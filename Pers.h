#pragma once
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

enum class gen { male, female };

class Pers {
private:
	static int newID;
	const int ID;
	char* name;
	const gen gender;
	Pers* mother;
	Pers* father;
	void Erase();
	void Clone(const Pers&);
public:
	Pers& operator =(const Pers&);
	void setName(const char* aName);
	int GetID() const;
	Pers(const Pers&);//конструктор копирования получает константную ссылку на объект данного типа
	Pers(const char*);
	Pers(const char*, gen agender);
	//конструктор, в который передается имя
	~Pers();//destructure
	void SetName(const char*);
	const char* GetName() const;
	Pers* GiveBirth(Pers* father, const char* baby_name, gen baby_gender);
	void PrintInfo();
};

