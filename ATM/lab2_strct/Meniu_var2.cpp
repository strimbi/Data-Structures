#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "Meniu_var2.h"
#include "atm.h"

void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

using namespace std;

void Menu2()
{
	int Set[] = { 7, 7, 7, 7, 7 };
	int counter = 1;
	char key;
	Atm atm;

	for (int i = 0;; )
	{
		gotoxy(1, 2);
		color(Set[0]);
		cout << "1 - Show funds";

		gotoxy(1, 3);
		color(Set[1]);
		cout << "2 - Show transactions";

		gotoxy(1, 4);
		color(Set[2]);
		cout << "3 - Input bills";

		gotoxy(1, 5);
		color(Set[3]);
		cout << "4 - Pay sum";

		gotoxy(1, 6);
		color(Set[4]);
		cout << "0 - Exit";

		key = _getch();

		if (key == 72 && (counter >= 2 && counter <= 5))
		{
			counter--;
		}

		if (key == 80 && (counter >= 1 && counter <= 4))
		{
			counter++;
		}

		if (key == 77 || key == 75 || key == 27)
		{
			system("cls");
		}

		if (key == '\r')
		{
			int x = 0;
			cout << '\n';

			if (counter == 1)
			{
				atm.showFunds();
			}

			if (counter == 2)
			{
				atm.showTranz();
			}

			if (counter == 3)
			{
				int bill;
				int size;
				std::cout << "What bill do you want to add? " << std::endl;
				std::cin >> bill;
				std::cout << "How many bills? " << std::endl;
				std::cin >> size;
				atm.addBancnota(bill, size);
			}

			if (counter == 4)
			{
				atm.addTranz();
			}

			if (counter == 5)
			{
				break;
			}

		}

		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7;
		Set[3] = 7;
		Set[4] = 7;

		if (counter == 1)
		{
			Set[0] = 10;
		}
		if (counter == 2)
		{
			Set[1] = 10;
		}
		if (counter == 3)
		{
			Set[2] = 10;
		}
		if (counter == 4)
		{
			Set[3] = 10;
		}
		if (counter == 5)
		{
			Set[4] = 10;
		}
	}

}