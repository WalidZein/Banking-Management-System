#pragma once
#include <string>
#include <vector>
#include"json_map.h"
#include"Datamanagement.h"


class User 
{
private:
	std::string id;
	int balance[3];
	struct json_map* transactions;
	struct json_map* userData;
	datamanagement* database;

public:
	User(datamanagement *database, std::string id);
	std::vector<std::string> getTransactions();
	void deposit(double amount);
	void withdraw(double amount);
	void setTransactions(std::string data, std::string type, std::string, std::string amount);
	
	


};