#include "RingQueue.h"
#include <iostream>

using namespace std;

struct COMBINATION
{
	char symbol_1;
	char symbol_2;
	char symbol_3;
};

void printSlotMachine();
void rolling(int& balance, int x);
void showBalance(int balance);

int main()
{
	int balance = 10000;
	while (true)
	{
		showBalance(balance);
		int x = 0;
		cout << endl;
		cout << 1 - 500<<"$" << endl << 2 - 1000 << "$" << endl << 3 - 2000 << "$" << endl;
		cin >> x;
		if (x > 0 && x < 4)
		{
			rolling(balance, x);
		}
		showBalance(balance);
	}
}

void showBalance(int balance)
{
	cout << "Balance: " << balance << (char)36;
}

void printSlotMachine()
{
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 7; j++)
		{
			switch (i)
			{
			case 1:
				if (j == 1)cout << (char)218;
				else if (j == 2 || j == 4 || j == 6)cout << (char)196;
				else if (j == 3 || j == 5)cout << (char)194;
				else if (j == 7)cout << (char)191;
				break;
			case 2:
				if (j == 1 || j == 3 || j == 5 || j == 7)cout << (char)179;
				else if (j == 2 || j == 4 || j == 6)cout << " ";
				break;
			case 3:
				if (j == 1)cout << (char)192;
				else if (j == 2 || j == 4 || j == 6)cout << (char)196;
				else if (j == 3 || j == 5)cout << (char)193;
				else if (j == 7)cout << (char)217;
				break;
			}
		}
	}
}

void rolling(int& balance, int x)
{
	srand(time(0));

	RingQueue bandit[3];

	bandit[0].addElem(2);
	bandit[0].addElem(36);
	bandit[0].addElem(65);
	bandit[0].addElem(3);
	bandit[0].addElem(64);

	bandit[2] = bandit[1] = bandit[0];

	int ex_times;

	char comb[3];

	for (int i = 0; i < 3; i++)
	{
		ex_times = rand() % 40;
		for (int j = 0; j < ex_times; j++)
		{
			comb[i] = (char)(bandit[i].extractElem());
		}
	}

	for (int i = 0; i < 3; i++)
	{
		cout << comb[i] << " ";
	}

	if (comb[0] == comb[1] && comb[1] == comb[2])
	{
		cout << "JACKPOT!";
		balance += 5000 * x;
	}
	else if (comb[0] == comb[1] || comb[1] == comb[2] || comb[0] == comb[2])
	{
		cout << "WIN!";
		balance += 500 * x;
	}
	else
	{
		cout << "LOSE!";
		balance -= 500 * x;
	}

	if (balance == 0)
	{
		cout << "Balance is empty!";
		exit(0);
	}
}