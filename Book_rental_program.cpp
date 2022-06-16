#include<iostream>
#include<string>
#define BOOK_MAX 30
using namespace std;

typedef struct Book {
	string BookName;
	int BookPrice;
	int BookNumber;
	bool BookExistence = true;
}Book;

enum MENU {MENU_NONE, MENU_INSERT, MENU_RENT, MENU_RETURN, MENU_OUTPUT, MENU_EXIT};

int main() {

	Book BookArr[BOOK_MAX] = {};
	int BookCount = 0;
	string NameSearch;

	while (1) {
		system("cls");

		cout << "1. 책 등록" << '\n';
		cout << "2. 책 대여" << '\n';
		cout << "3. 책 반납" << '\n';
		cout << "4. 책 목록" << '\n';
		cout << "5. 종료" << '\n';
		cout << "원하는 메뉴를 선택하세요(1~5): ";
		int menu;
		cin >> menu;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (menu == MENU_EXIT) {
			break;
		}

		switch (menu) {
		case MENU_INSERT:
			system("cls");
			cout << "==================== 책 추가 =====================" << '\n';
			if (BookCount == BOOK_MAX) {
				break;
			}
			cin.ignore(1024, '\n');
			cout << "책 이름: ";
			getline(cin, BookArr[BookCount].BookName);
			cout << "책 대여금액: ";
			cin >> BookArr[BookCount].BookPrice;
			cout << "책 번호: ";
			cin >> BookArr[BookCount].BookNumber;

			BookCount++;
			cout << "책 추가 완료" << '\n';

			break;
		case MENU_RENT:
			system("cls");
			cout << "==================== 책 대여 =====================" << '\n';
			cin.ignore(1024, '\n');
			cout << "책 이름: ";
			getline(cin, NameSearch);
			for (int i = 0; i < BookCount; i++) {
				if (BookArr[i].BookName == NameSearch) {
					cout << "책 번호: " << BookArr[i].BookNumber << '\n';
					cout << "책 대여금액: " << BookArr[i].BookPrice << '\n';
					cout << "대여";
					if (BookArr[i].BookExistence == true) {
						cout << "가능" << '\n';
						BookArr[i].BookExistence = false;
					}
					else {
						cout << "불가" << '\n';
					}
					break;
				}
			}
			break;
		case MENU_RETURN:
			system("cls");
			cout << "==================== 책 반납 =====================" << '\n';
			cin.ignore(1024, '\n');
			cout << "책 이름: ";
			getline(cin, NameSearch);
			for (int i = 0; i < BookCount; i++) {
				if (BookArr[i].BookName == NameSearch) {
					BookArr[i].BookExistence = true;
					cout << "책 반납이 완료되었습니다." << endl;
					break;
				}
			}
			break;
		case MENU_OUTPUT:
			system("cls");
			cout << "==================== 책 목록 =====================" << '\n';
			for (int i = 0; i < BookCount; i++) {
				cout << "책 이름: " << BookArr[i].BookName << '\n';
				cout << "책 번호: " << BookArr[i].BookNumber << '\n';
				cout << "책 대여금액: " << BookArr[i].BookPrice << '\n';
				cout << "대여";
				if (BookArr[i].BookExistence == true) {
					cout << "가능" << endl << endl;
				}
				else {
					cout << "불가" << endl << endl;
				}
			}
			break;
		default:
			cout << "잘못 입력하였습니다" << '\n';
			break;
		}
		system("pause");
	}
	return 0;
}