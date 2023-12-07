#include <iostream>
#include "Ui.h"
#include "teste.h"
#include "Meniu_var2.h"

int main()
{
	Ui ui;
	Test teste;
	teste.testAll();
	std::cout << "Tests finished!\n";
	cout << endl;
	//ui.start();
	Menu2();
	return 0;
}