//
// Created by Yuval Barzam on 5/12/18.
//

#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int prs_ReadInt(){
    int num;
    scanf("%d", &num);
    return num;
}

char* parse_cmd(int* args){
    char* cmd_str = malloc(1024 * sizeof(char));
    char* cmd;
    int c;
    while ( (c = getchar()) != EOF && c != '\n') { }
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
