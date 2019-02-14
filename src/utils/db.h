#ifndef OIDC_DB_H
#define OIDC_DB_H

#include "utils/listUtils.h"

#include <time.h>

typedef unsigned short db_name;
#define OIDC_DB_CONNECTIONS 1
#define OIDC_DB_ACCOUNTS 2
#define OIDC_DB_PASSWORDS 3
#define OIDC_DB_CODEVERIFIERS 4

void    db_newDB(const db_name db);
list_t* db_getDB(const db_name db);
void    db_setMatchFunction(const db_name db, matchFunction match);
void    db_setFreeFunction(const db_name db, void (*free_fn)(void*));
void    db_removeIfFound(const db_name db, void* value);
void    db_addValue(const db_name db, void* value);
size_t  db_getSize(const db_name db);
void*   db_findValue(const db_name db, void* key);
void    db_reset(const db_name db);
time_t  db_getMinDeath(const db_name db, time_t (*deathGetter)(void*));
void*   db_getDeathEntry(const db_name db, time_t (*deathGetter)(void*));

#endif  // OIDC_DB_H
