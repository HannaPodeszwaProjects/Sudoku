#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h> 
#include <windows.h>
#include <cstdio>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include "Stan.h"
#include "Ogolne.h"
#include "Pole.h"
#include "Plansza.h"
#include "Rozwiaz.h"
#include "Wynik.h"
#include "Wygrana.h"

using namespace std;

state Stan::do_menu(void)
{
	czas = 0;
	daj_kolor(15);
	
	wypisz_menu();
	cout << "1.GRAJ" << endl;
	cout << "2.WYNIKI" << endl;
	cout << "0.WYJSCIE" << endl;
	char wybor = '-1';
	fseek(stdin, 0, SEEK_END); //usuniecie dodatkowych znakow z bufora
	cin >> wybor;
	switch (wybor)
	{
	case '0':
		return STOP;
	case '1':
	{
		czas = 0;
		return GRA;
	}
	case '2':
		return WYNIK;
	case'h':
	{
		return HELP;
	}

	default:
	{
		cout << "Niepoprawna wartosc." << endl;
		system("pause");
		return MENU;
	}
	}
}

void wypisz_menu()
{
	system("cls"); //czyszczenie konsoli
	ustaw_kursor(0, 0);
	daj_kolor(15);
	cout << endl << endl;
	cout << "*******************" << endl;
	cout << "*     SUDOKU      *" << endl;
	cout << "*******************" << endl << endl;
}

void Pole::wypisz()
{
	if (wartosc == -1) //gdy pole puste
		cout << " ";
	else if (z_pliku == true)
	{
		daj_kolor(3); //zmiana koloru na niebieski
		cout << wartosc;
	}
	else
		cout << wartosc;
	daj_kolor(15); //zmiana koloru na bialy
}

void Plansza::wypisz_plansze()
{
	COORD c;
	c.X = 0;
	c.Y = 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c); //ustawenie kursora
	cout << "浜様僕様僕様僕様僕様僕様僕様僕様僕様�\n";
	for (int i = 0;i < 9;i++)
	{
		cout << "�";
		for (int j = 0;j < 9;j++)
		{

			cout << " ";
			tab[i][j].wypisz(); //wypisanie wartosci
			if (j % 3 == 2)
				cout << " �";
			else
				cout << " �";
		}

		cout << endl;
		if (i != 8)
		{
			if (i % 3 == 2)
			{
				cout << "麺様陵様陵様陵様陵様陵様陵様陵様陵様�\n";
			}
			else
				cout << "鳴陳田陳田陳猟陳田陳田陳猟陳田陳田陳�\n";
		}
		else
			cout << "藩様瞥様瞥様瞥様瞥様瞥様瞥様瞥様瞥様�\n";
	}

}
