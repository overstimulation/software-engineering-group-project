#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include "Uczelnia.h"
#include "Wydzial.h"
#include "User.h"
#include "Student.h"
#include "Wykladowca.h"
#include "Kurs.h"
#include "Poczta.h"
#include "Wiadomosc.h"
#include "Skrzynka.h"
#include "Plik.h"
#include "Ocena.h"
#include "testy.h"

// Do logowania
const string LOGOWANIE = "1";
const string REJESTRACJA = "2";

// Po zalogowaniu studenta
const string ZARZADZANIE_PLIKAMI = "2";

// Po zalogowaniu wykladowcy
const string STWORZ_KURS = "2";
const string ZARZADZANIE_KURS = "3";

// Po zalogowaniu all
const string POCZTA = "1";
const string WYLOGUJ = "4";

// Zawsze
const string OUT = "0";

static Poczta pocztaInst;

void clearConsole()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pressEnterToContinue()
{
    cout << "Nacisnij Enter, aby kontynuowac...";
    cin.get();
}

void printMenuHeader(const string &menuName)
{
    clearConsole();
    string line(menuName.length() + 2, '=');
    cout << line << "\n"
         << menuName << "\n"
         << line << "\n";
}

void printStudents(list<Student *> studenci)
{
    cout << "DEBUG studenci\n";
    for (Student *s : studenci)
    {
        cout << "Student: " << s->getImie() << " " << s->getNazwisko() << " - " << s->getLogin() << " " << s->getHaslo() << "\n";
    }
}

void printKursy(list<Kurs *> kursy)
{
    int i = 1;
    if (kursy.size() == 0)
    {
        cout << "Brak kursow.\n";
        pressEnterToContinue();
        cin.ignore();
        return;
    }
    cout << "Lista kursow:\n";
    for (Kurs *k : kursy)
    {
        cout << i++ << ". " << k->getNazwa() << "\n";
    }
}

void baseInit(Uczelnia *UMCS, Wydzial *MFII)
{
    Student *s001 = new Student("Mateusz", "Zawal", MFII, 312428, 2, 1);
    Student *s002 = new Student("Jakub", "Dobrowolski", MFII, 318759, 2, 1);
    Student *s003 = new Student("Kacper", "Bednarczuk", MFII, 318685, 2, 1);

    s001->setLogin("Emzeey");
    s001->setHaslo("123");
    s002->setLogin("DeKa");
    s002->setHaslo("123");
    s003->setLogin("overstimulation");
    s003->setHaslo("123");

    Wykladowca *w001 = new Wykladowca("Andrzej", "Daniluk", MFII, "doktor", "inzynieria oprogramowania");
    w001->setLogin("daniluk");
    w001->setHaslo("tron");

    Kurs *k1 = new Kurs("Programowanie obiektowe", w001);
    Kurs *k2 = new Kurs("Bazy danych", w001);
    w001->getKursy()->push_back(k1);
    w001->getKursy()->push_back(k2);
    MFII->dodajKurs(k2);
    k2->dodajStudenta(s001);
    k2->dodajStudenta(s003);
    Ocena *o1 = new Ocena(5, s001);
    Ocena *o2 = new Ocena(4, s003);

    k2->dodajOcene(o1);
    k2->dodajOcene(o2);

    Skrzynka *nowa = new Skrzynka("kolos");
    k2->dodajSkrzynke(nowa);
    Plik *nowyPlik = new Plik("zadanie1", 0, "");
    nowa->setPlik(nowyPlik);

    Wiadomosc *tron = new Wiadomosc("egzamin", "https://www.cda.pl/video/1190300338", "27-05-2025", w001, s001);
    Wiadomosc *tron2 = new Wiadomosc("egzamin", "https://www.cda.pl/video/1190300338", "27-05-2025", s001, w001);

    s001->wyslijWiadomosc(&pocztaInst, tron);
    w001->wyslijWiadomosc(&pocztaInst, tron2);
}

