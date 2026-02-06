#include <stdio.h>
#include "calculator_operations.h"

int main(){

  float firstNum;
  float secondNum;
  char operator;

  printf("Bitte nachfolgend eine Zahl mit Nachkommastellen eingeben:\n");
  scanf("%f", &firstNum);
  printf("\n");

  printf("Nun bitte einen arithmetischen Operator (+, -, *, /) eingeben:\n");
  scanf(" %c", &operator);
  printf("\n");
  if((operator!='+')&&(operator!='-')&&(operator!='*')&&(operator!='/')){
    printf("Der eingegebene Operator ist nicht erlaubt.");
    return 1;
  }

  printf("Bitte nachfolgend eine Zahl mit Nachkommastellen eingeben:\n");
  scanf(" %f", &secondNum);
  printf("\n");

  switch(operator){
    case '+': printResult(firstNum, secondNum, operator, add); break;
    case '-': printResult(firstNum, secondNum, operator, subtract); break;
    case '*': printResult(firstNum, secondNum, operator, multiply); break;
    case '/': printResult(firstNum, secondNum, operator, divide);  break;
    default: break;
  }

  return 0;
}