#include<iostream>
#include<time.h>
using namespace std;

int main() {
	srand((unsigned int)time(NULL));

	int iNumber[9] = {};

	for (int i = 0; i < 9; i++) {
		iNumber[i] = i + 1;
	}

	int Temp, idx1, idx2;
	for (int i = 0; i < 100; i++) {
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		Temp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = Temp;
	}

	int iStrike = 0, iBall = 0, count = 0;
	int input[3] = {};

	while (1) {
		cout << count << "�õ�" << endl;
		cout << "1~9������ ������ ���� 3���� �Է��ϼ���(0: ����): ";
		cin >> input[0] >> input[1] >> input[2];

		if (input[0] == 0 || input[1] == 0 || input[2] == 0) {
			break;
		}
		else if (input[0] < 0 || input[0]>9 || input[1] < 0 || input[1]>9 || input[2] < 0 || input[2]>9) {
			cout << "�߸��� ���ڸ� �Է��Ͽ����ϴ�." << endl;
			continue;
		}
		else if (input[0] == input[1] || input[1] == input[2] || input[0] == input[2]) {
			cout << "�ߺ��� ���ڸ� �Է��Ͽ����ϴ�." << endl;
			continue;
		}
		iStrike = iBall = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (iNumber[i] == input[j]) {
					if (i == j) {
						iStrike++;
					}
					else {
						iBall++;
					}
					break;
				}
			}
		}
		if (iStrike == 3) {
			cout << "���ڸ� ��� ������ϴ�." << endl;
			break;
		}
		else if (iStrike == 0 && iBall == 0) {
			cout << "OUT" << endl;
		}
		else {
			cout << "strike :" << iStrike << " ball :" << iBall << endl;
		}
		count++;
		cout << "=======================================================" << endl << endl;
	}
	return 0;
}
