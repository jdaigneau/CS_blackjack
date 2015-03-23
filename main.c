#include <iostream>
#include <ctime>
#include <Windows.h>
#include <vector>
#include "card.h"
#include <stdio.h>
#include "blackjack.h"

using namespace std;

int main() {
	int y;
	bool loop = true;
	int again;

	do
	{
		system("cls");
		gotoxy(0, 0);
		cout << "Input number of players:";
		cin >> y;
		system("cls");
		Game t(y);
		gotoxy(0, 4);
		cout << ">>";
		//t[0].setcard (1, t[0].get_card (0));
		t.gameHand();
		for (int i = 0; i < y; i++) {
			t.betTurn();
			t.gameHand();
		}
		for (int i = 0; i < y; i++) {
			t.hitTurn();
			t.gameHand();
		}
		t.calcWinner();

		gotoxy(0, 20);
		cout << "Would you like to play again? 1 for yes 0 for no." << endl;
		cin >> again;

		if (again == 0)
			loop = false;

	} while (loop);

	gotoxy(0, 23);
	return 0;
}
