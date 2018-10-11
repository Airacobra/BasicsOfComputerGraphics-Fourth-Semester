///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __FORMBUILDER_H__
#define __FORMBUILDER_H__


#include <wx/rawbmp.h>
#include <wx/wxprec.h>     
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/scrolbar.h>
#include <wx/gauge.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/filedlg.h>



///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class wxFrame
///////////////////////////////////////////////////////////////////////////////
class wxMyFrame : public wxFrame
{
private:

protected:
	wxButton * m_button1;
	wxPanel* m_panel1;
	wxButton* m_button2;
	wxPanel* m_panel2;
	wxButton* m_button3;
	wxPanel* m_panel3;
	wxButton* m_button4;
	wxPanel* m_panel4;
	wxButton* m_button5;
	wxPanel* m_panel5;
	wxButton* m_buttonResult;
	wxButton* m_buttonSave;
	wxRadioButton* full_size;
	wxRadioButton* to_window;
	wxRadioButton* to_width;
	wxRadioButton* to_height;
	wxPanel* m_panelRight;

	// Virtual event handlers, overide them in your derived class
	virtual void Button_1(wxCommandEvent& event) { event.Skip(); }
	virtual void Button_2(wxCommandEvent& event) { event.Skip(); }
	virtual void Button_3(wxCommandEvent& event) { event.Skip(); }
	virtual void Button_4(wxCommandEvent& event) { event.Skip(); }
	virtual void Button_5(wxCommandEvent& event) { event.Skip(); }
	virtual void Button_Result(wxCommandEvent& event) { event.Skip(); }
	virtual void Button_Save(wxCommandEvent& event) { event.Skip(); }
	virtual void pro100(wxCommandEvent& event) { event.Skip(); }
	virtual void window_size(wxCommandEvent& event) { event.Skip(); }
	virtual void width_size(wxCommandEvent& event) { event.Skip(); }
	virtual void height_size(wxCommandEvent& event) { event.Skip(); }
	virtual void OnUpdate(wxUpdateUIEvent& event) { event.Skip(); }


public:

	wxMyFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1120, 577), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~wxMyFrame();

};

#endif //__FORMBUILDER_H__

