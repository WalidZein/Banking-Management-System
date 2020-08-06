#include "Header/User.h"


User::User(datamanagement *database, std::string id) {
	id = id;
	this -> database = database;
	userData = std::any_cast<struct json_map*>(database->findValue(id)[0]);
	transactions = std::any_cast<struct json_map*> (database->getValue("0", "accountinfo", "transactions"));
	balance[0] =100;
	balance[1] = 100;
	balance[2] = 100;

	

}