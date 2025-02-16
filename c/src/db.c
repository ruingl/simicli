#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include <stdio.h>

char *read_database() {
    FILE *file = fopen("database.json", "r");
    if (!file) return NULL;

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    rewind(file);

    char *json_data = malloc(length + 1);
    if (!json_data) {
        fclose(file);
        return NULL;
    }

    if (fread(json_data, 1, length, file) != (size_t)length) {
        free(json_data);
        fclose(file);
        return NULL;
    }

    json_data[length] = '\0';
    fclose(file);
    return json_data;
}

void seed_database() {
    FILE *file = fopen("database.json", "w");
    if (!file) return;

    cJSON *json = cJSON_CreateObject();
    char *json_str = cJSON_PrintUnformatted(json);
    if (json_str) {
        fprintf(file, "%s", json_str);
        free(json_str);
    }

    fclose(file);
    cJSON_Delete(json);
}

cJSON *init_database() {
    char *json_data = read_database();
    if (!json_data) {
        seed_database();
        json_data = read_database();
        if (!json_data) return cJSON_CreateObject();
    }

    cJSON *json = cJSON_Parse(json_data);
    free(json_data);

    return json ? json : cJSON_CreateObject();
}

char *get_response(const char *query) {
    cJSON *json = init_database();
    if (!json) return NULL;
    if (!query) {
        cJSON_Delete(json);
        return strdup("Invalid query.");
    }

    cJSON *response = cJSON_GetObjectItemCaseSensitive(json, query);

    char *result;
    if (cJSON_IsString(response)) {
        result = strdup(response->valuestring);
    } else {
        result = strdup("I dont know that one.");
    }

    cJSON_Delete(json);
    return result;
}

int add_response(const char *query, const char *response) {
    cJSON *json = init_database();
    if (!json) return 0;

    cJSON *new_response = cJSON_CreateString(response);
    if (!new_response) {
        cJSON_Delete(json);
        return 0;
    }

    cJSON *existing = cJSON_GetObjectItemCaseSensitive(json, query);
    if (existing) {
        cJSON_ReplaceItemInObjectCaseSensitive(json, query, new_response);
    } else {
        cJSON_AddItemToObject(json, query, new_response);
    }

    FILE *file = fopen("database.json", "w");
    if (!file) return 0;

    char *json_str = cJSON_PrintUnformatted(json);
    fprintf(file, "%s", json_str);
    fclose(file);

    free(json_str);
    cJSON_Delete(json);

    return 1;
}
