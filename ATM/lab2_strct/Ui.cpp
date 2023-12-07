#include <iostream>
#include <string>
#include "ui.h"

using namespace std;

Ui::Ui()
{
}

bool Ui::check_for_digits(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (isdigit(input[i]) == false)
            return false;
    }
    return true;
}

void Ui::print_main_menu()
{

    cout << "       BANCOMAT        \n";
    cout << "=====================\n";
    cout << "1 - Print bills\n";
    cout << "2 - Show transactions\n";
    cout << "3 - Input bills\n";
    cout << "4 - Pay sum\n";
    cout << "5 - Exit\n";
}

void Ui::addbancnote()
{
    int bani = 0, size = 0;
    cout << "What bill do you want to add?" << endl;
    cin >> bani;
    cout << "How many?" << endl;
    cin >> size;
    atm.addBancnota(bani, size);
}

void Ui::afisbancnote()
{
    atm.showFunds();
}

void Ui::afistranzactii()
{
    atm.showTranz();
}

void Ui::achitaresuma()
{
    atm.addTranz();
}

void Ui::start()
{

    while (true)
    {
        print_main_menu();

        string input;
        while (true)
        {
            cout << ">";
            getline(cin, input);
            if (check_for_digits(input) == true)
                if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5")
                    break;
            cout << "Invalid option\n";
        }

        int u_input = stoi(input);

        if (u_input == 1)
        {
            afisbancnote();
        }
        else if (u_input == 2)
        {
            afistranzactii();
        }
        else if (u_input == 3)
        {
            addbancnote();
        }
        else if (u_input == 4)
        {
            achitaresuma();
        }
        else if (u_input == 5)
        {
            break;
        }
     
    }
}

Ui::~Ui() = default;