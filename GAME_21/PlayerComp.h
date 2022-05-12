#pragma once
#include <iostream>
#include <random>

using namespace std;

// ��������� ������ ����. ������
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

// ���� ������������� ����
int check_cards() {
	int arrayRepeatCards[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 }; // ���-�� ��������
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
//��������� ������ ����. �����


//��� ������
int player_turn() {
	return check_cards();
}

//��� ����������
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

//������� ��������
bool win(int summa_user, int summa_comp) {
	cout << "����� ����� ���������� - " << summa_comp << endl;
	cout << "���� �������� ����� - " << summa_user << endl;
	if (summa_user == 21) cout << "������ ������\n";
	else if (summa_user > 21) cout << "������ ����������\n";
	else if (summa_comp > 21) cout << "������ ������\n";
	else if (summa_user == summa_comp) cout << "�����\n";
	else if (summa_user > summa_comp) cout << "������ ������\n";
	else if (summa_user < summa_comp) cout << "������ ����������\n";
	else if (summa_user == summa_comp) cout << "�����\n";

	return false;
}
