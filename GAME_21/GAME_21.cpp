#include <iostream>
#include <Windows.h>
#include "PlayerComp.h"


using namespace std;
// game 21
void main_menu();
void step_game(int cards_first, int cards_next);
int random_issuance_of_cards();
int check_cards();
int player_turn();
int computer_turn();
bool win(int summa_user, int summa_comp);
void cards_show(int card);

int main()
{
	setlocale(LC_ALL, "");
	int first_card = check_cards(), second_card = check_cards();
	main_menu();
	step_game(first_card, second_card);

}

// интерфейс игры. Начало
void main_menu() {
	cout << "Добро пожаловать в игру 21!\n";
	cout << "Хотите начать? (y/n)\n";
	string flag;
	cin >> flag;

}

// Вывод самих карт
void cards_show(int card) {
	string six = "********\n"
		"* 6    *\n"
		"*      *\n"
		"*      *\n"
		"*      *\n"
		"*    9 *\n"
		"********\n";
	string seven = "********\n"
		"* 7    *\n"
		"*      *\n"
		"*      *\n"
		"*      *\n"
		"*    7 *\n"
		"********\n";
	string eight = "********\n"
		"* 8    *\n"
		"*      *\n"
		"*      *\n"
		"*      *\n"
		"*    8 *\n"
		"********\n";
	string nine = "********\n"
		"* 9    *\n"
		"*      *\n"
		"*      *\n"
		"*      *\n"
		"*    6 *\n"
		"********\n";
	string ten = "********\n"
		"* 10   *\n"
		"*      *\n"
		"*      *\n"
		"*      *\n"
		"*   10 *\n"
		"********\n";
	string valet = "********\n"
		"*  *** *\n"
		"*   ** *\n"
		"* **** *\n"
		"*  *** *\n"
		"*valet *\n"
		"********\n";
	string queen = "********\n"
		"* **** *\n"
		"*  *** *\n"
		"* **** *\n"
		"*  *** *\n"
		"*queen *\n"
		"********\n";
	string king = "********\n"
		"* ** * *\n"
		"*   ** *\n"
		"* **** *\n"
		"*  *** *\n"
		"* king *\n"
		"********\n";
	string tuz = "********\n"
		"* **** *\n"
		"*      *\n"
		"*   *  *\n"
		"*      *\n"
		"* **** *\n"
		"********\n";
	switch (card) {
	case(2):
		cout << valet;
		break;
	case(3):
		cout << queen;
		break;
	case(4):
		cout << king;
		break;
	case(6):
		cout << six;
		break;
	case(7):
		cout << seven;
		break;
	case(8):
		cout << eight;
		break;
	case(9):
		cout << nine;
		break;
	case(10):
		cout << ten;
		break;
	case(11):
		cout << tuz;
		break;
	default:
		break;

	}

}
void step_game(int cards_first, int cards_next) {
	string flag;
	int extra_card; // дополнительная карта
	bool f = true;
	int summa_user = cards_first + cards_next, summa_comp = 0;
	cout << "Ваши карты: " << cards_first << "," << cards_next << endl;
	cards_show(cards_first);
	cards_show(cards_next);
	cout << "Итоговая сумма: " << cards_first + cards_next << endl;
	while (f) {
		cout << "Хотите взять еще одну карту?(y/n)\n";
		cin >> flag;
		if (flag == "y") {
			extra_card = player_turn();
			summa_user += extra_card;
			cout << "Ваша карта: " << extra_card << endl;
			cards_show(extra_card);
			cout << "Итоговая сумма: " << summa_user << endl;
			if (summa_user > 21) {
				//summa_comp += computer_turn();
				f = win(summa_user, summa_comp);
				continue;
			}
			else if (summa_user == 21) {
				summa_comp += computer_turn();
				f = win(summa_user, summa_comp);
				continue;
			}
		}
		else if (flag == "n") {
			summa_comp += computer_turn();
			f = win(summa_user, summa_comp);
			continue;
		}
		else
		{
			cout << "Неверный ввод, повторите!";
		}
	}
}
// интерфейс игры. Конец


