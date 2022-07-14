#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bank.h"

//GLOBAL VARIABLES START//
int balance = 0; // DEFAULT BALANCE
int pin = 0000; // DEFAULT PIN
//GLOBAL VARIABLES END//

//FUNCTIONS START//
int main(void);
bool CHECKPIN(void);
int MAIN_MENU(void);
int BACK(void);
int OPT1(void);
int OPT2(void);
int OPT3(void);
int OPT4(void);
int SOPT1(void);

//MAIN GLOBAL VARS START//
int mcounter = 1;
//MAIN GOBAL VARS END//
int main(void){
 CLEAR();
 PRINT("Welcome to The Bank of America");
 WAIT(3);
 while(mcounter!=3){
 bool getaccess = CHECKPIN();
  if(getaccess){ 
   mcounter = 0;
   MAIN_MENU();
  }else{
   printf("Remaining attempts: %d\n",3-mcounter);
   mcounter++;
   WAIT(2);
   CLEAR();
   main();
  }
 }
 CLEAR();
 PRINT("you reached the maximum amount of tries..");
 WAIT(3);
 CLEAR();
 return 0;
}

bool CHECKPIN(void){
 int counter = 0;
 int inpin;
 PRINT("Insert your PIN:");
 scanf("%d",&inpin);
 if(inpin==pin){
  return true;
 }else{
  return false;
 }
}

int MAIN_MENU(void){
 CLEAR();
 PRINT(" 1 - Check Balance \n 2 - Deposit \n 3 - Withdraw \n 4 - Settings \n 5 - Re-Login \n 6 - Exit");
 int opt;
 scanf("%d",&opt);
 if(opt==1){
  OPT1();
 }else if(opt==2){
  OPT2();
 }else if(opt==3){
  OPT3();
 }else if(opt==4){
  OPT4(); 
 }else if(opt==5){
  main();
 }else if(opt==6){
  BACK();
 }else{
  MAIN_MENU();
 }
 return 0;
}

int BACK(void){
 CLEAR();
 PRINT("Do you want to exit?\n(y or n)");
 char res;
 scanf("%c",&res);
 if(res=='y'||res=='Y'){
  EXIT(0);
 }else if(res=='n'||res=='N'){
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
 int amount, aux;
 PRINT("Digit the desire amount:");
 scanf("%d",&amount);
 aux = amount;
  do{
  if(amount>=100){
   amount -= 100;
   balance -= 100;
  }else if(amount>=50){
   amount -= 50;
   balance -= 50;
  }else if(amount>=20){
   amount -= 20;
   balance -= 20;
  }else if(amount>=10){
   amount -= 10;
   balance -= 10;
  }else if(amount>=5){
   amount -= 5;
   balance -= 5;
  }else if(amount>=1){
   amount -= 1;
   balance -= 1;
  }
 }while(amount>0);
 printf("Withdrawn %d\n",aux);
 WAIT(3);
 BACK();
 return 0;
}

int OPT4(void){
 CLEAR();
 PRINT("SETTINGS OPTIONS: \n 1 - Change PIN \n 2 - Exit");
 int opt;
 scanf("%d",&opt);
 if(opt==1){
  SOPT1(); 
 }else if(opt==2){
  BACK();
 }else{
  OPT4();
 }
 return 0;
}

int SOPT1(void){
 CLEAR();
 PRINT("Type the desire PIN:");
 int auxpin;
 scanf("%d",&auxpin);
 pin = auxpin;
 WAIT(3);
 BACK();
 return 0;
}
//FUNCTIONS END//
