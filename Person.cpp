#include <iostream>
#include "pers.h"
#include <string>

using namespace std;
int main()
{
	Pers* Adam(new Pers("Adam", gen::male));
	Pers* Eva(new Pers("Eva", gen::female));
	Pers* Kain(Eva->GiveBirth(Adam, "Kain", gen::male));
	Pers* Sif(Eva->GiveBirth(nullptr, "Sif", gen::male));
	Pers* Ksenia(Eva->GiveBirth(Adam, "Ksenia", gen::female));
	Pers* Andrey(Eva->GiveBirth(Adam, "Andrey", gen::male));
	Pers* Vasilisa(Ksenia->GiveBirth(Andrey, "Vasilisa", gen::female));
	Pers* Anatoly(Ksenia->GiveBirth(Andrey, "Anatoly", gen::male));
	Vasilisa->PrintInfo();
	Kain->PrintInfo();
	Sif->PrintInfo();
	return 0;
}
