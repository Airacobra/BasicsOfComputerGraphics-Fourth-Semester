#include <wx/wxprec.h>     //na przyszlosc nadawac w FracemBuilder unikalne nazwy :F
#include <wx/colordlg.h>   //do obslugi okienka kolorow
#include "FrameCreator.h" 

class MyApp : public wxApp   //tworzyme aplikacje, nie tykac tego
{
public:
	virtual bool OnInit();
};

//----------------------------------------------------------------------------------------------------
//sekcja tworzenia klasy dzieidziczacej z Myframe, deklaracje zmiennych, obiektow i funkcji
class MyWorkingFrame : public MyFrame  //MyFrame zostalo utworzone w wxForm, wiec tu tworze klase dziedziczaca po niej, TODO: nadpisac wirtualne metody
{
public:
	//funkcje dopisane
	MyWorkingFrame(wxWindow* parent);  // konstruktor, wykorzystuje konstruktor klasy bazowej
	void PaintStuffAndThingsOnScreen();  // na panel wyrysuj malpke i gwiazde, slonce, lub ksiezyc w zaleznosci od flagi
	
	//przeladowania
	void OnUpdateUI(wxUpdateUIEvent& event); //dzieki tej funckji to co narysowane pokaze sie na ekranie
	void Choice(wxCommandEvent& event); //zapisuje do flagi wybor ksiezyca, slonca, lub gwiazdy
	void Check(wxCommandEvent& event);  //jesli wduszono checkboxa dla banana, to odblokuj scrolla i pasek pod nim, zmien rysunek
	void SaveToFile(wxCommandEvent& event);  //zapisywanie do pliku w dowolnym miejscu
	void Scroll(wxScrollEvent& event);   //ruszanie paskiem, zmienia "wartosc" nizszego pasa za³adowania, oraz pozycje reki i banana
	void ChooseColour(wxCommandEvent& event); //pozwala uzytkownikowi na wybor koloru
	void EnterText(wxCommandEvent& event); //wpisywanie dwoch tekstow na ekran, odswiezanie

	//zmienne
	bool ifBanana; //czy malpa ma byc smutna czy nie
	int flag; //flaga przy opjcach rysowania na ekran
	int xPosition, yPosition; //do przechwytywania ruchu
	int angle; //do ruchu reka z bananem

	//dodatkowe obiekty do pracy z funkcjami
	wxClientDC *MyDC;  //mozna dodawac rysunki na panel
	wxImage Image;  //do pracowania z obrazem
	wxBitmap Bitmap; //do pracy z obrazem    
	wxBitmap *SaveCurrentBitMap; //do pracy z zapisywaniem obrazu 
	wxColourData *dataColour;      //ponizsze trzy obiekty
	wxColourDialog *dialogColour;  //sa do prace z funkcja
	wxColour choosenStarColour;    //choose colour
};

//----------------------------------------------------------------------------------------------------
wxIMPLEMENT_APP(MyApp);  

bool MyApp::OnInit()
{
	MyWorkingFrame *frame = new MyWorkingFrame(NULL);         //inicjalizacja, wywolanie konstruktora, wstepne rysowanie, cos czego juz nie trzeba zmieniac
	frame->PaintStuffAndThingsOnScreen();
	frame->Show(true);
	return true;
}
//----------------------------------------------------------------------------------------------------
//sekcja definicji metod klasy MyWorking Frame

MyWorkingFrame::MyWorkingFrame(wxWindow* parent) : MyFrame(parent) //przesy³amy tworzenie "okna" do klasy bazowej utworzonej w wxForm
{
	SetTitle("Lab3 - Sad Monkey");		//inicjalizacja, tak jak na wyk³adzie
	SetIcon(wxNullIcon);
	SetSize(8, 8, 600, 450);
	Center();

	wybor->Append("star");    //dodajemy trzy opcje
	wybor->Append("sun");
	wybor->Append("moon");
	wybor->SetSelection(0);      //domyslny wybor - gwiazda
	scroll->SetScrollbar(0, 15, 100, 10); //parametry suwaka
	scroll->Enable(false);      //suwak zablokowany do momentu akcji wduszenia przycisku ale to juz nie tu
	Image.AddHandler(new wxPNGHandler); //beda mozliwe operacje na banan.png
	MyDC = new wxClientDC(m_panel1);

	ifBanana = false;				//domyslnie malpa jest smutna :(
	flag = 0;				    //flaga rysowania, przyda sie na zapas
	xPosition = 0;
	yPosition = 0;
	angle = 0;
}

