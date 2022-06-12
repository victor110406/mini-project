#include<iostream>
#include<time.h>
#include<conio.h>
using namespace std;

int main() {
	srand((unsigned int)time(NULL));

	int Number[25] = {};
	for (int i = 0; i < 24; i++) {
		Number[i] = i + 1;
	}
	Number[24] = INT_MAX;

	int temp, dx1, dx2;
	int StarIndex = 24;
	for (int i = 0; i < 100; i++) {
		dx1 = rand() % 24;
		dx2 = rand() % 24;
		temp = Number[dx1];
		Number[dx1] = Number[dx2];
		Number[dx2] = temp;
	}

	while (1) {
		system("cls");
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (Number[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				}
				else {
					cout << Number[i * 5 + j] << '\t';
				}
			}
			cout << endl;
		}
		bool bWin = true;
		for (int i = 0; i < 24; i++) {
			if (Number[i] != i + 1) {
				bWin = false;
				break;
			}
		}
		if (bWin) {
			break;
		}
		cout << "W : 위 S : 아래 a : 왼쪽 d : 오른쪽 q : 종료 : ";
		// _getch() 함수는 문자 1개를 입력받는 함수
		// 문자를 누르는 순간 바로 그 문자를 반환
		char cInput = _getch();
		if (cInput == 'q' || cInput == 'Q') {
			break;
		}
		switch (cInput) {
		case 'w':
		case 'W':
			if (StarIndex  < 5) {
				continue;
			}
			Number[StarIndex] = Number[StarIndex - 5];
			Number[StarIndex - 5] = INT_MAX;
			StarIndex -= 5;
			break;
		case 's':
		case 'S':
			if (StarIndex  > 19) {
				continue;
			}
			Number[StarIndex] = Number[StarIndex + 5];
			Number[StarIndex + 5] = INT_MAX;
			StarIndex += 5;
			break;
		case 'a':
		case 'A':
			if ((StarIndex % 5) != 0) {
				Number[StarIndex] = Number[StarIndex - 1];
				Number[StarIndex - 1] = INT_MAX;
				StarIndex--;
			}
			break;
		case 'd':
		case 'D':
			if ((StarIndex % 5) != 4) {
				Number[StarIndex] = Number[StarIndex + 1];
				Number[StarIndex + 1] = INT_MAX;
				StarIndex++;
			}
			break;
		}
	}
	cout << endl << "게임을 종료합니다." << endl;

	return 0;
}