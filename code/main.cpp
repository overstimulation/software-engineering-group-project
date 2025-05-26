#include <list>
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

void clearConsole()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
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
    w001->setLogin("0");
    w001->setHaslo("0");
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
    printMenuHeader("Zarządzanie kursem");
    Wykladowca *wykladowca = static_cast<Wykladowca *>(zalogowany);
    list<Kurs *> kursy = wykladowca->getWydzial()->getKursy();
    printKursy(kursy);

    string wybor;
    cout << "Wybierz kurs z powyzszych wpisujac nazwe:\n";
    cout << "> ";
    cin >> wybor;

    Kurs *kurs = nullptr;
    for (Kurs *k : kursy)
    {
        if (k->getNazwa() == wybor)
        {
            kurs = k;
            break;
        }
    }

    if (kurs != nullptr)
    {
        cout << "Zarzadzanie kursem:\n";
    }
    else
    {
        cout << "Nie ma takiego kursu.\n";
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
        return;
    }
    auto skrzynki = wybranyKurs->getSkrzynki();
    if (skrzynki.empty())
    {
        cout << "Brak skrzynek w tym kursie.\n";
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
}

void poczta(User *&zalogowany)
{
    clearConsole();
    printMenuHeader("Panel poczty");
    static Poczta pocztaInst;
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
            cout << "Nacisnij Enter, aby wrocic do menu...";
            cin.ignore();
            cin.get();
        }
        else
        {
            cout << "Wyjscie z widoku wiadomosci.\n";
            cout << "Nacisnij Enter, aby wrocic do menu...";
            cin.ignore();
            cin.get();
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