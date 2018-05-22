#include "parser.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int prsr_readInt(){
    int num = -1;
    while (num < 0 || num > 80) {
        if (scanf("%d", &num) != 1){
            printf("Error: Scanf failed");
            exit(1);
        }
        if (num < 0 || num > 80)
            return -1;
    }

    return num;
}

char* prsr_fetchCmd(int *args){
    char* cmd_str = malloc(1024 * sizeof(char));
    char* cmdpt = NULL;
    char* cmd = malloc(1024 * sizeof(char));
    char* arg;
    int i = 0;
    if (!cmd_str){ /* allocation failed */
        printf("Error: %s has failed\n", "prsr_fetchCmd");
        exit(1);
    }

    while (cmdpt == NULL) {
        fgets(cmd_str, 1024, stdin);
        cmdpt = strtok(cmd_str, " \t\r\n");
        if (cmdpt == NULL && feof(stdin)) {
            printf("%s", cmdpt);
            strcpy(cmd, EXIT);
            return cmd;
        }
    }

    strcpy(cmd, cmdpt);

    arg = strtok(NULL, " \t\r\n");

    while (arg != NULL) {
        args[i] = (int) *arg - '0';
        arg = strtok(NULL, " \t\r\n");
        i++;
    }
    while (i < 3){
        args[i] = -1;
        i++;
    }
    free(cmd_str);
    return cmd;
}
