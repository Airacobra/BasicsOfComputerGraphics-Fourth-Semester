#include "MyClass.h"
//--------------------------------------------------------------------------

MyClass::MyClass(wxWindow *parent) : wxMyFrame(parent)
{
	SetTitle("Photo-Patchwork");
	wxImage::AddHandler(new wxJPEGHandler);
	wxImage::AddHandler(new wxPNGHandler);

	wxSize panelSize = m_panelRight->GetClientSize();
	EmptyBitmap.Create(panelSize.GetX(), panelSize.GetY());
	EmptyDC.SelectObject(EmptyBitmap);
	EmptyDC.SetBackground(*wxWHITE_BRUSH);
	EmptyDC.Clear();

	WxOpenFileDialog = new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("*.*"), wxFD_OPEN);
    WxOpenFileDialog->SetWildcard("PNG File (*.png)|*.png");
	MyDC1 = new wxClientDC(m_panel1);
	MyDC2 = new wxClientDC(m_panel2);
	MyDC3 = new wxClientDC(m_panel3);
	MyDC4 = new wxClientDC(m_panel4);
	MyDC5 = new wxClientDC(m_panel5);
	MyDCRight = new wxClientDC(m_panelRight);

	m_panelRight->Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(MyClass::OnRightPanelLeftClick), NULL, this);
	m_panelRight->Connect(wxEVT_RIGHT_DCLICK, wxMouseEventHandler(MyClass::OnRightPanelRightClick), NULL, this);

	allowEventPanel1 = false; 
	allowEventPanel2 = false; 
	allowEventPanel3 = false; 
	allowEventPanel4 = false; 
	allowEventPanel5 = false;
	ifShowImageToWorkOn = false;
	ifBackground = false;
	showResult = false;
	showPolygon = false;
	showLines = false;
	c = 0;
}

//--------------------------------------------------------------------------

void MyClass::Button_1(wxCommandEvent& event)
{
	if (WxOpenFileDialog->ShowModal() == wxID_OK)
	{
		MyDC1->Clear();
		filename1 = WxOpenFileDialog->GetPath();
		MyImage1.LoadFile(filename1, wxBITMAP_TYPE_PNG);
		size1 = MyImage1.GetSize();
		wxSize panelSize = m_panel1->GetClientSize();
		MyImage1.Rescale(panelSize.GetX(), panelSize.GetY());
		MyBitmap1 = wxBitmap(MyImage1);

		if (!ifBackground) 
		{
			ifBackground = true;
			MyImageResult.LoadFile(filename1, wxBITMAP_TYPE_PNG);
			wxSize panelSize = m_panelRight->GetClientSize();
			MyImageResult.Rescale(panelSize.GetX(), panelSize.GetY());
			MyBitmapResult = wxBitmap(MyImageResult);

		}
	}

	if (!allowEventPanel1)
	{
		allowEventPanel1 = true;
		m_panel1->Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(MyClass::OnLeftPanel1Click), NULL, this);
	}
}

void MyClass::Button_2(wxCommandEvent& event)
{
	if (WxOpenFileDialog->ShowModal() == wxID_OK)
	{
		MyDC2->Clear();
		filename2 = WxOpenFileDialog->GetPath();
		MyImage2.LoadFile(filename2, wxBITMAP_TYPE_PNG);
		size2 = MyImage2.GetSize();
		wxSize panelSize = m_panel2->GetClientSize();
		MyImage2.Rescale(panelSize.GetX(), panelSize.GetY());
		MyBitmap2 = wxBitmap(MyImage2);

		if (!ifBackground)
		{
			ifBackground = true;
			MyImageResult.LoadFile(filename2, wxBITMAP_TYPE_PNG);
			wxSize panelSize = m_panelRight->GetClientSize();
			MyImageResult.Rescale(panelSize.GetX(), panelSize.GetY());
			MyBitmapResult = wxBitmap(MyImageResult);
		}
	}

	if (!allowEventPanel2)
	{
		allowEventPanel2 = true;
		m_panel2->Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(MyClass::OnLeftPanel2Click), NULL, this);
	}
}

