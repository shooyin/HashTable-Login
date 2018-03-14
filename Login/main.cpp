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
	string choice;
	bool lock = true;

	cout << "Apple Bottom Jeans\n\n";
	cout << "(1) Login\n";
	cout << "(2) Create Account\n";
	cout << "(3) Forgot Password\n";
	cout << "(4) Exit\n\n";

	while (lock == true) {
		cout << "Choice: ";
		cin >> choice;

		if (choice == "1" || choice == "login" || choice == "Login") {
			lock = false;
			system("cls");
			showLoginScreen(hashy);
		}
		else if (choice == "2" || choice == "Create Account") {
			lock = false;
			system("cls");
			showCreateAccountScreen(hashy);
		}
		else if (choice == "3" || choice == "Forgot Password") {
			lock = false;
			system("cls");
			showForgotPasswordScreen(hashy);
		}
		else if (choice == "4" || choice == "exit") {
			lock = false;
			cout << "\nGoodbye!\n" << endl;
			system("exit");
		}
		else if (choice == "5" || choice == "debug") {
			lock = false;
			system("cls");
			showAdminScreen(hashy);
		}
		else {
			lock = false;
			system("cls");
			showOpeningScreen(hashy);
		}
	}
}

void showLoginScreen(hashi hashy) {
	string username, password;

	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;

	if (hashy.confirmUser(username, password) == true) {
		cout << "Passed" << endl;
	}

	system("pause");
	system("cls");
	showOpeningScreen(hashy);
}

void showCreateAccountScreen(hashi hashy) {
	string username, password;

	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;

	hashy.addUser(username, password);
	hashy.addToTextFile(username, password);
	cout << "\n\n" << username << " was successfully created" << endl;
	system("cls");
	showLoginScreen(hashy);
}

void showForgotPasswordScreen(hashi hashy) {
	string username;

	while (username != "exit") {
		cout << "Search: ";
		cin >> username;

		if (username != "exit")
			hashy.findPassword(username);
	}
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