void notLoggedPrompt(string *input, User *&zalogowany, Uczelnia *&UMCS)
{
    printMenuHeader("Menu Glowne");
    cout << LOGOWANIE << ". Logowanie\n";
    cout << REJESTRACJA << ". Rejestracja\n";
    cout << OUT << ". Koniec\n";
    cout << "> ";
    cin >> *input;

    if (*input == LOGOWANIE)
    {
        clearConsole();
        printMenuHeader("Logowanie");
        // printStudents(UMCS->getStudenci());
        zalogowany = User::zaloguj(UMCS);
    }
    else if (*input == REJESTRACJA)
    {
        clearConsole();
        printMenuHeader("Rejestracja");
        zalogowany = User::zarejestruj(UMCS);
    }
}

void zarzadzanieKursem(User *&zalogowany)
{
    clearConsole();
    printMenuHeader("Zarzadzanie kursem");
    Wykladowca *wykladowca = static_cast<Wykladowca *>(zalogowany);
    list<Kurs *> kursy = *wykladowca->getKursy();
    printKursy(kursy);
    if (kursy.empty())
    {
        return;
    }

    string wyborKursu;
    cout << "Wybierz kurs z powyzszych wpisujac nazwe:\n> ";
    cin.ignore();
    getline(cin, wyborKursu);

    Kurs *kurs = nullptr;
    for (Kurs *k : kursy)
    {
        if (k->getNazwa() == wyborKursu)
        {
            kurs = k;
            break;
        }
    }

    if (!kurs)
    {
        pressEnterToContinue();
        return;
    }

    bool running = true;
    while (running)
    {
        clearConsole();
        printMenuHeader("Panel zarzadzania kursem: " + kurs->getNazwa());
        cout << "1. Dodaj skrzynke plikow\n";
        cout << "2. Usun skrzynke plikow\n";
        cout << "3. Dodaj uczestnika (student/wykladowca)\n";
        cout << "4. Usun uczestnika\n";
        cout << "5. Wyswietl uczestnikow\n";
        cout << "6. Wyswietl skrzynki plikow\n";
        cout << "7. Przegladaj pliki w skrzynkach\n";
        cout << "8. Wyswietl studentow i wykladowcow na wydziale\n";
        cout << "9. Zarzadzaj ocenami\n";
        cout << "0. Wyjdz\n";
        cout << "> "; // Znak zachety
        string opcja;
        getline(cin, opcja);
        if (opcja == "1")
        {
            cout << "Podaj nazwe nowej skrzynki: ";
            string nazwa;
            getline(cin, nazwa);
            static int nextId = 1;
            Skrzynka *nowa = new Skrzynka(nazwa);
            kurs->dodajSkrzynke(nowa);
            cout << "Dodano skrzynke. Nacisnij Enter...";
            cin.get();
        }
        else if (opcja == "2")
        {
            cout << "Podaj ID skrzynki do usuniecia: ";
            int id;
            cin >> id;
            cin.ignore();
            if (kurs->usunSkrzynke(id))
                cout << "Usunieto skrzynke. ";
            else
            {
                cout << "Nie znaleziono skrzynki o podanym ID.";
            }
            pressEnterToContinue();
        }
        else if (opcja == "3")
        {
            cout << "Dodaj uczestnika (student/wykladowca):\n1. Student\n2. Wykladowca\n> ";
            string typ;
            getline(cin, typ);
            if (typ == "1")
            {
                cout << "Podaj ID studenta: ";
                int id;
                cin >> id;
                cin.ignore();
                // Szukaj studenta po ID na wydziale
                Student *s = nullptr;
                for (Student *st : kurs->getWykladowcy().front()->getWydzial()->getUczelnia()->getStudenci())
                {
                    if (st->getId() == id)
                    {
                        s = st;
                        break;
                    }
                }
                if (s)
                {
                    kurs->dodajStudenta(s);
                    // s->getKursy()->push_back(kurs);
                    cout << "Dodano studenta. ";
                }
                else
                {
                    cout << "Nie znaleziono studenta o podanym ID. ";
                }
            }
            else if (typ == "2")
            {
                cout << "Podaj ID wykladowcy: ";
                int id;
                cin >> id;
                cin.ignore();
                Wykladowca *w = nullptr;
                for (Wykladowca *wyk : kurs->getWykladowcy().front()->getWydzial()->getUczelnia()->getWykladowcy())
                {
                    if (wyk->getId() == id)
                    {
                        w = wyk;
                        break;
                    }
                }
                if (w)
                {
                    kurs->dodajWykladowce(w);
                    // w->getKursy()->push_back(kurs);
                    cout << "Dodano wykladowce. ";
                }
                else
                {
                    cout << "Nie znaleziono wykladowcy o podanym ID.";
                }
            }
            pressEnterToContinue();
        }
        else if (opcja == "4")
        {
            cout << "Podaj ID uczestnika do usuniecia: ";
            int id;
            cin >> id;
            cin.ignore();
            if (kurs->usunUczestnika(id))
                cout << "Usunieto uczestnika. ";
            else
                cout << "Nie znaleziono uczestnika o podanym ID. ";
            pressEnterToContinue();
        }
        else if (opcja == "5")
        {
            cout << "Studenci:\n";
            for (Student *s : kurs->getStudenci())
            {
                cout << "ID: " << s->getId() << ", " << s->getImie() << " " << s->getNazwisko() << "\n";
            }
            cout << "Wykladowcy:\n";
            for (Wykladowca *w : kurs->getWykladowcy())
            {
                cout << "ID: " << w->getId() << ", " << w->getImie() << " " << w->getNazwisko() << "\n";
            }
            pressEnterToContinue();
        }
        else if (opcja == "6")
        {
            cout << "Skrzynki plikow:\n";
            if (kurs->getSkrzynki().size() == 0)
            {
                cout << "Brak skrzynek w tym kursie.\n";
            }
            for (Skrzynka *s : kurs->getSkrzynki())
            {
                cout << "ID: " << s->getId() << ", " << s->getNazwa() << "\n";
            }
            pressEnterToContinue();
        }
        else if (opcja == "7")
        {
            // Przegladanie plikow w skrzynkach
            auto skrzynki = kurs->getSkrzynki();
            if (skrzynki.empty())
            {
                cout << "Brak skrzynek plikow w tym kursie.\n";
                pressEnterToContinue();
                continue;
            }
            cout << "Dostepne skrzynki plikow:\n";
            for (Skrzynka *s : skrzynki)
            {
                cout << s->getId() << ": " << s->getNazwa() << "\n";
            }
            cout << "Podaj ID skrzynki do sprawdzenia: ";
            int idSkrzynki;
            cin >> idSkrzynki;
            cin.ignore();
            Skrzynka *wybranaSkrzynka = nullptr;
            for (Skrzynka *s : skrzynki)
            {
                if (s->getId() == idSkrzynki)
                {
                    wybranaSkrzynka = s;
                    break;
                }
            }
            if (!wybranaSkrzynka)
            {
                cout << "Nie znaleziono skrzynki o podanym ID.\n";
                pressEnterToContinue();
                continue;
            }
            Plik *plik = wybranaSkrzynka->getPlik();
            if (plik)
            {
                cout << "Plik w skrzynce: " << plik->getNazwa() << "\n";
                cout << "Data dodania: " << plik->getDataDodania() << "\n";
                cout << "Rozmiar: " << plik->getRozmiar() << " bajtow\n";
                pressEnterToContinue();
            }
            else
            {
                cout << "Brak pliku w tej skrzynce.\n";
                pressEnterToContinue();
            }
        }
        else if (opcja == "8")
        {
            Wydzial *wydzial = kurs->getWykladowcy().front()->getWydzial();
            cout << "Studenci na wydziale:\n";
            for (Student *s : wydzial->getStudenci())
            {
                cout << "ID: " << s->getId() << ", " << s->getImie() << " " << s->getNazwisko() << ", e-mail: " << s->getEmail() << "\n";
            }
            cout << "Wykladowcy na wydziale:\n";
            for (Wykladowca *w : wydzial->getWykladowcy())
            {
                cout << "ID: " << w->getId() << ", " << w->getImie() << " " << w->getNazwisko() << ", e-mail: " << w->getEmail() << "\n";
            }
            pressEnterToContinue();
        }
        else if (opcja == "9")
        {
            // Zarzadzanie ocenami
            bool ocenyRunning = true;
            while (ocenyRunning)
            {
                clearConsole();
                printMenuHeader("Zarzadzanie ocenami w kursie: " + kurs->getNazwa());
                cout << "Studenci w kursie:\n";
                for (Student *s : kurs->getStudenci())
                {
                    cout << "ID: " << s->getId() << ", " << s->getImie() << " " << s->getNazwisko() << "\n";
                }
                cout << "Podaj ID studenta lub 0 aby wyjsc: ";
                int idStudenta;
                cin >> idStudenta;
                cin.ignore();
                if (idStudenta == 0)
                    break;
                Student *wybrany = nullptr;
                for (Student *s : kurs->getStudenci())
                {
                    if (s->getId() == idStudenta)
                    {
                        wybrany = s;
                        break;
                    }
                }
                if (!wybrany)
                {
                    cout << "Nie znaleziono studenta o podanym ID.\n";
                    pressEnterToContinue();
                    continue;
                }
                bool studentOceny = true;
                while (studentOceny)
                {
                    clearConsole();
                    printMenuHeader("Oceny studenta: " + wybrany->getImie() + " " + wybrany->getNazwisko());
                    cout << "1. Dodaj ocene\n2. Usun ocene\n3. Pokaz oceny\n0. Powrot\n> ";
                    string wybor;
                    getline(cin, wybor);
                    if (wybor == "1")
                    {
                        cout << "Podaj wartosc oceny (2-5): ";
                        int wartosc;
                        cin >> wartosc;
                        cin.ignore();
                        if (wartosc < 2 || wartosc > 5)
                        {
                            cout << "Nieprawidlowa wartosc oceny.\n";
                            pressEnterToContinue();
                            continue;
                        }
                        Ocena *nowa = new Ocena(wartosc, wybrany);
                        kurs->dodajOcene(nowa);
                        cout << "Dodano ocene.\n";
                        pressEnterToContinue();
                    }
                    else if (wybor == "2")
                    {
                        // Pokaz oceny i pozwol usunac
                        std::vector<Ocena *> ocenyStudenta;
                        int idx = 1;
                        for (Ocena *o : kurs->getOceny())
                        {
                            if (o->getAdresat() == wybrany)
                            {
                                cout << idx << ". Ocena: " << o->getWartosc() << "\n";
                                ocenyStudenta.push_back(o);
                                idx++;
                            }
                        }
                        if (ocenyStudenta.empty())
                        {
                            cout << "Brak ocen do usuniecia.\n";
                            pressEnterToContinue();
                            continue;
                        }
                        cout << "Podaj numer oceny do usuniecia lub 0 aby anulowac: ";
                        int nr;
                        cin >> nr;
                        cin.ignore();
                        if (nr > 0 && nr <= ocenyStudenta.size())
                        {
                            if (kurs->usunOcene(ocenyStudenta[nr - 1]))
                                cout << "Usunieto ocene.\n";
                            else
                                cout << "Blad usuwania oceny.\n";
                        }
                        else
                        {
                            cout << "Anulowano.\n";
                        }
                        pressEnterToContinue();
                    }
                    else if (wybor == "3")
                    {
                        cout << "Oceny studenta:\n";
                        for (Ocena *o : kurs->getOceny())
                        {
                            if (o->getAdresat() == wybrany)
                            {
                                cout << "Ocena: " << o->getWartosc() << "\n";
                            }
                        }
                        pressEnterToContinue();
                    }
                    else if (wybor == "0")
                    {
                        studentOceny = false;
                    }
                    else
                    {
                        cout << "Nieznana opcja.\n";
                        pressEnterToContinue();
                    }
                }
            }
        }
        else if (opcja == "0")
        {
            running = false;
        }
        else
        {
            cout << "Nieznana opcja. Nacisnij Enter...";
            cin.get();
        }
    }
}