void MyClass::Button_3(wxCommandEvent& event)
{
	if (WxOpenFileDialog->ShowModal() == wxID_OK)
	{


		MyDC3->Clear();
		filename3 = WxOpenFileDialog->GetPath();
		MyImage3.LoadFile(filename3, wxBITMAP_TYPE_PNG);
		size3 = MyImage3.GetSize();
		wxSize panelSize = m_panel3->GetClientSize();
		MyImage3.Rescale(panelSize.GetX(), panelSize.GetY());
		MyBitmap3 = wxBitmap(MyImage3);

		if (!ifBackground)
		{
			ifBackground = true;
			MyImageResult.LoadFile(filename3, wxBITMAP_TYPE_PNG);
			wxSize panelSize = m_panelRight->GetClientSize();
			MyImageResult.Rescale(panelSize.GetX(), panelSize.GetY());
			MyBitmapResult = wxBitmap(MyImageResult);
		}
	}

	if (!allowEventPanel3)
	{
		allowEventPanel3 = true;
		m_panel3->Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(MyClass::OnLeftPanel3Click), NULL, this);
	}
}

void MyClass::Button_4(wxCommandEvent& event)
{
	if (WxOpenFileDialog->ShowModal() == wxID_OK)
	{
		MyDC4->Clear();
		filename4 = WxOpenFileDialog->GetPath();
		MyImage4.LoadFile(filename4, wxBITMAP_TYPE_PNG);
		size4 = MyImage4.GetSize();
		wxSize panelSize = m_panel4->GetClientSize();
		MyImage4.Rescale(panelSize.GetX(), panelSize.GetY());
		MyBitmap4 = wxBitmap(MyImage4);

		if (!ifBackground)
		{
			ifBackground = true;
			MyImageResult.LoadFile(filename4, wxBITMAP_TYPE_PNG);
			wxSize panelSize = m_panelRight->GetClientSize();
			MyImageResult.Rescale(panelSize.GetX(), panelSize.GetY());
			MyBitmapResult = wxBitmap(MyImageResult);
		}
	}

	if (!allowEventPanel4)
	{
		allowEventPanel4 = true;
		m_panel4->Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(MyClass::OnLeftPanel4Click), NULL, this);
	}
}

void MyClass::Button_5(wxCommandEvent& event)
{
	if (WxOpenFileDialog->ShowModal() == wxID_OK)
	{
		MyDC5->Clear();
		filename5 = WxOpenFileDialog->GetPath();
		MyImage5.LoadFile(filename5, wxBITMAP_TYPE_PNG);
		size5 = MyImage5.GetSize();
		wxSize panelSize = m_panel5->GetClientSize();
		MyImage5.Rescale(panelSize.GetX(), panelSize.GetY());
		MyBitmap5 = wxBitmap(MyImage5);

		if (!ifBackground)
		{
			ifBackground = true;
			MyImageResult.LoadFile(filename5, wxBITMAP_TYPE_PNG);
			wxSize panelSize = m_panelRight->GetClientSize();
			MyImageResult.Rescale(panelSize.GetX(), panelSize.GetY());
			MyBitmapResult = wxBitmap(MyImageResult);
		}
	}

	if (!allowEventPanel5)
	{
		allowEventPanel5 = true;
		m_panel5->Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(MyClass::OnLeftPanel5Click), NULL, this);
	}
}

void MyClass::pro100(wxCommandEvent& event)
{
	MyDCRight->Clear();
	wxSize panelSize = m_panelRight->GetClientSize();
	MyImageToWorkOn.Rescale(size.GetX(), size.GetY());
	MyBitmapToWorkOn = wxBitmap(MyImageToWorkOn);
	ifShowImageToWorkOn = true;
}

void MyClass::window_size(wxCommandEvent& event)
{
	MyDCRight->Clear();
	wxSize panelSize = m_panelRight->GetClientSize();
	MyImageToWorkOn.Rescale(panelSize.GetX(), panelSize.GetY());
	MyBitmapToWorkOn = wxBitmap(MyImageToWorkOn);
	ifShowImageToWorkOn = true;
}

void MyClass::width_size(wxCommandEvent& event)
{
	MyDCRight->Clear();
	wxSize panelSize = m_panelRight->GetClientSize();
	MyImageToWorkOn.Rescale(panelSize.GetX(),size.GetY());
	MyBitmapToWorkOn = wxBitmap(MyImageToWorkOn);
	ifShowImageToWorkOn = true;
}

void MyClass::height_size(wxCommandEvent& event)
{
	MyDCRight->Clear();
	wxSize panelSize = m_panelRight->GetClientSize();
	MyImageToWorkOn.Rescale(size.GetX(), panelSize.GetY());
	MyBitmapToWorkOn = wxBitmap(MyImageToWorkOn);
	ifShowImageToWorkOn = true;
}

