#include "MyForm.h"
#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace LABA4FORMA2;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MyForm);
    return 0;
}