void MyWorkingFrame::PaintStuffAndThingsOnScreen()   //m_panel1->Refresh();
{
	//rysowanie malpki, bez animacji
	wxClientDC MyDC(m_panel1);  //mozna dodawac rysunki na panel
	MyDC.SetPen(wxPen(*wxBLACK, 3));  //ustawiamy pioro
	MyDC.Clear();               //czyscimy na start to co bylo

	MyDC.DrawCircle(200, 100, 40);      //glowa
	MyDC.DrawCircle(180, 95, 8);
	MyDC.DrawCircle(220, 95, 8);

	MyDC.DrawLine(200, 140, 200, 250);   //reszta ciala, ale bez mobilnej reki i usmiechu
	MyDC.DrawLine(200, 160, 250, 250);
	//MyDC.DrawLine(200, 160, 150, 250); 
	MyDC.DrawLine(200, 250, 260, 360);
	MyDC.DrawLine(200, 250, 140, 360);


	//gwiazda, slonce, ksiezyc
	switch (flag)
	{
	case 0:
	{ //konieczne, inaczej blad w case
		//MyDC.SetPen(wxPen(*wxBLACK, 2));		
		//MyDC.SetBrush(wxBrush(*wxBLACK, wxSOLID));
		MyDC.SetPen(wxPen(choosenStarColour, 2));   //rysowanie gwiazd
		MyDC.SetBrush(wxBrush(choosenStarColour, wxSOLID));
		
		//wxPoint simplePoints[3];
		wxPoint simplePoints2[5];
		wxPoint simplePoints[10];

		simplePoints[0] = wxPoint(20, 40);    // 10 punktow, laczy pierwsze z ostatnim
		simplePoints[1] = wxPoint(34, 40);
		simplePoints[2] = wxPoint(40, 20);
		simplePoints[3] = wxPoint(46, 40);
		simplePoints[4] = wxPoint(60, 40);
		simplePoints[5] = wxPoint(48, 48);
		simplePoints[6] = wxPoint(55, 70);
		simplePoints[7] = wxPoint(40, 57);
		simplePoints[8] = wxPoint(25, 70);
		simplePoints[9] = wxPoint(32, 48);
		MyDC.DrawPolygon(10, simplePoints);

		break;	
	}
	case 1:
	{
		MyDC.SetPen(wxPen(*wxYELLOW, 2));			 //rysowanie slonca
		MyDC.SetBrush(wxBrush(*wxYELLOW, wxSOLID));
		MyDC.DrawCircle(80, 80, 30);

		MyDC.DrawLine(80, 40, 80, 25);   //kreski do slonca
		MyDC.DrawLine(120, 80, 135, 80);
		MyDC.DrawLine(80, 120, 80, 135);
		MyDC.DrawLine(40, 80, 25, 80);

		MyDC.DrawLine(115, 115, 122, 122);
		MyDC.DrawLine(45, 45, 37, 37);
		MyDC.DrawLine(115, 45, 122, 37);
		MyDC.DrawLine(45, 115, 37, 122);

		break;
	}
	case 2:
	{
		MyDC.SetPen(wxPen(*wxBLACK, 2));			//rysowanie ksiezyca
		MyDC.SetBrush(wxBrush(*wxLIGHT_GREY, wxSOLID));
		MyDC.DrawCircle(60, 60, 40);

		MyDC.SetPen(wxPen(*wxWHITE, 2));            //biale kolko, przeslania szare
		MyDC.SetBrush(wxBrush (*wxWHITE, wxSOLID));
		MyDC.DrawCircle(40, 40, 40);
		break;
	}
	default:
		break;
	}


	//tekst
	MyDC.SetTextBackground(wxTRANSPARENT);
	MyDC.SetPen(wxPen(*wxBLACK, 3));
	MyDC.SetBrush(wxBrush(*wxBLACK, wxTRANSPARENT));

	MyDC.SetFont(wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_LIGHT, false, "Arial"));
	MyDC.DrawText(tekst->GetValue(), 230, 530);

	MyDC.SetFont(wxFont(40, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL, false, "Comic Sans"));
	MyDC.DrawRotatedText(tekst->GetValue(), 410, 470, 90);


	//banan i reka
	MyDC.SetPen(wxPen(*wxBLACK, 3));
	MyDC.DrawLine(200, 160, 150 - 0.5 * angle, 250 - angle);

	if (ifBanana)
	{
		MyDC.DrawEllipticArc(185, 115, 30, 15, -180, 0);
		if (Bitmap.Ok())
			MyDC.DrawBitmap(Bitmap, 130 - 0.5 * angle, 220 - angle);
	}
	else
		MyDC.DrawEllipticArc(185, 115, 30, 15, 0, 180);
}

