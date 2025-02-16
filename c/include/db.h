#ifndef DB_H
#define DB_H

#include "cJSON.h"

char *read_database(void);
void seed_database(void);
cJSON *init_database(void);
char *get_response(char *query);
int add_response(char *query, const char *response);

#endif // DB_H
