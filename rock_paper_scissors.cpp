#include<iostream>
#include<time.h>
using namespace std;

int main() {

	srand((unsigned int)time(NULL));
	int iPlayer, iAi, iWin;

	while (true) {
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. ��" << endl;
		cout << "�޴��� �����ϼ���: ";
		cin >> iPlayer;

		if (iPlayer < 0 || iPlayer > 3) {
			cout << "�߸��� ���� �Է��Ͽ����ϴ�." << endl;
			continue;
		}

		iAi = rand() % 3 + 1;

		switch (iAi) {
		case 1:
			cout << "AI: ����" << endl;
			break;
		case 2:
			cout << "AI: ����" << endl;
			break;
		case 3:
			cout << "AI: ��" << endl;
			break;
		}

		iWin = iPlayer - iAi;
		if (iWin == 1 || iWin == -2) {
			cout << "Player �¸�" << endl;
		}
		else if (iWin == 0) {
			cout << "���º�" << endl;
		}
		else {
			cout << "AI �¸�" << endl;
		}
		cout << endl;
		cout << "=======================" << endl;
	}
	return 0;
}