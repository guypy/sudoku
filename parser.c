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
    char* cmd;
    fgets(cmd_str, 1024, stdin);
    cmd = strtok(cmd_str, " \t\r\n");
    char* arg = strtok(NULL, " \t\r\n");
    int i = 0;
    while (arg != NULL) {
        args[i] = (int) *arg - '0';
        printf("%d\n", args[i]);
        arg = strtok(NULL, " \t\r\n");
        i++;
    }

    return cmd;
}
