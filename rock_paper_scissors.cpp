#include<iostream>
#include<time.h>
using namespace std;

int main() {

	srand((unsigned int)time(NULL));
	int iPlayer, iAi, iWin;

	while (true) {
		cout << "1. 가위" << endl;
		cout << "2. 바위" << endl;
		cout << "3. 보" << endl;
		cout << "메뉴를 선택하세요: ";
		cin >> iPlayer;

		if (iPlayer < 0 || iPlayer > 3) {
			cout << "잘못된 값을 입력하였습니다." << endl;
			continue;
		}

		iAi = rand() % 3 + 1;

		switch (iAi) {
		case 1:
			cout << "AI: 가위" << endl;
			break;
		case 2:
			cout << "AI: 바위" << endl;
			break;
		case 3:
			cout << "AI: 보" << endl;
			break;
		}

		iWin = iPlayer - iAi;
		if (iWin == 1 || iWin == -2) {
			cout << "Player 승리" << endl;
		}
		else if (iWin == 0) {
			cout << "무승부" << endl;
		}
		else {
			cout << "AI 승리" << endl;
		}
		cout << endl;
		cout << "=======================" << endl;
	}
	return 0;
}