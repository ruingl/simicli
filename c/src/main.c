#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "bprint.h"
#include "db.h"

void simi();
void teach();
void ask();

void simi() {
    while (1) {
        system("clear");
        bprint("Simsimi");
        printf("\nWelcome! What would you like?\n\n");
        printf("1. Teach Simi\n");
        printf("2. Ask Simi\n");
        printf("3. Exit\n\n");
        printf("$: ");

        char input[3];
        if (fgets(input, sizeof(input), stdin)) {
            input[strcspn(input, "\n")] = '\0';
        }
        printf("\n");

        if (strcmp(input, "1") == 0) {
            teach();
        } else if (strcmp(input, "2") == 0) {
            ask();
        } else if (strcmp(input, "3") == 0) {
            printf("Goodbye\n");
            break;
        } else {
            printf("Invalid input.\n");
            sleep(1);
        }
    }
}

void teach() {
    while (1) {
        system("clear");
        bprint("Teach");
        printf("\n");

        char query[100], response[100];

        printf("Query: ");
        if (fgets(query, sizeof(query), stdin)) {
            query[strcspn(query, "\n")] = '\0';
        }
        printf("\n");

        printf("Response: ");
        if (fgets(response, sizeof(response), stdin)) {
            response[strcspn(response, "\n")] = '\0';
        }
        printf("\n");

        if (add_response(query, response) == 1) {
            printf("Teached simi! Would you like to continue? (y/n)\n\n");
            printf("$: ");

            char action[3];
            if (fgets(action, sizeof(action), stdin)) {
                action[strcspn(action, "\n")] = '\0';
            }
            printf("\n");

            if (strcasecmp(action, "n") == 0) {
                printf("Goodbye!\n");
                break;
            }
        }
    }
}

void ask() {
    while (1) {
        system("clear");
        bprint("Ask");
        printf("\n");

        char query[100];

        printf("Query: ");
        if (fgets(query, sizeof(query), stdin)) {
            query[strcspn(query, "\n")] = '\0';
        }
        printf("\n");

        char *response = get_response(query);
        if (response) {
            printf("Response: %s\n\n", response);
            free(response);

            printf("Done! Would you like to continue? (y/n)\n");
            printf("$: ");

            char action[3];
            if (fgets(action, sizeof(action), stdin)) {
                action[strcspn(action, "\n")] = '\0';
            }
            printf("\n");

            if (strcasecmp(action, "n") == 0) {
                printf("Goodbye\n");
                break;
            }
        }
    }
}

int main() {
    simi();
    return 0;
}