void MyWorkingFrame::OnUpdateUI(wxUpdateUIEvent& event)     //rysujemy wszystko na panel (tyle ile jest podyktowane flaga)
{
	PaintStuffAndThingsOnScreen();
}

void MyWorkingFrame::Choice(wxCommandEvent& event)   // zmien flage wyboru gwiazdy, slonca, lub ksiezyca
{
	flag = wybor->GetSelection();
}

void MyWorkingFrame::Check(wxCommandEvent& event)  //czy ramka jest zaznaczona
{
	if (!(banan->IsChecked()))      //jak nie to dajemy na false
	{
		ifBanana = false;
		scroll->Enable(false);	
	}
	else
	{
		ifBanana = true;   //jak tak to uwalniamy scrolla i wczytujemy obraz
		scroll->Enable(true);

		Image.LoadFile("banan.png", wxBITMAP_TYPE_PNG);
		Image.Rescale(30, 35);
		Bitmap = wxBitmap(Image);
	}
}


void MyWorkingFrame::Scroll(wxScrollEvent& event)
{
	angle = scroll->GetThumbPosition();     //zczytuejmy pozycje scrolla, jako kat [0,100]
	pasek->SetValue(1.2 * angle);			//sposob ustawienia paska dla wxGauge
	PaintStuffAndThingsOnScreen();		    //zmienia sie kat, zmienia sie ruch reka
}

void MyWorkingFrame::SaveToFile(wxCommandEvent& event) //zapisuje do pliku, potrzebny dialog i DC
{
	wxFileDialog *FileDialog = new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("*.bmp"), wxFD_SAVE);
	
	if (FileDialog->ShowModal() == wxID_OK)
	{
		int width, high;
		wxMemoryDC memory;
	
		m_panel1->GetClientSize(&width, &high);
		SaveCurrentBitMap = new wxBitmap(width, high);

		memory.SelectObject(*SaveCurrentBitMap);
		memory.Blit(0, 0, width, high, MyDC, 0, 0, wxCOPY, true);

		wxString PlaceName = FileDialog->GetPath();
		wxImage saveimage = SaveCurrentBitMap->ConvertToImage();

		saveimage.SaveFile(PlaceName, wxBITMAP_TYPE_BMP);
	}
}

void MyWorkingFrame::ChooseColour(wxCommandEvent& event)  //pozwala wybrac kolor, 
{
	dataColour = new wxColourData;             
	dialogColour = new wxColourDialog(this);    //modal, modeless
	if (dialogColour->ShowModal() == wxID_OK)   //modal - dopoki jest otwarte okno nic z nim nie mozna robic 
	{
		*dataColour = dialogColour->GetColourData(); //pobieramy kolor
		choosenStarColour = dataColour->GetColour(); //zapisujemy kolor do obiektu
	} 
}

void MyWorkingFrame::EnterText(wxCommandEvent& event)
{
	// w sumie to mozna o to zadbac podczas rysowania
}