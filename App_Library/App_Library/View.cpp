#include "View.h"
#include <iostream>
#include <string>


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

View::View() {
    setConsole();
}

string View::showMainMenu()
{
    cleanConsole();
    setHeaderAndFooter("     MENU  PRINCIPAL","                    Ingrese s para salir.", 0, 8);
    cout << "  Seleccione una Opcion:\n\n";
    cout << "  1) Prestar Libro.\n";
    cout << "  2) Recibir Libro.\n\n";
    cout << "  3) Agregar Nuevo Socio.\n";
    cout << "  4) Agregar Nuevo Libro.\n";
    cout << "  5) Agregar Copia de un Libro.\n\n";
    cout << "  6) Historial de prestamos.\n";
    cout << "  7) Disponibilidad de Ejemplares.\n\n";
    cout << "     Ingrese s para salir.\n\n";
    cout << "     Opcion: ";
    
    cin >> option;
    checkIncorrectOption(5, 13, 17);
    return option;
}

void View::showBorrowMenu(string* pointerData, list<Member> members, list<Book> books)
{
    cleanConsole();
    string libro;
    setHeaderAndFooter("     MENU  DE PRESTAMOS","Ingrese s para regresar al Menu Pricipal.", 0, 8);
    cout << "  Ingrese el nombre del libro que desea retirar:\n";
    cout << "  Libro: ";
    getline(cin, option);
    checkIncorrectOption(0, 9, 10);
    setCursorPosition(0, 11);
    bool check1 = false;
    bool check2 = false;
    bool check3 = false;
    for (auto book = books.begin(); book != books.end(); ++book) {
        if (book->getName() == option) {
            check1 = true;
            if (book->getAvailability()) {
                check2 = true;
                pointerData[0] = book->getIsbnCode();
                libro = book->getIsbnCode();
            }
        }
    }
    if (check1) {
        if (!check2) {
            setErrorLetter();
            cout << "  En este momento no hay copias disponibles del titulo\n";
            cout << "  Reintentar en 5 dias habiles. ";
            setNormalLetter();
        }
        else {
            cout << "\n  Ingrese Codigo de Socio:\n";
            cout << "  Codigo: ";

            checkIncorrectOption(0, 9, 10);
            setCursorPosition(0, 11);
            check1 = true;
            for (auto member = members.begin();member != members.end();++member) {
                if (member->getIdentificationCode() == option) {
                    for (auto edition = member->getBorrowedEditions().begin();edition != member->getBorrowedEditions().end();++edition) {
                        if (edition->getIsbnCode() == libro) {
                            check1 = false;
                            cout << "\n\n\n\n  Ya posee una copia del libro, no puede retirar mas.\n";
                        }
                    }
                }
            }
            if (check1) {
                check2 = false;
                for (auto member = members.begin(); member != members.end(); ++member) {
                    if (member->getIdentificationCode() == option) {
                        if (member->getBorrowedEditions().size() < member->getMaxBorrowedEditions()) {
                            pointerData[1] = member->getIdentificationCode();
                            check3 = true;
                        }
                        else {
                            cout << "\n\n\n\n  El Socio se encuentra al limite de copias que puede retirar.\n";
                        }
                        check2 = true;
                    }
                }
                if (check3) {
                    cout << "\n\n\n\n\n  <<Copia prestada al socio>>.\n";
                }
                if (!check2) {
                    cout << "\n\n\n\n\n  No se encontro Socio con el codigo indicado.\n";
                }
            }
        }
    }
    else {
        setErrorLetter();
        cout << "  No Poseemos ese Titulo en la Biblioteca. ";
        setNormalLetter();
    }
    cout << "\n\n  Presione s para volver al menu principal\n  ";
    cin >> option;
    checkIncorrectOption(6, 2, 14);
}

void View::showDevolutionMenu(string* pointerData, list<Borrow>borrows)
{
    cleanConsole();
    setHeaderAndFooter("  MENU  DE DEVOLUCIONES","Ingrese s para regresar al Menu Pricipal.", 0, 8);
    
    cout << "  Ingrese el codigo de Socio:\n\n";
    cout << "  Codigo: ";
    getline(cin, option);
    checkIncorrectOption(0, 10, 10);
    pointerData[0] = option;
    option = "";
    setCursorPosition(0,12);
    cout << "\n  Ingrese el codigo ISBN del Libro:\n\n";
    cout << "  Codigo: ";
    checkIncorrectOption(0, 10, 15);
    pointerData[1] = option;
    bool check = false;
    for (auto borrow = borrows.begin(); borrow != borrows.end(); ++borrow) {
        if (borrow->getDevolution() == false) {
            if (borrow->getMember().getIdentificationCode() == pointerData[0]) {
                if (borrow->getEdition().getIsbnCode() == pointerData[1]) {
                    check = true;
                }
            }
        }
    }
    if (check) {
        cout << "\n\n  Devolucion procesada con exito!\n\n";
    }
    else {
        cout << "\n\n  Error: No se registra prestamo del titulo al Socio ingresado.\n\n";
    }
    cout << "\n  Presione s para volver al menu principal\n  ";
    cin >> option;
}

