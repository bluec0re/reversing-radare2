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

const const char* passwords[] = {
    "shad7Pe",
    "miTho7i",
    "Wa3suac",
    "ohGhah7",
    "Aibah1a",
    NULL
};

typedef struct CONTEXT {
    int tries;
    char inputPassword[256];
    const char** pwdList;
    const char** currentPassword;
} CONTEXT, *PCONTEXT;

void banner() {
    printf("##################################\n");
    printf("#          Challenge 3           #\n");
    printf("#                                #\n");
    printf("#      (c) 2016 Timo Schmid      #\n");
    printf("##################################\n");
}

int readPassword(PCONTEXT ctxt) {
    printf("Enter Password no. %d: ", ctxt->currentPassword - ctxt->pwdList + 1);
    scanf("%255s", ctxt->inputPassword);
    /* not really required as scanf adds a null byte,
     * but explicit is better than implicit */
    ctxt->inputPassword[sizeof(ctxt->inputPassword)-1] = '\0';
    return strlen(ctxt->inputPassword);
}

BOOL checkPassword(PCONTEXT context) {
    for(context->currentPassword = context->pwdList;
        *context->currentPassword != NULL;
        context->currentPassword++) {
        int len = readPassword(context);
        if(strncmp(context->inputPassword, *context->currentPassword, len))
            return FALSE;
    }
    return TRUE;
}

int main(int argc, char** argv, char** env) {
    banner();

    CONTEXT ctxt;
    ctxt.tries = 0;
    ctxt.pwdList = passwords;
    ctxt.currentPassword = passwords;

    if(checkPassword(&ctxt)) {
        printf("Password accepted!\n");
    } else {
        printf("Wrong!\n");
    }
    return EXIT_SUCCESS;
}
