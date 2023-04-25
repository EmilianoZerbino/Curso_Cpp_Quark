#include <windows.h>
#include "Presenter.h"

using namespace std;


int main()
{
    Presenter presenter = Presenter();
    presenter.PrecargarDatos();
    presenter.excute();

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 0);
    return 0;
}