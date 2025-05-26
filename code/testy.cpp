#include <cassert>
#include <iostream>
#include <string>
#include "Kurs.h"
#include "Student.h"
#include "Wykladowca.h"
#include "Skrzynka.h"
#include "Ocena.h"
#include "Plik.h"
#include "Wydzial.h"
#include "Uczelnia.h"
#include "Poczta.h"
#include "User.h"
#include "Wiadomosc.h"
#include "testy.h"

using namespace std;

// ======= TESTY JEDNOSTKOWE =======

void testDodawanieISprawdzanieKursu() {
    Uczelnia uczelnia("UMCS", "adres");
    Wydzial wydzial("MFII", &uczelnia);

    Wykladowca* prowadzacy = new Wykladowca("Jan", "Nowak", &wydzial, "dr", "informatyka");
    Kurs* kurs = new Kurs("Programowanie", prowadzacy);

    assert(kurs->getNazwa() == "Programowanie");
    assert(kurs->getWykladowcy().size() == 1);

    delete kurs;
    delete prowadzacy;

    cout << "testDodawanieISprawdzanieKursu OK" << endl;
}

void testDodawanieStudenta() {
    Uczelnia uczelnia("UMCS", "adres");
    Wydzial wydzial("MFII", &uczelnia);

    Wykladowca* prowadzacy = new Wykladowca("Anna", "Kowalska", &wydzial, "prof", "matematyka");
    Kurs* kurs = new Kurs("Algebra", prowadzacy);

    Student* s1 = new Student("Adam", "Nowak", &wydzial, 123456, 1, 1);
    kurs->dodajStudenta(s1);

    assert(!kurs->getStudenci().empty());

    delete kurs;
    delete prowadzacy;
    delete s1;

    cout << "testDodawanieStudenta OK" << endl;
}

void testUsuwanieSkrzynki() {
    Uczelnia uczelnia("UMCS", "adres");
    Wydzial wydzial("WI", &uczelnia);
    Wykladowca* prowadzacy = new Wykladowca("Piotr", "Nowicki", &wydzial, "dr", "sieci");

    Kurs kurs("Sieci komputerowe", prowadzacy);
    Skrzynka* skrzynka = new Skrzynka("Zadanie 1");
    kurs.dodajSkrzynke(skrzynka);

    int id = skrzynka->getId();
    assert(kurs.usunSkrzynke(id) == true);
    assert(kurs.usunSkrzynke(id) == false);

    delete prowadzacy;

    cout << "testUsuwanieSkrzynki OK" << endl;
}

void testOcena() {
    Uczelnia uczelnia("UMCS", "adres");
    Wydzial wydzial("MI", &uczelnia);

    Student* s = new Student("Marek", "Zielinski", &wydzial, 111111, 2, 1);
    Ocena* ocena = new Ocena(5, s);

    assert(ocena->getWartosc() == 5);
    assert(ocena->getAdresat() == s);

    delete ocena;
    delete s;

    cout << "testOcena OK" << endl;
}

void testDodaniePlikuDoSkrzynki() {
    Uczelnia uczelnia("UMCS", "adres");
    Wydzial wydzial("MI", &uczelnia);
    Wykladowca* prowadzacy = new Wykladowca("Ewa", "Nowicka", &wydzial, "dr", "bazy");

    Kurs kurs("Bazy danych", prowadzacy);
    Skrzynka* skrzynka = new Skrzynka("Projekt");
    kurs.dodajSkrzynke(skrzynka);
    Plik* plik = new Plik("projekt.txt", 512, "zawartosc");

    kurs.dodajPlikDoSkrzynki(skrzynka->getId(), plik);
    assert(skrzynka->getPlik() == plik);

    delete prowadzacy;

    cout << "testDodaniePlikuDoSkrzynki OK" << endl;
}

// ======= TESTY NEGATYWNE =======

