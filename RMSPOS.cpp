#include "pch.h"
#include "Main.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void
main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    RMSPOS::Main form;
    Application::Run(% form);
}