void zarzadzaniePlikami(User *&zalogowany)
{
    clearConsole();
    printMenuHeader("Zarzadzanie plikami");
    cout << "Zarzadzanie plikami w skrzynce:\n";
    list<Kurs *> *kursy = zalogowany->getKursy();
    if (!kursy || kursy->empty())
    {
        cout << "Brak kursow przypisanych do uzytkownika.\n";
        pressEnterToContinue();
        cin.ignore();
        return;
    }
    printKursy(*kursy);
    cout << "Podaj nazwe kursu: ";
    string nazwaKursu;
    cin >> nazwaKursu;
    Kurs *wybranyKurs = nullptr;
    for (Kurs *k : *kursy)
    {
        if (k->getNazwa() == nazwaKursu)
        {
            wybranyKurs = k;
            break;
        }
    }
    if (!wybranyKurs)
    {
        cout << "Nie znaleziono kursu.\n";
        pressEnterToContinue();
        cin.ignore();
        return;
    }
    auto skrzynki = wybranyKurs->getSkrzynki();
    if (skrzynki.empty())
    {
        cout << "Brak skrzynek w tym kursie.\n";
        pressEnterToContinue();
        cin.ignore();
        return;
    }
    cout << "Dostepne skrzynki:\n";
    for (Skrzynka *s : skrzynki)
    {
        cout << s->getId() << ": " << s->getNazwa() << "\n";
    }
    cout << "Podaj ID skrzynki: ";
    int idSkrzynki;
    cin >> idSkrzynki;
    Skrzynka *wybranaSkrzynka = nullptr;
    for (Skrzynka *s : skrzynki)
    {
        if (s->getId() == idSkrzynki)
        {
            wybranaSkrzynka = s;
            break;
        }
    }
    if (!wybranaSkrzynka)
    {
        cout << "Nie znaleziono skrzynki.\n";
        pressEnterToContinue();
        return;
    }
    // Dodawanie pliku - symbolicznie: tylko sciezka
    cout << "Podaj sciezke do istniejacego pliku (symbolicznie): ";
    string sciezka;
    cin.ignore();
    getline(cin, sciezka);
    if (sciezka.empty())
    {
        cout << "Sciezka nie moze byc pusta!\n";
        return;
    }
    Plik *nowyPlik = new Plik(sciezka, 0, ""); // rozmiar i tresc ignorowane
    wybranaSkrzynka->setPlik(nowyPlik);        // zawsze zastepuje
    cout << "Plik zostal dodany do skrzynki (sciezka symboliczna).\n";
    pressEnterToContinue();
}