void View::showAddNewMemberMenu(string* pointer)
{
    cleanConsole();
    setHeaderAndFooter("  MENU  DE ALTA DE SOCIOS", "Ingrese s para regresar al Menu Pricipal.", 0, 8);
    cout << "  Ingrese Nombre: ";
    option = "";

    getline(cin, option);
    checkIncorrectOption(0, 18, 8);
    pointer[0] = option;
    option = "";
    cout << "\n\n  Ingrese Apellido: ";
    checkIncorrectOption(0, 20, 11);
    pointer[1] = option;
    option = "";
    cout << "\n\n  Ingrese Numero de Identificacion: ";

    checkIncorrectOption(0, 36, 14);
    pointer[2] = option;
    option = "";
    cout << "\n\n  Es miembro Vip:\n";
    cout << "     1) Si\n";
    cout << "     2) No\n          ";
    setCursorPosition(18, 17);
    cin >> option;
    checkIncorrectOption(2, 18, 17);
    pointer[3] = option;
    option = "";
    if (pointer[3] == "1") {
        cout << "\n\n\n  Ingrese Valor de la cuota mensual: $";
        bool check = true;
        float cost;
        while (check) {
            cin >> option;
            if (option != "s") {
                try {
                    cost = stof(option);
                    check = false;
                }
                catch (invalid_argument const& e) {
                    setCursorPosition(37, 21);
                    setErrorLetter();
                    cout << "                           ";
                    cout << "\n  Valor incorrecto, vuelva a intentarlo.                ";
                    setNormalLetter();
                    setCursorPosition(37, 21);
                }
            }
            else
            {
                cost = -1;
                check = false;
            }
        }
        pointer[4] = option;
    }
    else {
        cout << "\n";
    }
    cout << "\n\n  Socio agregado con exito!!!, Ingrese s para continuar \n  ";
    cin >> option;
    checkIncorrectOption(6, 2, 25);
    option = "";
}

void View::showAddNewBookMenu(string* pointer)
{
    cleanConsole();
    setHeaderAndFooter("  MENU  DE ALTA DE LIBROS", "Ingrese s para regresar al Menu Pricipal.", 0, 8);
    cout << "  Ingrese Nombre: ";
    option = "";

    getline(cin, option);
    checkIncorrectOption(0, 18, 8);
    pointer[0] = option;
    option = "";
    cout << "\n\n  Ingrese Codigo ISBN: ";
    checkIncorrectOption(0, 23, 11);
    pointer[1] = option;
    option = "";
    cout << "\n\n  Ingrese Autor: ";

    checkIncorrectOption(0, 17, 14);
    pointer[2] = option;
    cout << "\n\n  Libro agregado con exito!!!, Ingrese s para continuar \n  ";
    cin >> option;
    checkIncorrectOption(6, 2, 18);
    option = "";
}

void View::showAddNewEditionMenu(string* pointer, list<string> isbnCodes)
{
    cleanConsole();
    setHeaderAndFooter("  MENU  DE ALTA DE COPIAS", "Ingrese s para regresar al Menu Pricipal.", 0, 8);
    cout << "  Ingrese Numero de Copia: ";
    option = "";

    getline(cin, option);
    checkIncorrectOption(0, 18, 8);
    pointer[0] = option;
    option = "";
    cout << "\n\n  Ingrese Codigo ISBN: ";
    checkIncorrectOption(0, 23, 11);
    pointer[1] = option;
    option = "";
    cout << "\n\n  Ingrese Ubicacion: ";
    checkIncorrectOption(0, 17, 14);
    pointer[2] = option;
    bool check = false;
    for (auto isbnCode = isbnCodes.begin(); isbnCode != isbnCodes.end(); ++isbnCode) {
        if (*isbnCode == pointer[1]) {
            check = true;
        }
    }
    if (check) {
        cout << "\n\n  Copia agregada con exito!!!, Ingrese s para continuar \n  ";
    }
    else {
        cout << "\n\n  Error: No se encontro el libro con el Codigo ISBN indicado\n  Ingrese s para continuar \n  ";
    }
    cin >> option;
    checkIncorrectOption(6, 2, 18);
    option = "";
}

