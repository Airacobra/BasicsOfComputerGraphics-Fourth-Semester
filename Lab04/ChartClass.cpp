#include <wx/dc.h>
#include <memory>
#include "ChartClass.h"
#include "vecmat.h"

ChartClass::ChartClass(std::shared_ptr<ConfigClass> c)
{
    cfg= std::move(c);
    x_step=200;
}

void ChartClass::Set_Range()
{
 double xmin=9999.9,xmax=-9999.9,ymin=9999.9,ymax=-9999.9;
 double x,y,step;
 int i;

 xmin=cfg->Get_x_start();
 xmax=cfg->Get_x_stop();

 step=(cfg->Get_x_stop()-cfg->Get_x_start())/(double)x_step;
 x=cfg->Get_x_start();

 for (i=0;i<=x_step;i++)
  {
   y=GetFunctionValue(x);
   if (y>ymax) ymax=y;
   if (y<ymin) ymin=y;
   x=x+step;
  }

 y_min=ymin;
 y_max=ymax;
 x_min=xmin;
 x_max=xmax;
}

double ChartClass::GetFunctionValue(double x)
{
 if (cfg->Get_F_type()==1) return x*x;
 if (cfg->Get_F_type()==2) return 0.5*exp(4*x-3*x*x);
 return x+sin(x*4.0);
}

//----------------------------------------
void ChartClass::Draw(wxDC *dc, int w, int h)
{
 Matrix matrix;
 Matrix temp_mat;
 Vector temp_vect;

 height = h;
 width = w;
 double i, di;

 dc->SetBackground(wxBrush(RGB(255, 255, 255)));
 dc->Clear();
 dc->SetPen(wxPen(RGB(255, 0, 0)));
 dc->DrawRectangle(10, 10, width - 20, height - 20);
 dc->SetClippingRegion(10, 10, width - 20, height - 20); //nie wyjdzie poza prostokat

 double xStartPosition = cfg->Get_x_start();   //pomocne dane, aby caly czas nie wracac do metod
 double xStopPosition = cfg->Get_x_stop();
 double yMaxPosition = Get_Y_max();
 double yMinPosition = Get_Y_min();

 //rotacja
 if(cfg->RotateScreenCenter())
 {
	 matrix =  windowChanges() * performRotatation() * performTranslation();
 }
 else
 {
	 matrix = windowChanges() * performTranslation() * performRotatation();
 }

 //osie x i y
 dc->SetPen(wxPen(RGB(0, 80, 150)));
 line2d(matrix, height, xStartPosition, 0, xStopPosition, 0 , dc);
 line2d(matrix, height, 0, yMinPosition, 0, yMaxPosition, dc);
 
 //przedzial x
 i = xStartPosition; 
 while(i <= xStopPosition)
 {
	 line2d(matrix, height, i, -0.1, i, 0.1, dc);
	 //temp_vect.Set(i = 0.1, 0);
	 //temp_mat = windowChanges()
	 drawRotatedText(dc, i - 0.1, -0.1, matrix, wxString::Format(wxT("%.2g"), i));
	 i +=  1;
 }

 //przedzial y
 i = yMinPosition;
 while (i <= yMaxPosition)
 {
	 line2d(matrix, height, -0.1, i, 0.1, i, dc);
	 drawRotatedText(dc, 0.1, i, matrix, wxString::Format(wxT("%.2g"), i));
	 i += 1;
 }

 //wykres
 dc->SetPen(wxPen(RGB(12, 230, 100)));
 di = (xStopPosition - xStartPosition) / x_step;
 i = xStartPosition;
 while(i <= xStopPosition)
 {
	 line2d(matrix, height, i, GetFunctionValue(i), i + di, GetFunctionValue(i + di), dc);
	 i += di;
 }
}

void ChartClass::line2d(Matrix mat, int h,  double x1, double y1, double x2, double y2, wxDC * dc)
{
	Vector vectorU;
	Vector vectorV;

	vectorU.Set(x1, y1);
	vectorV.Set(x2, y2);

	vectorU = mat * vectorU;    //macierz * wektor != wektor * macierz
	vectorV = mat * vectorV;

	double tempValueU = vectorU.GetY();   //d³ugie, bez sensu ale ze 
	double tempValueV = vectorV.GetY();	  //zwgledu na errory zostawiam

	double value1X = vectorU.GetX();
	double value1Y = h  - tempValueU;
	double value2X = vectorV.GetX();
	double value2Y = h - tempValueV;
	
	dc->DrawLine(value1X, value1Y, value2X, value2Y);  //na ekran rysujemy
}

/*void ChartClass::line2dDraw(wxDC *dc, Vector vectorU, Vector vectorV)
{
	double value1X = vectorU.GetX();
	double value1Y = height - vectorU.GetY;       //niepotrzebna fun() ^wrzucone wy¿ej
	double value2X = vectorV.GetX();
	double value2Y = height - vectorV.GetY;

	dc->DrawLine(vectorU.GetX(), value1Y, vectorV.GetX, value2Y);
}*/

Matrix ChartClass::performTranslation()
{
	Matrix mat;

	mat.data[0][0] = 1;    //operacja translacji w macierzy 2x2
	mat.data[1][0] = 0;
	mat.data[0][1] = 0; 
	mat.data[1][1] = 1;
	mat.data[0][2] = cfg->Get_dX(); 
	mat.data[1][2] = cfg->Get_dY();

	return mat;
}

Matrix ChartClass::performRotatation()
{
	Matrix mat;
	double alpha = cfg->Get_Alpha() * M_PI / 180;  //wyznacznie kata

	mat.data[0][0] = cos(alpha);  //rotacja wedlug wyznaczonego
	mat.data[0][1] = sin(alpha);  //kota alpha
	mat.data[1][0] = -sin(alpha);
	mat.data[1][1] = cos(alpha);

	return mat;
}

void ChartClass::drawRotatedText(wxDC *dc, double xPosition, double yPosition, Matrix mat, wxString str)
{
	Vector VectorU;
	VectorU.Set(xPosition, yPosition);     
	VectorU = mat * VectorU;

	double valueX = VectorU.GetX();            //wyznacznie wartosci i wypisanie na ekran
	double valueY = height - VectorU.GetY();   //zrotowanego tekstu
	double angle = -cfg->Get_Alpha();

	dc->DrawRotatedText(str, valueX, valueY, angle);
}

Matrix ChartClass::windowChanges()
{
	Matrix mat;

	double x0 = cfg->Get_x0();
	double y0 = cfg->Get_y0();
	double x1 = cfg->Get_x1();
	double y1 = cfg->Get_y1();

	double scaleParameterHeight = (height - 30.) / (y1 - y0);
	double scaleParameterWidth = (width - 30.) / (x1 - x0);
	
	mat.data[1][0] = 0;
	mat.data[0][1] = 0;
	mat.data[0][0] = (width - 30.) / (x1 - x0);
	mat.data[1][1] = (height - 30.) / (y1 - y0);
	mat.data[0][2] = 10. - x0 * (width - 30.) / (x1 - x0);
	mat.data[1][2] = 10. -  y0 * (height - 30.) / (y1 - y0);

	return mat;
}
//----------------------------------------

double ChartClass::Get_Y_min()
{
	Set_Range();
	return y_min;
}

double ChartClass::Get_Y_max()
{
	Set_Range();
	return y_max;
}