#include <iostream>
using namespace std;
struct Dimension {
	int height;
	int depth;
	int width;
};

struct Book {
	string PublishingHouse;
	string authors;
	string name;
	int VendorCode;
	int YearOfPublication;
	int NumberOfPages;
};

struct BGUK {
	int carbohydrates;
	int proteins;
	int fats;
	float calories;
};

struct Initials {
	string surname;
	string patronymic;
	string name;
};

struct Notebook {
	string color;
	Initials owner;
	string name;
	int VendorCode;
	int YearOfPublication;
	int weight;
};

struct Time {
	int year;
	int month;
	int day;
	int week;
	string DayOfTheWeek;
	int hour;
	int minute;
	int second;

};

struct Jeans {
	string color;
	int VendorCode;
	int size;
	int weight;

};

struct Television {
	int weight;
	int diagonal;
	Dimension dimensions;
	Time Publication;

};

struct BodyParameters {
	int heft;
	Dimension dimensions;
	Time TimeOfBirth;
	Initials FIO;
	string EyeColor;
	void (*Create)();
};

struct Human {
	Initials FIO;
	Time TimeOfBirth;
	void (*Create)(Human* man);
};

