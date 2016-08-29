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
    printf("#          Challenge 2           #\n");
    printf("#                                #\n");
    printf("#      (c) 2016 Timo Schmid      #\n");
    printf("##################################\n");
}

BOOL checkPassword(const char* password) {
    const char* foo = "Sup3rP4ss";
    int len1 = strlen(foo);
    int len2 = strlen(password);
    if(len1 != len2)
        return 0;

    int len = len1;

    /* compare to reversed string */
    /* ss4Pr3puS */
    for(int i = 0; i < len; i++) {
        if(password[i] != foo[len-1-i])
            return 0;
    }
    return TRUE;
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
