#include <stdio.h>

float add(float operand1, float operand2){
  return operand1+operand2;
}
float subtract(float operand1, float operand2){
  return operand1-operand2;
}
float multiply(float operand1, float operand2){
  return operand1*operand2;
}
float divide(float operand1, float operand2){
 return operand1/operand2;
}

void printResult(float operand1, float operand2, char operator, float (*calc)(float, float)){
  printf("Das Ergebnis der Berechnung ist: %.2f %c %.2f = %.2f", operand1, operator, operand2, calc(operand1, operand2));
}

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