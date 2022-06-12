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
		cout << count << "시도" << endl;
		cout << "1~9사이의 숫자중 숫자 3개를 입력하세요(0: 종료): ";
		cin >> input[0] >> input[1] >> input[2];

		if (input[0] == 0 || input[1] == 0 || input[2] == 0) {
			break;
		}
		else if (input[0] < 0 || input[0]>9 || input[1] < 0 || input[1]>9 || input[2] < 0 || input[2]>9) {
			cout << "잘못된 숫자를 입력하였습니다." << endl;
			continue;
		}
		else if (input[0] == input[1] || input[1] == input[2] || input[0] == input[2]) {
			cout << "중복된 숫자를 입력하였습니다." << endl;
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
			cout << "숫자를 모두 맞췄습니다." << endl;
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
