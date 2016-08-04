#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#ifndef TRUE
    #define TRUE 1
#endif
#ifndef FALSE
    #define FALSE 0
#endif
#ifndef BOOL
    #define BOOL uint8_t
#endif

void banner() {
    printf("##################################\n");
    printf("#          Challenge 1           #\n");
    printf("#                                #\n");
    printf("#      (c) 2016 Timo Schmid      #\n");
    printf("##################################\n");
}

BOOL checkPassword(const char* password) {
    const char* foo = "p4ssw0rd";
    /*
     * I'm aware that the strlen is wrong here. I've added it to
     * generate some additional assembly code.
     * strncmp(password, "n0p4ssw0rd", 11) would be more fail safe
     * Be aware that it's strlen("n0p4ssw0rd") + 1, otherwise
     * "n0p4ssw0rd_And_some_junk" would be also considered equal.
     */
    return strncmp(password, "n0p4ssw0rd", strlen(password)) == 0;
}

int main(int argc, char** argv, char** env) {
    banner();

    char password[256];
    printf("Enter Password: ");
    scanf("%255s", password);
    /* not really required as scanf adds a null byte,
     * but explicit is better than implicit */
    password[sizeof(password)-1] = '\0';

    if(checkPassword(password)) {
        printf("Password accepted!\n");
    } else {
        printf("Wrong!\n");
    }
    return EXIT_SUCCESS;
}
