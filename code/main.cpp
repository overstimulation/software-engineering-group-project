<<<<<<< Updated upstream
#include "Plik.h"

int main() {
	return 0;
=======
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
#include "Ocena.h"

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
    string nazwaKursu, opisKursu;
    Wykladowca *wykladowca = static_cast<Wykladowca *>(zalogowany);
    do
    {
        cout << "Tworzenie nowego kursu:\n";
        cout << "Nazwa: ";
        cin >> nazwaKursu;
        cout << "Opis: ";
        cin.ignore();
        getline(cin, opisKursu);
        istnieje = false;
        if (nazwaKursu.empty() || opisKursu.empty())
        {
            cout << "Nazwa i opis kursu nie moga byc puste!\n";
            continue;
        }
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
        cout << "Czy chcesz anulowac tworzenie kursu? (t/n): ";
        string anuluj;
        cin >> anuluj;
        if (anuluj == "t" || anuluj == "T")
        {
            cout << "Anulowano tworzenie kursu.\n";
            return;
        }
    } while (istnieje || nazwaKursu.empty() || opisKursu.empty());
    Kurs *nowyKurs = new Kurs(nazwaKursu, wykladowca);
    // TODO: zapisz opis kursu jesli klasa Kurs zostanie rozszerzona
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
    cout << "Zarzadzanie plikami w skrzynce:\n";
    if (zalogowany->getRola() != "student" && zalogowany->getRola() != "wykladowca")
    {
        cout << "Brak uprawnien do zarzadzania plikami.\n";
        return;
    }
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

void zarzadzanieUczestnikami(User *&zalogowany)
{
    system("cls");
    Wykladowca *wykladowca = static_cast<Wykladowca *>(zalogowany);
    list<Kurs *> kursy = wykladowca->getWydzial()->getKursy();
    printKursy(kursy);
    cout << "Podaj nazwe kursu do zarzadzania uczestnikami: ";
    string nazwaKursu;
    cin >> nazwaKursu;
    Kurs *kurs = nullptr;
    for (Kurs *k : kursy)
    {
        if (k->getNazwa() == nazwaKursu)
        {
            kurs = k;
            break;
        }
    }
    if (!kurs)
    {
        cout << "Nie znaleziono kursu.\n";
        return;
    }
    cout << "1. Dodaj uczestnika\n2. Usun uczestnika\n0. Wyjdz\n> ";
    string wybor;
    cin >> wybor;
    if (wybor == "1")
    {
        cout << "Podaj login uzytkownika do dodania: ";
        string login;
        cin >> login;
        User *nowy = nullptr;
        for (User *u : wykladowca->getWydzial()->getUczelnia()->getUzytkownicy())
        {
            if (u->getLogin() == login)
            {
                nowy = u;
                break;
            }
        }
        if (!nowy)
        {
            cout << "Nie znaleziono uzytkownika.\n";
            return;
        }
        if (nowy->getRola() == "student")
        {
            kurs->dodajStudenta(static_cast<Student *>(nowy));
            cout << "Dodano studenta do kursu.\n";
        }
        else if (nowy->getRola() == "wykladowca")
        {
            kurs->dodajWykladowce(static_cast<Wykladowca *>(nowy));
            cout << "Dodano wykladowce do kursu.\n";
        }
        else
        {
            cout << "Nieprawidlowa rola uzytkownika.\n";
        }
    }
    else if (wybor == "2")
    {
        cout << "Podaj ID uzytkownika do usuniecia: ";
        int id;
        cin >> id;
        if (kurs->usunUczestnika(id))
        {
            cout << "Uzytkownik zostal usuniety z kursu.\n";
        }
        else
        {
            cout << "Nie znaleziono uzytkownika w kursie.\n";
        }
    }
    else
    {
        cout << "Wyjscie z zarzadzania uczestnikami.\n";
    }
}

void zarzadzanieOcenami(User *&zalogowany)
{
    system("cls");
    Wykladowca *wykladowca = static_cast<Wykladowca *>(zalogowany);
    list<Kurs *> kursy = wykladowca->getWydzial()->getKursy();
    printKursy(kursy);
    cout << "Podaj nazwe kursu do zarzadzania ocenami: ";
    string nazwaKursu;
    cin >> nazwaKursu;
    Kurs *kurs = nullptr;
    for (Kurs *k : kursy)
    {
        if (k->getNazwa() == nazwaKursu)
        {
            kurs = k;
            break;
        }
    }
    if (!kurs)
    {
        cout << "Nie znaleziono kursu.\n";
        return;
    }
    cout << "1. Dodaj ocene\n2. Usun ocene\n0. Wyjdz\n> ";
    string wybor;
    cin >> wybor;
    if (wybor == "1")
    {
        cout << "Podaj ID studenta: ";
        int id;
        cin >> id;
        Student *student = nullptr;
        for (Student *s : kurs->getStudenci())
        {
            if (s->getId() == id)
            {
                student = s;
                break;
            }
        }
        if (!student)
        {
            cout << "Nie znaleziono studenta w kursie.\n";
            return;
        }
        cout << "Podaj przedmiot: ";
        string przedmiot;
        cin >> przedmiot;
        cout << "Podaj ocene: ";
        int wartosc;
        cin >> wartosc;
        Ocena *nowa = new Ocena(wartosc, przedmiot, student);
        kurs->dodajOcene(nowa);
        cout << "Ocena zostala dodana.\n";
    }
    else if (wybor == "2")
    {
        cout << "Podaj ID studenta: ";
        int id;
        cin >> id;
        cout << "Podaj przedmiot: ";
        string przedmiot;
        cin >> przedmiot;
        Ocena *doUsuniecia = nullptr;
        for (Ocena *o : kurs->getOceny())
        {
            if (o->getAdresat()->getId() == id && o->getPrzedmiot() == przedmiot)
            {
                doUsuniecia = o;
                break;
            }
        }
        if (doUsuniecia && kurs->usunOcene(doUsuniecia))
        {
            cout << "Ocena zostala usunieta.\n";
        }
        else
        {
            cout << "Nie znaleziono oceny do usuniecia.\n";
        }
    }
    else
    {
        cout << "Wyjscie z zarzadzania ocenami.\n";
    }
}

void zarzadzanieSkrzynkami(User *&zalogowany)
{
    system("cls");
    Wykladowca *wykladowca = static_cast<Wykladowca *>(zalogowany);
    list<Kurs *> kursy = wykladowca->getWydzial()->getKursy();
    printKursy(kursy);
    cout << "Podaj nazwe kursu do zarzadzania skrzynkami: ";
    string nazwaKursu;
    cin >> nazwaKursu;
    Kurs *kurs = nullptr;
    for (Kurs *k : kursy)
    {
        if (k->getNazwa() == nazwaKursu)
        {
            kurs = k;
            break;
        }
    }
    if (!kurs)
    {
        cout << "Nie znaleziono kursu.\n";
        return;
    }
    cout << "1. Dodaj skrzynke\n2. Usun skrzynke\n0. Wyjdz\n> ";
    string wybor;
    cin >> wybor;
    if (wybor == "1")
    {
        cout << "Podaj nazwe nowej skrzynki: ";
        string nazwa;
        cin >> nazwa;
        Skrzynka *nowa = new Skrzynka(nazwa);
        kurs->dodajSkrzynke(nowa);
        cout << "Skrzynka zostala dodana.\n";
    }
    else if (wybor == "2")
    {
        cout << "Podaj ID skrzynki do usuniecia: ";
        int id;
        cin >> id;
        if (kurs->usunSkrzynke(id))
        {
            cout << "Skrzynka zostala usunieta.\n";
        }
        else
        {
            cout << "Nie znaleziono skrzynki o podanym ID.\n";
        }
    }
    else
    {
        cout << "Wyjscie z zarzadzania skrzynkami.\n";
    }
}

void loggedPrompt(string *input, User *&zalogowany)
{
    string rola = zalogowany->getRola();

    if (rola == "wykladowca")
    {
        cout << STWORZ_KURS << ". Stworz kurs\n";
        cout << ZARZADZANIE_KURS << ". Zarzadzanie istniejacym kursem\n";
        cout << "5. Zarzadzanie uczestnikami kursu\n";
        cout << "6. Zarzadzanie ocenami\n";
        cout << "7. Zarzadzanie skrzynkami plikow\n";
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
    else if (*input == STWORZ_KURS)
    {
        stworzKurs(zalogowany);
    }
    else if (*input == ZARZADZANIE_KURS)
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
    else if (*input == "5")
    {
        zarzadzanieUczestnikami(zalogowany);
    }
    else if (*input == "6")
    {
        zarzadzanieOcenami(zalogowany);
    }
    else if (*input == "7")
    {
        zarzadzanieSkrzynkami(zalogowany);
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
>>>>>>> Stashed changes
}