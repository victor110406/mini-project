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

		cout << "1. å ���" << '\n';
		cout << "2. å �뿩" << '\n';
		cout << "3. å �ݳ�" << '\n';
		cout << "4. å ���" << '\n';
		cout << "5. ����" << '\n';
		cout << "���ϴ� �޴��� �����ϼ���(1~5): ";
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
			cout << "==================== å �߰� =====================" << '\n';
			if (BookCount == BOOK_MAX) {
				break;
			}
			cin.ignore(1024, '\n');
			cout << "å �̸�: ";
			getline(cin, BookArr[BookCount].BookName);
			cout << "å �뿩�ݾ�: ";
			cin >> BookArr[BookCount].BookPrice;
			cout << "å ��ȣ: ";
			cin >> BookArr[BookCount].BookNumber;

			BookCount++;
			cout << "å �߰� �Ϸ�" << '\n';

			break;
		case MENU_RENT:
			system("cls");
			cout << "==================== å �뿩 =====================" << '\n';
			cin.ignore(1024, '\n');
			cout << "å �̸�: ";
			getline(cin, NameSearch);
			for (int i = 0; i < BookCount; i++) {
				if (BookArr[i].BookName == NameSearch) {
					cout << "å ��ȣ: " << BookArr[i].BookNumber << '\n';
					cout << "å �뿩�ݾ�: " << BookArr[i].BookPrice << '\n';
					cout << "�뿩";
					if (BookArr[i].BookExistence == true) {
						cout << "����" << '\n';
						BookArr[i].BookExistence = false;
					}
					else {
						cout << "�Ұ�" << '\n';
					}
					break;
				}
			}
			break;
		case MENU_RETURN:
			system("cls");
			cout << "==================== å �ݳ� =====================" << '\n';
			cin.ignore(1024, '\n');
			cout << "å �̸�: ";
			getline(cin, NameSearch);
			for (int i = 0; i < BookCount; i++) {
				if (BookArr[i].BookName == NameSearch) {
					BookArr[i].BookExistence = true;
					cout << "å �ݳ��� �Ϸ�Ǿ����ϴ�." << endl;
					break;
				}
			}
			break;
		case MENU_OUTPUT:
			system("cls");
			cout << "==================== å ��� =====================" << '\n';
			for (int i = 0; i < BookCount; i++) {
				cout << "å �̸�: " << BookArr[i].BookName << '\n';
				cout << "å ��ȣ: " << BookArr[i].BookNumber << '\n';
				cout << "å �뿩�ݾ�: " << BookArr[i].BookPrice << '\n';
				cout << "�뿩";
				if (BookArr[i].BookExistence == true) {
					cout << "����" << endl << endl;
				}
				else {
					cout << "�Ұ�" << endl << endl;
				}
			}
			break;
		default:
			cout << "�߸� �Է��Ͽ����ϴ�" << '\n';
			break;
		}
		system("pause");
	}
	return 0;
}