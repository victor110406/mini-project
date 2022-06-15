#include<iostream>
#include<string>
#define NAME_SIZE 10
#define ADDRESS_SIZE 100
#define PHONE_NUMBER_SIZE 15
#define STUDENT_MAX 30
using namespace std;

typedef struct Student {
	char Name[NAME_SIZE];
	char Address[ADDRESS_SIZE];
	char PhoneNumber[PHONE_NUMBER_SIZE];
	int Number;
	int Korean;
	int English;
	int Math;
	int Total;
	float avg;
}Student;

enum MENU { MENU_NONE, MENU_INSERT, MENU_DELETE, MENU_SEARCH, MENU_OUTPUT, MENU_EXIT};

int main() {
	Student StudentArr[STUDENT_MAX] = {};
	int StudentCount = 0;
	char strName[NAME_SIZE] = {};

	while (1) {
		system("cls");

		cout << "1. 학생등록" << '\n';
		cout << "2. 학생삭제" << '\n';
		cout << "3. 학생탐색" << '\n';
		cout << "4. 학생출력" << '\n';
		cout << "5. 종료" << '\n';
		cout << "메뉴를 선택하세요(1 ~ 5):";
		int Menu;
		cin >> Menu;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (Menu == MENU_EXIT) {
			break;
		}

		switch (Menu) {
		case MENU_INSERT:
			system("cls");
			cout << "=================== 학생추가 ==================" << '\n';
			
			if (StudentCount == STUDENT_MAX) {
				break;
			}

			cout << "이름: ";
			cin >> StudentArr[StudentCount].Name;
			cin.ignore(1024, '\n');
			cout << "주소: ";
			cin.getline(StudentArr[StudentCount].Address, ADDRESS_SIZE);
			cout << "전화번호: ";
			cin >> StudentArr[StudentCount].Number;
			cout << "학번을 입력하세요: ";
			cin >> StudentArr[StudentCount].PhoneNumber;
			cout << "국어점수를 입력하세요: ";
			cin >> StudentArr[StudentCount].Korean;
			cout << "영어점수를 입력하세요: ";
			cin >> StudentArr[StudentCount].English;
			cout << "수학점수를 입력하세요: ";
			cin >> StudentArr[StudentCount].Math;

			StudentArr[StudentCount].Total = StudentArr[StudentCount].Korean + StudentArr[StudentCount].English + StudentArr[StudentCount].Math;
			StudentArr[StudentCount].avg = StudentArr[StudentCount].Total / 3.f;
			++StudentCount;
			cout << "학생 추가 완료" << '\n';
			break;

		case MENU_DELETE:
			system("cls");
			cout << "=================== 학생삭제 ==================" << '\n';

			cin.ignore(1024, '\n');
			cout << "삭제할 이름을 입력하세요: ";
			cin.getline(strName, NAME_SIZE);
			for (int i = 0; i < StudentCount; i++) {
				if (strcmp(StudentArr[i].Name, strName) == 0) {
					for (int j = i; j < StudentCount - 1; j++) {
						StudentArr[i] = StudentArr[i + 1];
					}
					--StudentCount;

					cout << "학생을 삭제하였습니다." << '\n';
					break;
				}
			}
			break;
		case MENU_SEARCH:
			system("cls");
			cout << "=================== 학생검색 ==================" << '\n';
			cin.ignore(1024, '\n');
			cout << "탐색할 이름을 입력하세요: ";
			cin.getline(strName, NAME_SIZE);
			for (int i = 0; i < StudentCount; i++) {
				if (strcmp(StudentArr[i].Name, strName) == 0){
					cout << "이름: " << StudentArr[i].Name << '\n';
					cout << "전화번호: " << StudentArr[i].PhoneNumber << '\n';
					cout << "주소: " << StudentArr[i].Address << '\n';
					cout << "학번: " << StudentArr[i].Number << '\n';
					cout << "국어: " << StudentArr[i].Korean << '\n';
					cout << "영어: " << StudentArr[i].English << '\n';
					cout << "수학: " << StudentArr[i].Math << '\n';
					cout << "총점: " << StudentArr[i].Total << '\n';
					cout << "평균: " << StudentArr[i].avg << '\n\n';
					break;
				}
			}
			break;
		case MENU_OUTPUT:
			system("cls");
			cout << "=================== 학생출력 ==================" << '\n';
			for (int i = 0; i < StudentCount; i++) {
				cout << "이름: " << StudentArr[i].Name << '\n';
				cout << "전화번호: " << StudentArr[i].PhoneNumber << '\n';
				cout << "주소: " << StudentArr[i].Address << '\n';
				cout << "학번: " << StudentArr[i].Number << '\n';
				cout << "국어: " << StudentArr[i].Korean << '\n';
				cout << "영어: " << StudentArr[i].English << '\n';
				cout << "수학: " << StudentArr[i].Math << '\n';
				cout << "총점: " << StudentArr[i].Total << '\n';
				cout << "평균: " << StudentArr[i].avg << '\n\n';
			}
			break;
		default:
			cout << "잘못 입력하였습니다." << '\n';
			break;
		}
		system("pause");
	}
	return 0;
}