void View::showHistorialBorrowMenu(list<Borrow> borrows, list<Book> books)
{
    cleanConsole();
    COORD size;
    size.X = 64;
    size.Y = 200;
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), size);
    cout << "----------------------------------------------------------------\n\n";
    cout << "  SISTEMA DE GESTION DIGITAL DE LA BIBLIOTECA PUBLICA NACIONAL\n\n";
    cout << "----------------------------------------------------------------\n\n";
    cout << "                   HISTORIAL DE PRESTAMOS\n\n";
    cout << "----------------------------------------------------------------\n\n";
    for (auto borrow = borrows.begin(); borrow != borrows.end(); ++borrow) {
        string name;
        for (auto book = books.begin(); book != books.end(); ++book) {
            if (book->getIsbnCode() == borrow->getEdition().getIsbnCode()) {
                name = book->getName();
            }
        }
        string category="Socio Comun";
        if (borrow->getMember().getMaxBorrowedEditions() == 3) {
            category = "Socio Vip";
        }
        cout << "  Socio  : " + borrow->getMember().getName() + " " + borrow->getMember().getLastName() + "\n";
        cout << "  Codigo : " + borrow->getMember().getIdentificationCode() + "\tCategoria: " + category + "\n";
        cout << "  Libro  : " + name + "\tCopia: " + borrow->getEdition().getEditionNumber() + "\tISBN: " + borrow->getEdition().getIsbnCode() + "\n";
        if (borrow->getDevolution()) {
            cout << "  Estado : >> Devuelto. <<\n";
        }
        else {
            cout << "  Estado : >> Pendiente de Devolucion. <<\n";
        }
        cout << "  Retiro : " + borrow->getDateOfBorrow()+"\n";
        cout << "  Regreso: " + borrow->getDateOfDevolution() + "\n\n";
        cout << "----------------------------------------------------------------\n\n";
    }
    cout << "\n\n  Presione s para volver al menu principal\n  ";
    cin >> option;
    setConsole();
}

void View::showAvailabilityMenu(list<Book> books)
{
    cleanConsole();
    setHeaderAndFooter("MENU  DE DISPONIBILIDAD DE LIBROS", "Ingrese s para regresar al Menu Pricipal.", 0, 8);
    cout << "  Ingrese Nombre del Libro: ";
    option = "";
    getline(cin, option);
    checkIncorrectOption(0, 28, 8);
    setCursorPosition(2, 11);
    bool check = false;
    for (auto book = books.begin(); book != books.end(); ++book) {
        if (book->getName() == option) {
            check = true;
            cout << "Libro: "  +book->getName() + "    ISBN: " + book->getIsbnCode() + "   Autor: " + book->getAuthor() + "\n";
            for (auto edition = book->getEditions().begin(); edition != book->getEditions().end(); ++edition) {
                cout << "\n  Ejemplar: " + edition->getEditionNumber() + "\t";
                if (edition->getBorrowed()) {
                    cout << "NO DISPONIBLE";
                }
                else {
                    cout << "DISPONIBLE";
                }
            } 
            if (book->getEditions().size() == 0) {
                cout << "\n  Aun no se registran ejemplares de este libro.";
            }
        }
    }

    if (!check) {
        cout << "Libro no encontrado";
    }
    cout << "\n\n\n  Presione s para volver al Menu Principal.\n  ";
    cin >> option;
    checkIncorrectOption(6,2, 17);
    option = "";
}

void View::showEndScreen()
{
    cleanConsole();
    cout << "\n\n\n\n\n\n\n\n\n----------------------------------------------------------------\n";
    cout << "                GRACIAS POR UTILIZAR EL SISTEMA\n";
    cout << "----------------------------------------------------------------\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "----------------------------------------------------------------\n";
    cout << "                                 Presione una tecla para salir.";
    setCursorPosition(0, 15);
}

//--Private Metods-------------------------------------------------------------------

void View::setConsole()
{
    system("mode con: lines=30 cols=64");
    setNormalLetter();
}

void View::cleanConsole()
{
    system("cls");
}

void View::setHeaderAndFooter(string header,string footer, int x, int y) {

    cout << "----------------------------------------------------------------\n\n";
    cout << "  SISTEMA DE GESTION DIGITAL DE LA BIBLIOTECA PUBLICA NACIONAL\n\n";
    cout << "----------------------------------------------------------------\n\n";
    cout << "                    " + header + "                   \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "----------------------------------------------------------------\n";
    cout << "                     " + footer;
    cout << "\n----------------------------------------------------------------";
    setCursorPosition(x, y);
}

void View::setErrorLetter()
{
    SetConsoleTextAttribute(hConsole, 4);
}

void View::setNormalLetter()
{
    SetConsoleTextAttribute(hConsole, 15);
}

void View::setCursorPosition(short x, short y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(hConsole, pos);
}

void View::checkIncorrectOption(int options, int posX, int posY) {

    if (options == 0) {
        getline(cin, option);
        while (option.empty()) {
            setErrorLetter();
            cout << "  Se debe llenar el campo.";
            setNormalLetter();
            setCursorPosition(posX, posY);
            getline(cin, option);
        }
        setCursorPosition(0, posY + 1);
        cout << "                           ";
    }

    if (options == 2) {
        while (option != "1" && option != "2" && option != "s") {
            check(posX, posY);
        }
    }

    if (options == 5) {
        while (option != "1" && option != "2" && option != "3" && option != "4" && option != "5" && option != "6" && option != "7" && option != "s") {
            check(posX, posY);
        }
    }

    if (options == 6) {
        while (option != "s") {
            check(posX, posY);
        }
    }

}

void View::check(int posX, int posY) {
    setCursorPosition(posX, posY);
    setErrorLetter(),
        cout << "  Opcion Incorrecta, Vuelva a intentarlo.";
    setNormalLetter();
    setCursorPosition(posX, posY);
    cin >> option;
}


