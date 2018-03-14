#pragma once
#include <iostream>
#include <string>



class hashi {
private:
	static const int TABLE_SIZE = 4;

	struct user {
		std::string username;
		std::string password;
		user* next;
	};

	user* HashTable[TABLE_SIZE];

public:
	hashi();
	int Hash(std::string Key);
	void loadDatabase();
	void addUser(std::string username, std::string password);
	void addToTextFile(std::string username, std::string password);
	bool confirmUser(std::string username, std::string password);
	int numberOfUsersInIndex(int index);
	void printTable();
	void printUsersInIndex(int index);
	void findPassword(std::string username);
	void removeUser(std::string username);
	void removeFromTextFile(std::string username, std::string password);
};