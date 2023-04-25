#include "Presenter.h"
#include "Member.h"


Presenter::Presenter()
{
}

void Presenter::PrecargarDatos()
{
    library = Library();
    /*
    Member member1 = Member("Pedro", "Gonzalez", "1001");
    Member member2 = Member("Juan", "Lezcano", "1002");
    Member member3 = Member("Roberto", "Sanchez", "1003");
    Member vipMember1 = VipMember("Marcelo", "Perez", "2001", 250.5);
    Member vipMember2 = VipMember("Julian", "Esquibel", "2002", 500.5);
    Member vipMember3 = VipMember("Martina", "Fernandez", "2001", 700.5);

    library.addNewMember(member1);
    library.addNewMember(member2);
    library.addNewMember(member3);
    library.addNewMember(vipMember1);
    library.addNewMember(vipMember2);
    library.addNewMember(vipMember3);

    Book book1 = Book("Calculo Numerico", "10001-001", "Pedro Sanchez");
    Book book2 = Book("Ciencias de la Tierra", "10001-002", "Jorge Martinez");
    Book book3 = Book("Lengua y Literatura 1", "10001-003", "Roberto Fernandez");
    Book book4 = Book("Historia Argentina", "10001-004", "Martin Canarias");
    Book book5 = Book("Geografia 2", "10001-005", "Hugo Lopez");
    Book book6 = Book("Ciencias Sociales 4", "10001-006  ", "Cristian Ortega");

    library.addNewBook(book1);
    library.addNewBook(book2);
    library.addNewBook(book3);
    library.addNewBook(book4);
    library.addNewBook(book5);
    library.addNewBook(book6);
    */
    view = View();
}


void Presenter::excute()
{
    string option="0";
    bool error = false;
    while (option != "s") {
        option = view.showMainMenu();
        if (option == "1") {
            string data[2] = {"-1","-1"};
            string* pointerData = data;
            view.showBorrowMenu(pointerData, library.getMembers(), library.getBooks());
            if (pointerData[0] != "-1" && pointerData[1] != "-1") {
                for (auto member = library.getMembers().begin(); member != library.getMembers().end(); ++member) {
                    if (member->getIdentificationCode() == data[1]) {
                        for (auto book = library.getBooks().begin(); book != library.getBooks().end(); ++book) {
                            if (book->getIsbnCode() == data[0]) {
                                bool check = true;
                                for (auto edition = book->getEditions().begin(); edition != book->getEditions().end(); ++edition) {
                                    if (check) {
                                        if (edition->getBorrowed() == false) {
                                            edition->setBorrowed(true);
                                            member->borrowEdition(*edition);
                                            Borrow borrow = Borrow(*member, *edition);
                                            library.addBorrow(borrow);
                                            check = false;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }else if (option == "2") {
            string data[2] = {"-1","-1"};
            string* pointerData = data;
            view.showDevolutionMenu(pointerData,library.getBorrows());
            if (data[0] != "-1" && data[1] != "-1") {
                Edition edition0=Edition("","","");
                for (auto member = library.getMembers().begin();member != library.getMembers().end();++member) {
                    if (member->getIdentificationCode()==data[0]) {
                        for (auto edition = member->getBorrowedEditions().begin();edition != member->getBorrowedEditions().end();++edition) {
                            if (edition->getIsbnCode() == data[1]) {
                                edition0 = *edition;
                            }
                        }
                    }
                    for (auto book = library.getBooks().begin();book != library.getBooks().end();++book) {
                        if (book->getIsbnCode() == edition0.getIsbnCode()) {
                            for (auto edition = book->getEditions().begin();edition != book->getEditions().end();++edition) {
                                if (edition->getEditionNumber() == edition0.getEditionNumber()) {
                                    edition->setBorrowed(false);
                                }
                            }
                        }
                    }
                    member->deleteEdition(edition0);
                }
                for (auto borrow = library.getBorrows().begin();borrow != library.getBorrows().end();++borrow) {
                    if (!borrow->getDevolution()) {
                        if (borrow->getMember().getIdentificationCode() == data[0]) {
                            if (borrow->getEdition().getIsbnCode() == data[1]) {
                                borrow->setDevolution(true);
                            }
                        }
                    }
                }
            }
        }else if (option == "3") {
            string data[5];
            string* pointer=data;
            view.showAddNewMemberMenu(pointer);
            if (data[3] == "1") {
                VipMember vipMember = VipMember(data[0], data[1], data[2], stof(data[4]));
                library.addNewMember(vipMember);
            }
            else {
                Member member = Member(data[0], data[1], data[2]);
                library.addNewMember(member);
            }
        }
        else if (option == "4") {
            string data[3];
            string* pointer = data;
            view.showAddNewBookMenu(pointer);
            Book book = Book(data[0], data[1], data[2]);
            library.addNewBook(book);
        }else if (option == "5") {
            string data[3];
            string* pointer = data;
            view.showAddNewEditionMenu(pointer, library.getIsbnCodes());
            Edition edition = Edition(data[1], data[0],data[2]);
            if (library.getBooks().size() > 0) {
                for (auto book = library.getBooks().begin(); book != library.getBooks().end(); ++book) {
                    if (book->getIsbnCode() == data[1]) {
                        book->addNewEdition(edition);
                    }
                }
            }
        }
        else if (option == "6") {
            view.showHistorialBorrowMenu(library.getBorrows(),library.getBooks());
        }
        else if (option == "7") {
            view.showAvailabilityMenu(library.getBooks());
        }
        else{
            view.showEndScreen();
        }
    }
}


