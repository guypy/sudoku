#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int prs_ReadInt(){
    int num;
    scanf("%d", &num);
    getchar();
    return num;
}

char* parse_cmd(int* args){
    char* cmd_str = malloc(1024 * sizeof(char));
    char* cmd = NULL;
    char* arg;
    int i = 0;
    if (!cmd_str){ /* allocation failed */
        printf("Error: %s has failed\n", "parse_cmd");
        exit(1);
    }
    while (cmd == NULL) {
        fgets(cmd_str, 1024, stdin);
        cmd = strtok(cmd_str, " \t\r\n");
    }
    arg = strtok(NULL, " \t\r\n");

    while (arg != NULL) {
        args[i] = (int) *arg - '0';
        arg = strtok(NULL, " \t\r\n");
        i++;
    }

    return cmd;
}
