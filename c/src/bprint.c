#include <stdio.h>
#include <unistd.h>
#include <string.h>

void bprint(const char *text) {
    int text_length = strlen(text);
    int border_length = text_length + 4;

    for (int i = 0; i < border_length; i++) {
        putchar('*');
        fflush(stdout);
        usleep(19500);
    }
    printf("\n");

    printf("* ");
    for (int i = 0; i < text_length; i++) {
        putchar(text[i]);
        fflush(stdout);
        usleep(19500);
    }
    printf(" *\n");

    for (int i = 0; i < border_length; i++) {
        putchar('*');
        fflush(stdout);
        usleep(19500);
    }
    printf("\n");
}