void MyClass::Button_Result(wxCommandEvent& event)
{
	MyDCRight->Clear();
	showResult = true;
}

void MyClass::Button_Save(wxCommandEvent& event)
{
	wxFileDialog *FileDialog = new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("*.bmp"), wxFD_SAVE);

	if (FileDialog->ShowModal() == wxID_OK)
	{
		int width, high;
		wxMemoryDC memory;

		m_panelRight->GetClientSize(&width, &high);
		SaveCurrentBitMap = new wxBitmap(width, high);

		memory.SelectObject(*SaveCurrentBitMap);
		memory.Blit(0, 0, width, high, MyDCRight, 0, 0, wxCOPY, true);

		wxString PlaceName = FileDialog->GetPath();
		wxImage saveimage = SaveCurrentBitMap->ConvertToImage();

		saveimage.SaveFile(PlaceName, wxBITMAP_TYPE_BMP);
	}
}

void MyClass::OnLeftPanel1Click(wxMouseEvent & event)
{
	MyDCRight->Clear();
	MyImageToWorkOn.LoadFile(filename1, wxBITMAP_TYPE_PNG);
	size = size1;
	wxSize panelSize = m_panelRight->GetClientSize();
	MyImageToWorkOn.Rescale(panelSize.GetX(), panelSize.GetY());
	MyBitmapToWorkOn = wxBitmap(MyImageToWorkOn);
	ifShowImageToWorkOn = true;

	c = 0;
	
	for (int i = 0; i < 100; i++)
	{
		temp_points[i].x = 0;
		temp_points[i].y = 0;
	}
}

void MyClass::OnLeftPanel2Click(wxMouseEvent & event)
{
	MyDCRight->Clear();
	MyImageToWorkOn.LoadFile(filename2, wxBITMAP_TYPE_PNG);
	size = size2;
	wxSize panelSize = m_panelRight->GetClientSize();
	MyImageToWorkOn.Rescale(panelSize.GetX(), panelSize.GetY());
	MyBitmapToWorkOn = wxBitmap(MyImageToWorkOn);
	ifShowImageToWorkOn = true;	

	c = 0;
	
	for (int i = 0; i < 100; i++)
	{
		temp_points[i].x = 0;
		temp_points[i].y = 0;
	}
}

void MyClass::OnLeftPanel3Click(wxMouseEvent & event)
{
	MyDCRight->Clear();
	MyImageToWorkOn.LoadFile(filename3, wxBITMAP_TYPE_PNG);
	size = size3;
	wxSize panelSize = m_panelRight->GetClientSize();
	MyImageToWorkOn.Rescale(panelSize.GetX(), panelSize.GetY());
	MyBitmapToWorkOn = wxBitmap(MyImageToWorkOn);
	ifShowImageToWorkOn = true;

	c = 0;
	
	for (int i = 0; i < 100; i++)
	{
		temp_points[i].x = 0;
		temp_points[i].y = 0;
	}
}

void MyClass::OnLeftPanel4Click(wxMouseEvent & event)
{
	MyDCRight->Clear();
	MyImageToWorkOn.LoadFile(filename4, wxBITMAP_TYPE_PNG);
	size = size4;
	wxSize panelSize = m_panelRight->GetClientSize();
	MyImageToWorkOn.Rescale(panelSize.GetX(), panelSize.GetY());
	MyBitmapToWorkOn = wxBitmap(MyImageToWorkOn);
	ifShowImageToWorkOn = true;

	c = 0;
	
	for (int i = 0; i < 100; i++)
	{
		temp_points[i].x = 0;
		temp_points[i].y = 0;
	}
}

void MyClass::OnLeftPanel5Click(wxMouseEvent & event)
{
	MyDCRight->Clear();
	MyImageToWorkOn.LoadFile(filename5, wxBITMAP_TYPE_PNG);
	size = size5;
	wxSize panelSize = m_panelRight->GetClientSize();
	MyImageToWorkOn.Rescale(panelSize.GetX(), panelSize.GetY());
	MyBitmapToWorkOn = wxBitmap(MyImageToWorkOn);
	ifShowImageToWorkOn = true;

	c = 0;
	
	for (int i = 0; i < 100; i++)
	{
		temp_points[i].x = 0;
		temp_points[i].y = 0;
	}
}

