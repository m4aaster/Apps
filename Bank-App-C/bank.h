#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifdef _WIN32 
#include <Windows.h>
#else
#include <unistd.h>
#endif

void CLEAR(void){
 system("cls||clear");
}

void WAIT(int ms){
 sleep(ms);
}

void PRINT(char *str){
 puts(str);
}

void EXIT(int return_code){
 exit(return_code);
}