void poczta(User *&zalogowany)
{
    clearConsole();
    printMenuHeader("Panel poczty");

    cout << "1. Sprawdz wiadomosci\n2. Wyslij wiadomosc\n0. Wyjdz\n> ";
    string wybor;
    cin >> wybor;
    if (wybor == "1")
    {
        // Sprawdz wiadomosci
        printMenuHeader("Sprawdzanie wiadomosci");
        auto wiadomosci = zalogowany->sprawdzWiadomosci(&pocztaInst);
        if (wiadomosci.empty())
        {
            cout << "Brak wiadomosci.\n";
            pressEnterToContinue();
            cin.ignore();
            return;
        }
        cout << "Twoje wiadomosci:\n";
        int idx = 1;
        for (Wiadomosc *w : wiadomosci)
        {
            string data = w->getData();
            if (!data.empty() && data.back() == '\n')
                data.pop_back();
            cout << idx++ << ". " << w->getTemat() << " (" << data << ")\n";
        }
        cout << "Podaj numer wiadomosci do odczytania lub 0 aby wyjsc: ";
        int nr;
        cin >> nr;
        if (nr > 0 && nr <= wiadomosci.size())
        {
            auto it = wiadomosci.begin();
            advance(it, nr - 1);
            Wiadomosc *wybrana = *it;
            cout << "Temat: " << wybrana->getTemat() << "\nTresc: " << wybrana->getTresc() << "\nData: " << wybrana->getData() << "\n";
            pressEnterToContinue();
            cin.ignore();
        }
    }
    else if (wybor == "2")
    {
        // Wyslij wiadomosc
        printMenuHeader("Wysylanie wiadomosci");
        string emailOdbiorcy, temat, tresc;
        cout << "Podaj e-mail odbiorcy: ";
        cin >> emailOdbiorcy;
        User *odbiorca = nullptr;
        for (User *u : zalogowany->getWydzial()->getUczelnia()->getUzytkownicy())
        {
            if (u->getEmail() == emailOdbiorcy)
            {
                odbiorca = u;
                break;
            }
        }
        if (!odbiorca)
        {
            cout << "Nie znaleziono odbiorcy o podanym e-mailu.\n";
            pressEnterToContinue();
            cin.ignore();
            return;
        }
        cout << "Temat: ";
        cin.ignore();
        getline(cin, temat);
        cout << "Tresc: ";
        getline(cin, tresc);
        time_t now = time(0);
        char *dt = ctime(&now);
        Wiadomosc *nowa = new Wiadomosc(temat, tresc, string(dt), odbiorca, zalogowany);
        zalogowany->wyslijWiadomosc(&pocztaInst, nowa);
        cout << "Wiadomosc zostala wyslana.\n";
        pressEnterToContinue();
    }
    else
    {
        cout << "Wyjscie z poczty.\n";
    }
}

