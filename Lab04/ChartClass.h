#ifndef __ChartClass__
#define __ChartClass__

#include <memory>
#include "ConfigClass.h"

//#include "vecmat.h"
class Matrix;

class ChartClass
{
    private:
        std::shared_ptr<ConfigClass> cfg;
        int x_step;         // liczba odcinkow z jakich bedzie sie skladal wykres
        double x_min,x_max; // zakres zmiennej x
        double y_min,y_max; // zakres wartosci przyjmowanych przez funkcje
        double GetFunctionValue(double x); // zwraca wartosci rysowanej funkcji
       
    public:
        ChartClass(std::shared_ptr<ConfigClass> c);
        void Set_Range();   // ustala wartosci zmiennych x_min,y_min,x_max,y_max
        double Get_Y_min(); // zwraca y_min
        double Get_Y_max(); // zwraca y_max
        void Draw(wxDC *dc, int width, int height);  // rysuje wykres

		//----------------------------------------------------------------------
		//funkcje
		void line2d(Matrix t, int h, double x1, double y1, double x2, double y2, wxDC * dc); //do ustawienia i rysowania parametrów odcinka <-update
		//void line2dDraw(wxDC *dc, Vector vectorU, Vector vectorV); //rysuje na ekran odcinek
		Matrix performTranslation(); // dokonuje translacji na punktach
		//Matrix GetCurrentInfo();  // zmiana planow
		Matrix performRotatation(); //do rotowania wykresem w zakresie 360 stopni
		void drawRotatedText(wxDC *dc, double xPosition, double yPosition, Matrix mat, wxString str); // do rysowania zmian w rotacji
		Matrix windowChanges();  //do operowania zmianami na ekranie
		// Matrix SetScaleToWindow(wxDC *dc, Matrix t, double *x1, double *y1, double *x2, double *y2); //rozbite

		//zmienne
		int height; //do rysowania, wysokosc  
		int width;  //szerokosc pikseli				
};

#endif
