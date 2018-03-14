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

	cout << "Apple Bottom Jeans\n\n";
	cout << "(1) Login\n";
	cout << "(2) Create Account\n";
	cout << "(3) Forgot Password\n";
	cout << "(4) Exit\n\n";
	cout << "Choice: ";
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

	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;

	if (hashy.confirmUser(username, password) == true) {
		/*
		This is where you put your code in Tran,
		replace this area and the comment with the start
		of the Database menu
		  */
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

	if (hashy.hasDuplicate(username)) {
		cout << "\n\n" << username << " already exists" << endl;
	}
	else {
		hashy.addUser(username, password);
		hashy.addToTextFile(username, password);
		cout << "\n\n" << username << " was successfully created" << endl;
	}
	system("pause");
	system("cls");
	showOpeningScreen(hashy);
}

void showForgotPasswordScreen(hashi hashy) {
	string username;

	cout << "Forgot Your Password?\n\n";

	while (username != "exit") {
		cout << "Search: ";
		cin >> username;

		if (username != "exit")
			hashy.findPassword(username);
		system("pause");
		system("cls");
		showForgotPasswordScreen(hashy);
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