void loggedPrompt(string *input, User *&zalogowany)
{
    string rola = zalogowany->getRola();
    printMenuHeader("Menu uzytkownika");

    cout << POCZTA << ". Poczta\n";

    if (rola == "wykladowca")
    {
        cout << STWORZ_KURS << ". Stworz kurs\n";
        cout << ZARZADZANIE_KURS << ". Zarzadzanie istniejacym kursem\n";
    }
    else if (rola == "student")
    {
        cout << ZARZADZANIE_PLIKAMI << ". Zarzadzanie plikami skrzynki w kursie\n";
    }

    cout << WYLOGUJ << ". Wyloguj\n";
    cout << OUT << ". Koniec\n";
    cout << "> ";
    cin >> *input;

    if (*input == WYLOGUJ)
    {
        zalogowany = zalogowany->wyloguj();
    }
    else if (*input == STWORZ_KURS && rola == "wykladowca")
    {
        static_cast<Wykladowca *>(zalogowany)->stworzKurs();
    }
    else if (*input == ZARZADZANIE_KURS && rola == "wykladowca")
    {
        zarzadzanieKursem(zalogowany);
    }
    else if (*input == ZARZADZANIE_PLIKAMI)
    {
        zarzadzaniePlikami(zalogowany);
    }
    else if (*input == POCZTA)
    {
        poczta(zalogowany);
    }
}

int main()
{
    bool testy = false;
    if (testy)
    {
        runAllTests();
        cout << "Wszystkie testy zakonczone sukcesem." << endl;
        cout << "Nacisnij Enter, aby kontynuowac...";
        cin.get();
        cin.ignore();
    }
    Uczelnia *UMCS = new Uczelnia("Uniwersytet Marii Curie Sklodowskiej", "Pl. M. Curie-Sklodowskiej 5 20-031 Lublin");
    Wydzial *MFII = new Wydzial("mfii", UMCS);

    baseInit(UMCS, MFII);

    // Interface
    User *zalogowany = nullptr;

    clearConsole();
    string input = "";
    while (input != OUT)
    {
        cout << "Witamy w systemie wspomagania uczelnianego, co chcesz zrobic?\n";
        if (zalogowany == nullptr)
        {
            notLoggedPrompt(&input, zalogowany, UMCS);
        }
        else
        {
            loggedPrompt(&input, zalogowany);
        }
    }
}
