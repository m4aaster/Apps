#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "bank.h"

//GLOBAL VARIABLES START//
int balance = 0;
int pin = 1234;
//GLOBAL VARIABLES END//

//FUNCTIONS START//
int main(void);
int MAIN_MENU(void);
int BACK(void);
int OPT1(void);
int OPT2(void);
int OPT3(void);

int main(void){
 CLEAR();
 PRINT("Welcome to The Bank of America");
 WAIT(3);
 MAIN_MENU();
 return 0;
}

int MAIN_MENU(void){
 CLEAR();
 PRINT(" 1 - Check Balance \n 2 - Deposit \n 3 - Withdraw \n 4 - Settings \n 5 - Exit");
 int opt;
 scanf("%d",&opt);
 if(opt==1){
  OPT1();
 }else if(opt==2){
  OPT2();
 }else if(opt==3){
  OPT3();
 }
 return 0;
}

int BACK(void){
 CLEAR();
 PRINT("Do you want to exit?\n(y or n)");
 char res;
 scanf("%c",&res);
 if(res=='y'){
  return 0;
 }else if(res=='n'){
  MAIN_MENU();
 }else{
  BACK();
 }
 return 0;
}

int OPT1(void){
 CLEAR();
 printf("The current balance is: %d\n",balance);
 WAIT(3);
 BACK();
 return 0;
}

int OPT2(void){
 CLEAR();
 PRINT("Digit the desire amout:");
 int amount;
 scanf("%d",&amount);
 balance += amount;
 BACK();
 return 0;
}

int OPT3(void){
 CLEAR();
 int bill1 = 1,bill2 = 2,bill5 = 5,bill10 = 10,bill20 = 20,bill50 = 50,bill100 = 100,amount;
 PRINT("Digit the desire amount:");
 scanf("%d",&amount);
 if(amount>=bill100){
  balance -= bill100;
 }else if(amount>=bill50){
  balance -= bill50;
 }else if(amount>=bill20){
  balance -= bill20;
 }else if(amount>=bill10){
  balance -= bill10;
 }else if(amount>=bill5){
  balance -= bill5;
 }else if(amount>=bill1){
  balance -= bill1;
 }
 printf("Withdrawn %d\n",amount);
 WAIT(3);
 BACK();
 return 0;
}
//FUNCTIONS END//
