#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int prs_ReadInt(){
    int num = -1;
    scanf("%d", &num);
    getchar();
    while (num < 0 || num > 80) {
        printf("Error: Invalid number of cells to fill (should be between 0 and 80)\n");
        while(getchar() != '\n');
        scanf("%d", &num);
    }

    return num;
}

char* parse_cmd(int* args){
    char* cmd_str = malloc(1024 * sizeof(char));
    char* cmdpt = NULL;
    char* cmd = malloc(1024 * sizeof(char));
    char* arg;
    int i = 0;
    if (!cmd_str){ /* allocation failed */
        printf("Error: %s has failed\n", "parse_cmd");
        exit(1);
    }
    while (cmdpt == NULL) {
        fgets(cmd_str, 1024, stdin);
        cmdpt = strtok(cmd_str, " \t\r\n");
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
