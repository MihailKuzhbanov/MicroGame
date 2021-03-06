// MicroGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;



int main()
{
	
	string a="\n0.Chernaya\t10%\t3.0\n1.Belaya\t20%\t2.0\n2.Seraya\t15%\t2.5\n3.Ultra Black\t5%\t4.0\n4.Ultra White\t25%\t1.5\n";
	float horsesAvard[5] = {3.0,2.0,2.5,4.0,1.5};
	int horsesChance[5] = {10,20,15,5,25};
	int pts = 100;
	int horse = 0;
	int bet = 0;
	
	while (pts > 0)
	{
		cout << "You balance: " << pts << "\nSelect horse \n\t\tWin \tAvards" << endl;
		cout << a;
		while (!(cin >> horse) || horse > 5)
		{
			cin.clear();
			while (cin.get() != '\n') continue;
			cout << "Invalid Value! " << endl;
		}
		cout << "Enter your bet" << endl;
		while (!(cin >> bet) || bet > pts)
		{
			cin.clear();
			while (cin.get() != '\n') continue;
			cout << "Invalid Value! " << endl;
		}
		
		cout << "Bets ready, horses are running, waiting for results\n";
		Sleep(1000);
		for (int i = 0; i < 10; i++)
		{
			cout << ".";
			Sleep(500);
		}
		cout << "\n";
		if (rand() % 100 + 1 <= horsesChance[horse])
		{
			pts += (int)(horsesAvard[horse] * bet);
			cout << "Your horse won, you earn " << (int)(horsesAvard[horse] * bet) << " pts" << endl;
		}
		else
		{
			pts -= (int)(horsesAvard[horse] * bet);
			cout << "Your horse lose, you waste " << (int)(horsesAvard[horse] * bet) << " pts" << endl;
		}
	}
	system("pause");
    return 0;
}

