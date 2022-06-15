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

		cout << "1. �л����" << '\n';
		cout << "2. �л�����" << '\n';
		cout << "3. �л�Ž��" << '\n';
		cout << "4. �л����" << '\n';
		cout << "5. ����" << '\n';
		cout << "�޴��� �����ϼ���(1 ~ 5):";
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
			cout << "=================== �л��߰� ==================" << '\n';
			
			if (StudentCount == STUDENT_MAX) {
				break;
			}

			cout << "�̸�: ";
			cin >> StudentArr[StudentCount].Name;
			cin.ignore(1024, '\n');
			cout << "�ּ�: ";
			cin.getline(StudentArr[StudentCount].Address, ADDRESS_SIZE);
			cout << "��ȭ��ȣ: ";
			cin >> StudentArr[StudentCount].Number;
			cout << "�й��� �Է��ϼ���: ";
			cin >> StudentArr[StudentCount].PhoneNumber;
			cout << "���������� �Է��ϼ���: ";
			cin >> StudentArr[StudentCount].Korean;
			cout << "���������� �Է��ϼ���: ";
			cin >> StudentArr[StudentCount].English;
			cout << "���������� �Է��ϼ���: ";
			cin >> StudentArr[StudentCount].Math;

			StudentArr[StudentCount].Total = StudentArr[StudentCount].Korean + StudentArr[StudentCount].English + StudentArr[StudentCount].Math;
			StudentArr[StudentCount].avg = StudentArr[StudentCount].Total / 3.f;
			++StudentCount;
			cout << "�л� �߰� �Ϸ�" << '\n';
			break;

		case MENU_DELETE:
			system("cls");
			cout << "=================== �л����� ==================" << '\n';

			cin.ignore(1024, '\n');
			cout << "������ �̸��� �Է��ϼ���: ";
			cin.getline(strName, NAME_SIZE);
			for (int i = 0; i < StudentCount; i++) {
				if (strcmp(StudentArr[i].Name, strName) == 0) {
					for (int j = i; j < StudentCount - 1; j++) {
						StudentArr[i] = StudentArr[i + 1];
					}
					--StudentCount;

					cout << "�л��� �����Ͽ����ϴ�." << '\n';
					break;
				}
			}
			break;
		case MENU_SEARCH:
			system("cls");
			cout << "=================== �л��˻� ==================" << '\n';
			cin.ignore(1024, '\n');
			cout << "Ž���� �̸��� �Է��ϼ���: ";
			cin.getline(strName, NAME_SIZE);
			for (int i = 0; i < StudentCount; i++) {
				if (strcmp(StudentArr[i].Name, strName) == 0){
					cout << "�̸�: " << StudentArr[i].Name << '\n';
					cout << "��ȭ��ȣ: " << StudentArr[i].PhoneNumber << '\n';
					cout << "�ּ�: " << StudentArr[i].Address << '\n';
					cout << "�й�: " << StudentArr[i].Number << '\n';
					cout << "����: " << StudentArr[i].Korean << '\n';
					cout << "����: " << StudentArr[i].English << '\n';
					cout << "����: " << StudentArr[i].Math << '\n';
					cout << "����: " << StudentArr[i].Total << '\n';
					cout << "���: " << StudentArr[i].avg << '\n\n';
					break;
				}
			}
			break;
		case MENU_OUTPUT:
			system("cls");
			cout << "=================== �л���� ==================" << '\n';
			for (int i = 0; i < StudentCount; i++) {
				cout << "�̸�: " << StudentArr[i].Name << '\n';
				cout << "��ȭ��ȣ: " << StudentArr[i].PhoneNumber << '\n';
				cout << "�ּ�: " << StudentArr[i].Address << '\n';
				cout << "�й�: " << StudentArr[i].Number << '\n';
				cout << "����: " << StudentArr[i].Korean << '\n';
				cout << "����: " << StudentArr[i].English << '\n';
				cout << "����: " << StudentArr[i].Math << '\n';
				cout << "����: " << StudentArr[i].Total << '\n';
				cout << "���: " << StudentArr[i].avg << '\n\n';
			}
			break;
		default:
			cout << "�߸� �Է��Ͽ����ϴ�." << '\n';
			break;
		}
		system("pause");
	}
	return 0;
}