///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "FormBuilder.h"

///////////////////////////////////////////////////////////////////////////

wxMyFrame::wxMyFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 91, false, wxEmptyString));
	this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));

	wxBoxSizer* bSizerAll;
	bSizerAll = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizerLeft;
	bSizerLeft = new wxBoxSizer(wxVERTICAL);

	bSizerLeft->SetMinSize(wxSize(300, -1));
	wxGridSizer* gSizerImages;
	gSizerImages = new wxGridSizer(0, 2, 0, 0);

	m_button1 = new wxButton(this, wxID_ANY, wxT("Load Image 1"), wxDefaultPosition, wxDefaultSize, 0);
	gSizerImages->Add(m_button1, 0, wxALL, 5);

	m_panel1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel1->SetBackgroundColour(wxColour(255, 255, 255));
	m_panel1->SetMinSize(wxSize(20, 50));

	gSizerImages->Add(m_panel1, 1, wxEXPAND | wxALL, 5);

	m_button2 = new wxButton(this, wxID_ANY, wxT("Load Image 2"), wxDefaultPosition, wxDefaultSize, 0);
	gSizerImages->Add(m_button2, 0, wxALL, 5);

	m_panel2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHTTEXT));

	gSizerImages->Add(m_panel2, 1, wxEXPAND | wxALL, 5);

	m_button3 = new wxButton(this, wxID_ANY, wxT("Load Image 3"), wxDefaultPosition, wxDefaultSize, 0);
	gSizerImages->Add(m_button3, 0, wxALL, 5);

	m_panel3 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));

	gSizerImages->Add(m_panel3, 1, wxEXPAND | wxALL, 5);

	m_button4 = new wxButton(this, wxID_ANY, wxT("Load Image 4"), wxDefaultPosition, wxDefaultSize, 0);
	gSizerImages->Add(m_button4, 0, wxALL, 5);

	m_panel4 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel4->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));

	gSizerImages->Add(m_panel4, 1, wxEXPAND | wxALL, 5);

	m_button5 = new wxButton(this, wxID_ANY, wxT("Load Image 5"), wxDefaultPosition, wxDefaultSize, 0);
	gSizerImages->Add(m_button5, 0, wxALL, 5);

	m_panel5 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel5->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));

	gSizerImages->Add(m_panel5, 1, wxEXPAND | wxALL, 5);


	bSizerLeft->Add(gSizerImages, 1, wxEXPAND, 5);

	wxGridSizer* gSizerResultAndSave;
	gSizerResultAndSave = new wxGridSizer(0, 2, 0, 0);

	m_buttonResult = new wxButton(this, wxID_ANY, wxT("Show Result"), wxDefaultPosition, wxDefaultSize, 0);
	gSizerResultAndSave->Add(m_buttonResult, 0, wxALL, 5);

	m_buttonSave = new wxButton(this, wxID_ANY, wxT("Save Image"), wxDefaultPosition, wxDefaultSize, 0);
	gSizerResultAndSave->Add(m_buttonSave, 0, wxALL, 5);


	bSizerLeft->Add(gSizerResultAndSave, 1, wxEXPAND, 5);

	wxGridSizer* gSizer3;
	gSizer3 = new wxGridSizer(0, 2, 0, 0);

	full_size = new wxRadioButton(this, wxID_ANY, wxT("100%"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer3->Add(full_size, 0, wxALL, 5);

	to_window = new wxRadioButton(this, wxID_ANY, wxT("adjust to window"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer3->Add(to_window, 0, wxALL, 5);

	to_width = new wxRadioButton(this, wxID_ANY, wxT("adjust to width"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer3->Add(to_width, 0, wxALL, 5);

	to_height = new wxRadioButton(this, wxID_ANY, wxT("adjust to height"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer3->Add(to_height, 0, wxALL, 5);


	bSizerLeft->Add(gSizer3, 1, wxEXPAND, 5);


	bSizerAll->Add(bSizerLeft, 0, 0, 5);

	m_panelRight = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxTAB_TRAVERSAL);
	m_panelRight->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVEBORDER));

	bSizerAll->Add(m_panelRight, 1, wxEXPAND | wxALL, 0);


	this->SetSizer(bSizerAll);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	m_button1->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxMyFrame::Button_1), NULL, this);
	m_button2->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxMyFrame::Button_2), NULL, this);
	m_button3->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxMyFrame::Button_3), NULL, this);
	m_button4->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxMyFrame::Button_4), NULL, this);
	m_button5->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxMyFrame::Button_5), NULL, this);
	m_buttonResult->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxMyFrame::Button_Result), NULL, this);
	m_buttonSave->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxMyFrame::Button_Save), NULL, this);
	full_size->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(wxMyFrame::pro100), NULL, this);
	to_window->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(wxMyFrame::window_size), NULL, this);
	to_width->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(wxMyFrame::width_size), NULL, this);
	to_height->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(wxMyFrame::height_size), NULL, this);
	m_panelRight->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(wxMyFrame::OnUpdate), NULL, this);
}

wxMyFrame::~wxMyFrame()
{
	// Disconnect Events
	m_button1->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxMyFrame::Button_1), NULL, this);
	m_button2->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxMyFrame::Button_2), NULL, this);
	m_button3->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxMyFrame::Button_3), NULL, this);
	m_button4->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxMyFrame::Button_4), NULL, this);
	m_button5->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxMyFrame::Button_5), NULL, this);
	m_buttonResult->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxMyFrame::Button_Result), NULL, this);
	m_buttonSave->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxMyFrame::Button_Save), NULL, this);
	full_size->Disconnect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(wxMyFrame::pro100), NULL, this);
	to_window->Disconnect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(wxMyFrame::window_size), NULL, this);
	to_width->Disconnect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(wxMyFrame::width_size), NULL, this);
	to_height->Disconnect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(wxMyFrame::height_size), NULL, this);
	m_panelRight->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(wxMyFrame::OnUpdate), NULL, this);

}

