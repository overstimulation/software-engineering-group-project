//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Uczelnia.h
//  @ Date : 19.05.2025
//  @ Author :
//
//


#if !defined(_UCZELNIA_H)
#define _UCZELNIA_H

#pragma once
#include <list>
#include <string>
#include <iostream>
using namespace std;

class Wydzial;
class Student;
class Wykladowca;
class User;

class Uczelnia {
public:
	string getNazwa();
	string getEmailNazwa();
	string getAdres();
	list<Wydzial*> getWydzialy();
	list<Student*> getStudenci();
	list<Wykladowca*> getWykladowcy();
    list<User*> getUzytkownicy();
	void dodajWydzial(Wydzial* wydzial);
	void dodajStudenta(Student* student);
	void dodajWykladowce(Wykladowca* wykladowca);
	void usunWydzial(Wydzial* wydzial);
	void usunStudenta(Student* student);
	void usunWykladowce(Wykladowca* wykladowca);
	Uczelnia(string nazwa, string adres);
private:
	string nazwa;
	string adres;
	list<Wydzial*> wydzialy;
	list<Student*> studenci;
	list<Wykladowca*> wykladowcy;
};

#endif  //_UCZELNIA_H
