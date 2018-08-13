#include <stdio.h>
#include <iostream>
#include "sqlite3.h"
#include "Database.h"

Database::Database() {

}

Database::~Database() {

}


sqlite3 *db;
int rc;
char *sql;
char *zErrMsg = 0;
const char* data = "Callback function called";

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for (i = 0; i<argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

static int callback2(void *data, int argc, char **argv, char **azColName) {
	int i;
	fprintf(stderr, "%s: ", (const char*)data);

	for (i = 0; i<argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");
	return 0;
}

void Database::Insert(std::string player, int coins, int monsters, int level)
{
	sqlite3_open("gameDB.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	}
	else {
		fprintf(stderr, "Opened database successfully\n");

		sql = "INSERT INTO Player (playerName, totalCoins, enemyKill, levelsFin) "\
			"VALUES (?, ?, ?, ?)",
			(player, coins, monsters, level);
		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	}
	sqlite3_close(db);
}

void Database::Fetch()
{
	rc = sqlite3_open("gameDB.db", &db);
	

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));		
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}

	/* Create SQL statement */
	sql = "SELECT * from Player";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback2, (void*)data, &zErrMsg);	


	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operation done successfully\n");		
	}
	sqlite3_close(db);
}
