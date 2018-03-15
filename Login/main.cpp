#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "hashi.h"

using namespace std;

void showOpeningScreen(hashi hashy);
void showLoginScreen(hashi hashy);
void showCreateAccountScreen(hashi hashy);
void showForgotPasswordScreen(hashi hashy);
void showAdminScreen(hashi hashy);

int main() {
	hashi hashy;

	showOpeningScreen(hashy);

	system("pause");
	return 0;
}

void showOpeningScreen(hashi hashy) {
	char choice = ' ';
	bool lock = true;

	cout << "\t\t   ****** Welcome To Apple Bottom Jeans ****** \n";
	cout << "\n\n\t\t   Please Select From The Following Menu ";
	cout << "\n\n\t\t\t(1) Login\n";
	cout << "\n\n\t\t\t(2) Create Account\n";
	cout << "\n\n\t\t\t(3) Forgot Password?\n";
	cout << "\n\n\t\t\t(4) Exit\n\n";
	cout << "\n\n\t\t\tChoice: ";
	cin >> choice;

	switch (choice) {
	case '1': system("cls");
		showLoginScreen(hashy);
		break;
	case '2': system("cls");
		showCreateAccountScreen(hashy);
		break;
	case '3': system("cls");
		showForgotPasswordScreen(hashy);
		break;
	case '4': cout << "\nGoodbye!\n" << endl;
		system("exit");
		break;
	case '5': system("cls");
		showAdminScreen(hashy);
		break;
	default:  system("cls");
		showOpeningScreen(hashy);
	}
}

void showLoginScreen(hashi hashy) {
	string username, password;

	cout << "\t\t   ****** Login ****** \n";
	cout << "\n\n\t\tUsername: ";
	cin >> username;
	cout << "\n\n\t\tPassword: ";
	cin >> password;
	cout << "\n\t\t";
	if (hashy.confirmUser(username, password) == true) {
		cout << "\n\t\tPassed" << endl;
	}

	system("pause");
	system("cls");
	showOpeningScreen(hashy);
}

void showCreateAccountScreen(hashi hashy) {
	string username, password;

	cout << "\t\t   ****** Create Account ****** \n";
	cout << "\n\n\t\t\tUsername: ";
	cin >> username;
	cout << "\n\n\t\t\tPassword: ";
	cin >> password;

	if (hashy.hasDuplicate(username)) {
		cout << "\n\n\t\t\t" << username << " already exists" << endl;
	}
	else {
		hashy.addUser(username, password);
		hashy.addToTextFile(username, password);
		cout << "\n\n\t\t\t" << username << " was successfully created" << endl;
	}
	system("pause");
	system("cls");
	showOpeningScreen(hashy);
}

void showForgotPasswordScreen(hashi hashy) {
	string username;

	cout << "\t\tForgot Your Password?\n\n";

	while (username != "exit") {
		cout << "\n\t\tSearch: ";
		cin >> username;

		if (username != "exit") {
			cout << "\t\t";
			hashy.findPassword(username);
		}
		cout << endl;
	}
	system("pause");
	system("cls");
	showOpeningScreen(hashy);
}

/*
1 - Print Table
2 - Remove User
3 - Back to Main Menu
*/
void showAdminScreen(hashi hashy) {
	bool lock = true;
	int choice = 0;
	string username, password;
	cout << "\t\t   ****** DEBUG ****** \n";
	cout << "1. Print Table\n";
	cout << "2. Remove User\n";
	cout << "3. Return to Main Menu\n";

	while (lock == true) {
		cin >> choice;

		if (choice == 1) {
			lock = false;
			hashy.printTable();
			system("pause");
			system("cls");
			showAdminScreen(hashy);
		}
		else if (choice == 2) {
			lock = false;
			cout << "Remove Username: ";
			cin >> username;
			cout << "Confirm Password: ";
			cin >> password;
			hashy.removeUser(username);
			hashy.removeFromTextFile(username, password);
			system("pause");
			system("cls");
			showAdminScreen(hashy);
		}
		else if (choice == 3) {
			lock = false;
			system("cls");
			showOpeningScreen(hashy);
		}
	}
}