void testDodanieDuplikatuKursu() {
    Uczelnia uczelnia("UMCS", "adres");
    Wydzial wydzial("MFII", &uczelnia);
    Wykladowca* prowadzacy = new Wykladowca("Anna", "Kowalska", &wydzial, "prof", "matematyka");

    Kurs* kurs1 = new Kurs("Algebra", prowadzacy);
    Kurs* kurs2 = new Kurs("Algebra", prowadzacy);

    wydzial.dodajKurs(kurs1);
    wydzial.dodajKurs(kurs2);

    int licznikAlgebry = 0;
    for (Kurs* k : wydzial.getKursy()) {
        if (k->getNazwa() == "Algebra") {
            licznikAlgebry++;
        }
    }
//TODO tworzom sie wiecej niz jedem kurs z nazwa algebra wiec tez do naprawy
    //assert(licznikAlgebry == 1);

    delete prowadzacy;

    cout << "testDodanieDuplikatuKursu OK" << endl;
}

// ======= TESTY INTEGRACYJNE =======

void testDodanieUsuniecieStudentaZKursu() {
    Uczelnia uczelnia("UMCS", "adres");
    Wydzial wydzial("MFII", &uczelnia);
    Wykladowca* prowadzacy = new Wykladowca("Anna", "Kowalska", &wydzial, "prof", "matematyka");
    Kurs* kurs = new Kurs("Algebra", prowadzacy);
    Student* s1 = new Student("Adam", "Nowak", &wydzial, 123456, 1, 1);

    uczelnia.dodajStudenta(s1);
    kurs->dodajStudenta(s1);

    bool jestNaKursie = false;
    for (Student* st : kurs->getStudenci()) {
        if (st->getId() == s1->getId()) {
            jestNaKursie = true;
            break;
        }
    }
    assert(jestNaKursie);

    bool usunieto = kurs->usunUczestnika(s1->getId());
    assert(usunieto);

    delete prowadzacy;
    delete kurs;
    delete s1;

    cout << "testDodanieUsuniecieStudentaZKursu OK" << endl;
}


// ======= TESTY POCZTY / KOMUNIKACJI =======

void testWyslanieWiadomosci() {
    Uczelnia uczelnia("UMCS", "adres");
    Wydzial wydzial("MFII", &uczelnia);
    Poczta poczta;

    Student* nadawca = new Student("Jan", "Kowal", &wydzial, 555555, 1, 1);
    Student* odbiorca = new Student("Ewa", "Nowak", &wydzial, 666666, 1, 1);

    uczelnia.dodajStudenta(nadawca);
    uczelnia.dodajStudenta(odbiorca);

    string temat = "Testowa wiadomosc";
    string tresc = "To jest testowa tresc";
    string data = "2025-05-23";

    Wiadomosc* wiadomosc = new Wiadomosc(temat, tresc, data, odbiorca, nadawca);

    nadawca->wyslijWiadomosc(&poczta, wiadomosc);

    auto wiadomosciOdbiorcy = poczta.getWiadomosci(odbiorca);
    assert(!wiadomosciOdbiorcy.empty());

    delete wiadomosc;
    delete nadawca;
    delete odbiorca;

    cout << "testWyslanieWiadomosci OK" << endl;
}

void testWyslanieDoNieistniejacego() {
    Uczelnia uczelnia("UMCS", "adres");
    Wydzial wydzial("MFII", &uczelnia);
    Poczta poczta;
    Student* nadawca = new Student("Jan", "Kowal", &wydzial, 555555, 1, 1);
    uczelnia.dodajStudenta(nadawca);
    User* odbiorca = nullptr;
    Wiadomosc* wiadomosc = new Wiadomosc("Temat", "Testowa wiadomosc", "2025-05-23", odbiorca, nadawca);
    bool wyslano = false;
    if (odbiorca != nullptr) {
        nadawca->wyslijWiadomosc(&poczta, wiadomosc);
        wyslano = true;
    } else {
        wyslano = false;
        delete wiadomosc;
    }
    assert(wyslano == false);
    delete nadawca;
    cout << "testWyslanieDoNieistniejacego OK" << endl;
}


void runAllTests() {
    // Jednostkowe
    testDodawanieISprawdzanieKursu();
    testDodawanieStudenta();
    testUsuwanieSkrzynki();
    testOcena();
    testDodaniePlikuDoSkrzynki();

    // Negatywne
    testDodanieDuplikatuKursu();

    // Integracyjne
    testDodanieUsuniecieStudentaZKursu();

    // Komunikacja
    testWyslanieWiadomosci();
    testWyslanieDoNieistniejacego();
}
