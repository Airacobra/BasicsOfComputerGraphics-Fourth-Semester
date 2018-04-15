///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "FrameCreator.h"

///////////////////////////////////////////////////////////////////////////

MyFrame::MyFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel1->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );
	m_panel1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	
	bSizer1->Add( m_panel1, 1, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	zapisDoPliku = new wxButton( this, wxID_ANY, wxT("Save to file"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( zapisDoPliku, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	banan = new wxCheckBox( this, wxID_ANY, wxT("banana!"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( banan, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	scroll = new wxScrollBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSB_HORIZONTAL );
	scroll->SetMinSize( wxSize( 200,20 ) );
	
	bSizer2->Add( scroll, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	pasek = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	pasek->SetValue( 0 );
	bSizer2->Add(pasek, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	kolor = new wxButton( this, wxID_ANY, wxT("Star color"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( kolor, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	tekst = new wxTextCtrl( this, wxID_ANY, wxT("DefaultText"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( tekst, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	wxArrayString wyborChoices;
	wybor = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wyborChoices, 0 );
	wybor->SetSelection( 0 );
	bSizer2->Add( wybor, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_panel1->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame::OnUpdateUI ), NULL, this );
	zapisDoPliku->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::SaveToFile), NULL, this );
	banan->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame::Check ), NULL, this );
	scroll->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	kolor->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::ChooseColour), NULL, this );
	tekst->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyFrame::EnterText), NULL, this );
	wybor->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame::Choice ), NULL, this );
}

MyFrame::~MyFrame()
{
	// Disconnect Events
	m_panel1->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame::OnUpdateUI ), NULL, this );
	zapisDoPliku->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::SaveToFile), NULL, this );
	banan->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame::Check ), NULL, this );
	scroll->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	kolor->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::ChooseColour), NULL, this );
	tekst->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyFrame::EnterText), NULL, this );
	wybor->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame::Choice ), NULL, this );
	
}
