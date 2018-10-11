//--------------------------------------------------------------------------
#include <wx/wxprec.h>
#include "FormBuilder.h"
#include "MyClass.h"

class MyApp : public wxApp {

public:

	virtual bool OnInit();
	virtual int OnExit() { return 0; }

};
//--------------------------------------------------------------------------

IMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
	MyClass *mainFrame = new MyClass(NULL);
	mainFrame->Show(true);
	SetTopWindow(mainFrame);

	return true;
}