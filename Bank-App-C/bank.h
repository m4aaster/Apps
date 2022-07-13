#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

void CLEAR(void){
 system("clear");
}

void WAIT(int ms){
 sleep(ms);
}

void PRINT(char *str){
 puts(str);
}
