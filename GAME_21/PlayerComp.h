#pragma once
#include <iostream>
#include <random>

using namespace std;

// рандомная выдача карт. Начало
int random_issuance_of_cards() {
	int random_card;
	random_device rd;   // non-deterministic generator
	mt19937 gen(rd());  // to seed mersenne twister.
	uniform_int_distribution<> dist(2, 11);
	random_card = dist(gen);
	while (random_card == 5) {
		mt19937 gen(rd());

		uniform_int_distribution<> dist(2, 11);
		random_card = dist(gen);
	}
	return random_card;
}

// учет повторяющихся карт
int check_cards() {
	int arrayRepeatCards[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 }; // кол-во повторов
	int random_card = random_issuance_of_cards();
	do {
		if (arrayRepeatCards[random_card] > 4)
			random_card = random_issuance_of_cards();
		else {
			arrayRepeatCards[random_card]++;
			return random_card;
		}
	} while (true);
}
//рандомная выдача карт. Конец


//ход игрока
int player_turn() {
	return check_cards();
}

//ход компьютера
int computer_turn() {
	int summa = 0;
	summa += check_cards();
	summa += check_cards();
	srand(time(NULL));
	int a, b, c;
	a = rand() % 2; // 50%
	b = rand() % 4; // 25%
	c = rand() % 10;// 10%
	while (summa <= 21)
	{
		if (summa < 11) summa += check_cards();
		else if (10 < summa && summa < 14) {
			if (b == 3) summa += check_cards();
			else break;
		}
		else if (13 < summa && summa < 16) {
			if (a) summa += check_cards();
			else break;
		}
		else if (15 < summa && summa < 18) {
			if (b == 3) summa += check_cards();
			else break;
		}
		else if (17 < summa && summa < 20) {
			if (c == 9) summa += check_cards();
			else break;
		}
	}
	return summa;
}

//условия выйгрыша
bool win(int summa_user, int summa_comp) {
	cout << "Сумма очков компьютера - " << summa_comp << endl;
	cout << "Ваша итоговая сумма - " << summa_user << endl;
	if (summa_user == 21) cout << "Победа игрока\n";
	else if (summa_user > 21) cout << "Победа компьютера\n";
	else if (summa_comp > 21) cout << "Победа игрока\n";
	else if (summa_user == summa_comp) cout << "Ничья\n";
	else if (summa_user > summa_comp) cout << "Победа игрока\n";
	else if (summa_user < summa_comp) cout << "Победа компьютера\n";
	else if (summa_user == summa_comp) cout << "Ничья\n";

	return false;
}
