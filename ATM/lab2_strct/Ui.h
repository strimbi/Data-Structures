#ifndef UI_H
#define UI_H
#include <iostream>
#include "atm.h"

using namespace std;

class Ui
{
private:
	Atm atm;

public:
	Ui();
	~Ui();

	bool check_for_digits(string input);
	void print_main_menu();
	void addbancnote();
	void afisbancnote();
	void afistranzactii();
	void achitaresuma();
	void start();
};

#endif // !UI_H

