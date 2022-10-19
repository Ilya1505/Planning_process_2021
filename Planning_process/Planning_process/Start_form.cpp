#include "Start_form.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Planning_process::Start_form form;
	Application::Run(%form);
}
