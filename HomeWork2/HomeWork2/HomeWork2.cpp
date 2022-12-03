#include "StructLib.h"
//#include "StructLib.cpp"
#include <iostream>
using namespace std;

void create(Human* man) {
	cout << "Name: ";
	cin >> man->FIO.name;
	cout << endl;
	cout << "Patronymic: ";
	cin >> man->FIO.patronymic;
	cout << endl;
	//...

};

struct Human CreateHuman(){
	Human man;
	cout << "Name: ";
	cin >> man.FIO.name;
	cout << endl;
	cout << "Patronymic: ";
	cin >> man.FIO.patronymic;
	cout << endl;
	//...
	return man;

};

struct Human CreateHumanParametrs(string name,string patronymic) {
	Human man;
	man.FIO.name = name;
    man.FIO.patronymic = patronymic;
	//...
	return man;
};

void CreateStructure(Human* man, string name, string patronymic) {
	man->FIO.name = name;
	man->FIO.patronymic = patronymic;
	//...

};




void main() {
	Initials human1;
	Time DateOfBirth;
	Dimension hauman1Dimension = {178,20,40};
	human1.name = "human name";
	human1.patronymic = "human patronymic";
	human1.surname = "human surname";
	DateOfBirth.day = 1;
	DateOfBirth.DayOfTheWeek = "setedey";
	DateOfBirth.year = 1897;
	BodyParameters human1Body = {87,hauman1Dimension,DateOfBirth,human1 };
	//-------------------------------------------------------------
	//№4
	Human man;
    man.Create = &create;
	man.Create(&man);
	create(&man);

	



};