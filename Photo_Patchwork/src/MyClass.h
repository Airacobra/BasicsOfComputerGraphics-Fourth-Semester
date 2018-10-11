#pragma once
#include "FormBuilder.h"

class MyClass : public wxMyFrame
{
public:
	//funkcje
	MyClass(wxWindow *parent);
	
	void Button_1(wxCommandEvent& event);
	void Button_2(wxCommandEvent& event);
	void Button_3(wxCommandEvent& event);
	void Button_4(wxCommandEvent& event);
	void Button_5(wxCommandEvent& event);
	void Button_Result(wxCommandEvent& event);
	void Button_Save(wxCommandEvent& event);
	void OnUpdate(wxUpdateUIEvent& event);
	void OnLeftPanel1Click(wxMouseEvent & event);
	void OnLeftPanel2Click(wxMouseEvent & event);
	void OnLeftPanel3Click(wxMouseEvent & event);
	void OnLeftPanel4Click(wxMouseEvent & event);
	void OnLeftPanel5Click(wxMouseEvent & event);
	void OnRightPanelLeftClick(wxMouseEvent & event);
	void OnRightPanelRightClick(wxMouseEvent & event);
	void pro100(wxCommandEvent& event);
	void window_size(wxCommandEvent& event);
	void width_size(wxCommandEvent& event);
	void height_size(wxCommandEvent& event);

	//zmienne
	wxImage  MyImage1, MyImage2, MyImage3, MyImage4, MyImage5, MyImageResult, MyImageToWorkOn;
	wxBitmap MyBitmap1, MyBitmap2, MyBitmap3, MyBitmap4, MyBitmap5, *SaveCurrentBitMap, MyBitmapResult, MyBitmapToWorkOn, EmptyBitmap;
	wxClientDC *MyDC1, *MyDC2, *MyDC3, *MyDC4, *MyDC5, *MyDCRight;
	wxFileDialog *WxOpenFileDialog;
	wxString filename1, filename2, filename3, filename4, filename5;
	wxSize size1, size2, size3, size4, size5, size;
	wxPoint temp_points[100];
	wxPoint *points;
	wxMemoryDC EmptyDC;

	bool allowEventPanel1, allowEventPanel2, allowEventPanel3, allowEventPanel4, allowEventPanel5;
	bool ifBackground, ifShowImageToWorkOn, showResult, showPolygon, showLines;
	unsigned c;

};