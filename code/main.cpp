#include <list>
#include "Uczelnia.h"
#include "Wydzial.h"
#include "User.h"
#include "Student.h"
#include "Wykladowca.h"
#include "Kurs.h"
#include "Poczta.h"
#include "Wiadomosc.h"

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

// To remove later
void baseInit(Uczelnia *UMCS, Wydzial *MFII)
{
    Student *s001 = new Student("Mateusz", "Zawal", MFII, 312428, 2, 1);
    Student *s002 = new Student("Jakub", "Dobrowolski", MFII, 123456, 2, 1);
    Student *s003 = new Student("Kacper", "Bednarczuk", MFII, 654321, 2, 1);

    s001->setLogin("1");
    s001->setHaslo("1");
    s002->setLogin("2");
    s002->setHaslo("2");
    s003->setLogin("3");
    s003->setHaslo("3");

    Wykladowca *w001 = new Wykladowca("Andrzej", "Daniluk", MFII, "doktor", "inzynieria oprogramowania");
    w001->setLogin("0");
    w001->setHaslo("0");
}

void notLoggedPrompt(string *input, User *&zalogowany, Uczelnia *&UMCS)
{
    cout << LOGOWANIE << ". Logowanie\n";
    cout << REJESTRACJA << ". Rejestracja\n";
    cout << OUT << ". Koniec\n";
    cout << "> ";
    cin >> *input;

    if (*input == LOGOWANIE)
    {
        system("cls");
        printStudents(UMCS->getStudenci());
        zalogowany = User::zaloguj(UMCS);
    }
    else if (*input == REJESTRACJA)
    {
        system("cls");
        zalogowany = User::zarejestruj(UMCS);
    }
}

void stworzKurs(User *&zalogowany)
{
    system("cls");

    bool istnieje = false;
    string nazwaKursu;
    Wykladowca *wykladowca = static_cast<Wykladowca *>(zalogowany);

    do
    {
        cout << "Tworzenie nowego kursu:\n";
        cout << "Nazwa: ";
        cin >> nazwaKursu;
        istnieje = false;

        for (Kurs *k : wykladowca->getWydzial()->getKursy())
        {
            if (k->getNazwa() == nazwaKursu)
            {
                istnieje = true;
                break;
            }
        }

        if (istnieje)
        {
            cout << "Kurs o podanej nazwie juz istnieje. Sprobuj ponownie.\n";
        }
    } while (istnieje);

    Kurs *nowyKurs = new Kurs(nazwaKursu, wykladowca);
    wykladowca->getWydzial()->dodajKurs(nowyKurs);
    cout << "Pomyslnie stworzono kurs.\n";
}

void zarzadzanieKursem(User *&zalogowany)
{
    system("cls");
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
    system("cls");
    // TODO
}

void poczta(User *&zalogowany)
{
    system("cls");
    static Poczta pocztaInst;
    cout << "Panel poczty:\n1. Sprawdz wiadomosci\n2. Wyslij wiadomosc\n0. Wyjdz\n> ";
    string wybor;
    cin >> wybor;
    if (wybor == "1")
    {
        // Sprawdz wiadomosci
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
            cout << idx++ << ". " << w->getTemat() << " (" << w->getData() << ")\n";
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
        }
        else
        {
            cout << "Wyjscie z widoku wiadomosci.\n";
        }
    }
    else if (wybor == "2")
    {
        // Wyslij wiadomosc
        string loginOdbiorcy, temat, tresc;
        cout << "Podaj login odbiorcy: ";
        cin >> loginOdbiorcy;
        User *odbiorca = nullptr;
        for (User *u : zalogowany->getWydzial()->getUczelnia()->getUzytkownicy())
        {
            if (u->getLogin() == loginOdbiorcy)
            {
                odbiorca = u;
                break;
            }
        }
        if (!odbiorca)
        {
            cout << "Nie znaleziono odbiorcy o podanym loginie.\n";
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

    if (rola == "wykladowca")
    {
        cout << STWORZ_KURS << ". Stworz kurs\n";
        cout << ZARZADZANIE_KURS << ". Zarzadzanie istniejacym kursem\n";
    }
    else if (rola == "student")
    {
        cout << ZARZADZANIE_PLIKAMI << ". Zarzadzanie plikami skrzynki w kursie\n";
    }

    cout << POCZTA << ". Poczta\n";
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
        stworzKurs(zalogowany);
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

    system("cls");
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