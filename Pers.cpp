#include "Pers.h"

int Pers::newID = 0;
void Pers::setName(const char* aName) {
	name = new char[strlen(aName) + 1];
	strcpy_s(name, strlen(aName) + 1, aName);
}
int Pers::GetID() const
{
	return ID;
}
Pers::Pers(const char* aName) : ID(++newID), gender(gen::male), mother(nullptr), father(nullptr)
{
	SetName(aName);
}
Pers::Pers(const char* aName, gen agender) : ID(++newID), gender(agender), mother(nullptr), father(nullptr)
{
	SetName(aName);
}
void Pers::Erase() {
	delete[] name;
}
void Pers::Clone(const Pers& p) {
	name = new char[strlen(p.name) + 1];
	strcpy_s(name, strlen(p.name) + 1, p.name);
	father = p.father;
	mother = p.mother;
}
Pers::~Pers() {
	Erase();
}
Pers::	Pers(const Pers& p) : ID(++newID), gender(p.gender) {
	Clone(p);
}
Pers& Pers::operator =(const Pers& p) {
	if (this != &p) {
		Erase();
		Clone(p);
	}
	return *this;
}
/*Pers& Pers::operator = (const Pers& p) {
	if (this == &p) {
		return *this;
	}
	delete[] name;
	name = new char[strlen(p.name) + 1];
	strcpy(name, p.name);
	return *this;
}*/
void Pers::SetName(const char* aname) {
	if (aname == NULL) {
		throw runtime_error("Invalid parametr (NULL)");
	}
	if (aname[0] == '\0') {
		throw runtime_error("Invalid name length");
	}
	name = new char[strlen(aname) + 1];
	strcpy_s(name, strlen(aname) + 1, aname);
}
const char* Pers::GetName() const {
	return name;
}

Pers* Pers::GiveBirth(Pers* father, const char* baby_name, gen baby_gender) {
	if (gender != gen::female) {
		throw logic_error("Mother's gender isn't female");
	}
	if (father != nullptr && father->gender != gen::male) {
		throw logic_error("Father's gender isn't male");
	}
	Pers* baby(new Pers(baby_name, baby_gender));
	baby->father = father;
	baby->mother = this;
}

void Pers::PrintInfo() {
	cout << "Name: " << name << endl;
	cout << "Gender: " << (gender == gen::male ? "male" : "female") << endl;
	cout << "ID: " << ID << endl;
	if (mother != nullptr) {
		cout << "Mother Name: " << mother->name << endl;
	}
	else {
		cout << "This person has no mother" << endl;
	}
	if (father != nullptr) {
		cout << "Father Name: " << father->name << endl;
	}
	else {
		cout << "This person has no father" << endl;
	}
}