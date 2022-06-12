#include<iostream>
#include<time.h>
using namespace std;

int main() {
	srand((unsigned int)time(NULL));

	int BingoNumber[25] = {};
	for (int i = 0; i < 25; i++) {
		BingoNumber[i] = i + 1;
	}
	int temp, dex1, dex2;
	int number, Bingo = 0;
	for (int i = 0; i < 100; i++) {
		dex1 = rand() % 25;
		dex2 = rand() % 25;
		temp = BingoNumber[dex1];
		BingoNumber[dex1] = BingoNumber[dex2];
		BingoNumber[dex2] = temp;
	}

	while (1) {
		system("cls");
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (BingoNumber[i * 5 + j] == 0) {
					cout << "*" << '\t';
				}
				else {
					cout << BingoNumber[i * 5 + j] << '\t';
				}
			}
			cout << endl;
		}
		
		bool left = true, right = true;
		Bingo = 12;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (BingoNumber[i * 5 + j] != 0) {
					Bingo--;
					break;
				}
			}
			for (int j = 0; j < 5; j++) {
				if (BingoNumber[j * 5 + i] != 0) {
					Bingo--;
					break;
				}
			}
			if (left && BingoNumber[i * 6] != 0) {
				Bingo--;
				left = false;
			}
			if (right && BingoNumber[(i+1) * 4] != 0) {
				Bingo--;
				right = false;
			}
		}
		if (Bingo >= 5) {
			break;
		}
		cout << "���� �ϼ��� ������ ��: " << Bingo << endl;
		cout << "1~25 ������ ���ڸ� �Է��ϼ���(����: 0 ): ";
		cin >> number;
		

		if (number < 0 || number >25) {
			cout << "���ڸ� �� �� �Է��Ͽ����ϴ�" << endl;
			continue;
		}
		else {
			for (int i = 0; i < 25; i++) {
				if (number == BingoNumber[i]) {
					BingoNumber[i] = 0;
					break;
				}
			}
		}
	}
	cout << Bingo << "�� ����!!!!" << endl;
	cout << "���� ����Ǿ����ϴ�." << endl;
	return 0;
}