void MyClass::OnRightPanelLeftClick(wxMouseEvent & event)
{
	const wxPoint pos = wxGetMousePosition();
	int mouseX = pos.x - this->GetScreenPosition().x-307;
	int mouseY = pos.y - this->GetScreenPosition().y-37;
	temp_points[c] = wxPoint(mouseX,mouseY);
	c++;
	
	showLines = true;
}

void MyClass::OnRightPanelRightClick(wxMouseEvent & event)
{
	points = new wxPoint[c];
	for (int i = 0; i < c; i++)
	{
		points[i] = temp_points[i];
	}

	showPolygon = true;
	showLines = false;
	
}

//--------------------------------------------------------------------------

void MyClass::OnUpdate(wxUpdateUIEvent& event)
{
	wxClientDC MyDC1(m_panel1);      //przypisanie paneli 
	wxClientDC MyDC2(m_panel2);
	wxClientDC MyDC3(m_panel3);
	wxClientDC MyDC4(m_panel4);
	wxClientDC MyDC5(m_panel5);
	wxClientDC MyDCRight(m_panelRight);
	

	if (MyBitmap1.Ok())						//rysowanie na ekran 5 zaladowanych przez uzytkownika zdjec
		MyDC1.DrawBitmap(MyBitmap1, 0, 0);
	if (MyBitmap2.Ok())
		MyDC2.DrawBitmap(MyBitmap2, 0, 0);
	if (MyBitmap3.Ok())
		MyDC3.DrawBitmap(MyBitmap3, 0, 0);
	if (MyBitmap4.Ok())
		MyDC4.DrawBitmap(MyBitmap4, 0, 0);
	if (MyBitmap5.Ok())
		MyDC5.DrawBitmap(MyBitmap5, 0, 0);

	if(showResult)   //pokaz rezultat na prawym panelu
	{
		if (MyBitmapResult.Ok())
		{
			MyDCRight.DrawBitmap(MyBitmapResult, 0, 0);
			showResult = false;
		}
	}

	if(ifShowImageToWorkOn) //pokaz aktualny rezultat
	{
		if (MyBitmapToWorkOn.Ok())
		{
			MyDCRight.DrawBitmap(MyBitmapToWorkOn, 0, 0);
			ifShowImageToWorkOn = false;
		}
	}

	if(showLines) //pokaz linie laczace wybrane przez uzytkownika punkty
	{
		MyDCRight.SetPen(wxPen(*wxBLACK, 3));
		if (c == 1)
			MyDCRight.DrawPoint(temp_points[0]);
		else
		{
			for(int i = 0; i < c - 1; i++)
				MyDCRight.DrawLine(temp_points[i].x, temp_points[i].y, temp_points[i+1].x, temp_points[i+1].y);
		
		}
		showLines = false;
	}

	if (showPolygon) //na podstawie wieolokata zamien pixele
	{

		wxSize panelSize = MyImageToWorkOn.GetSize();
		wxImage test(panelSize.GetHeight(), panelSize.GetWidth());
		wxMemoryDC dc;
		wxBitmap bm(panelSize.GetX(), panelSize.GetY(), dc);
		dc.SelectObject(bm);
		dc.SetBrush(wxBrush(wxColour(255, 255, 255)));
		dc.DrawRectangle(0, 0, panelSize.GetX(),panelSize.GetY());
		dc.SetBrush(wxBrush(wxColour(255, 0, 0)));
		dc.DrawPolygon(c, temp_points);
		
		test = bm.ConvertToImage();


		for (int x = 0; x < panelSize.GetWidth(); x++)
		{
			for (int y = 0; y < panelSize.GetHeight(); y++)
			{
				if ((test.GetRed(x, y)>0)&& (test.GetGreen(x, y)==0)&&(test.GetBlue(x, y)==0))
				{
					const int r = MyImageToWorkOn.GetRed(x, y);
					const int g = MyImageToWorkOn.GetGreen(x, y);
					const int b = MyImageToWorkOn.GetBlue(x, y);
					MyImageResult.SetRGB(x, y, r, g, b);
				}

			}
		}
		MyBitmapResult = wxBitmap(MyImageResult);
		EmptyDC.Clear();
		showPolygon = false;
		showResult = true;
		c = 0;
	




	}
	
}
