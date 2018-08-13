#pragma once
#include "sqlite3.h"
#include <string>

class Database
{
public:
	Database();
	~Database();

	void Insert(std::string player, int coins, int monsters, int level);
	void Fetch();


};
