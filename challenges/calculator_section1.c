#include <stdio.h>

float add(float operand1, float operand2){
  return operand1+operand2;
}
float sub(float operand1, float operand2){
  return operand1-operand2;
}
float multi(float operand1, float operand2){
  return operand1*operand2;
}
float div(float operand1, float operand2){
 return operand1/operand2;
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
    case '+': printf("Das Ergebnis der Berechnung ist: %.2f %c %.2f = %.2f", firstNum, operator, secondNum, add(firstNum, secondNum)); break;
    case '-': printf("Das Ergebnis der Berechnung ist: %.2f %c %.2f = %.2f", firstNum, operator, secondNum, sub(firstNum, secondNum)); break;
    case '*': printf("Das Ergebnis der Berechnung ist: %.2f %c %.2f = %.2f", firstNum, operator, secondNum, multi(firstNum, secondNum)); break;
    case '/': secondNum==0 ? printf("Division durch Null ist nicht definiert.") : printf("Das Ergebnis der Berechnung ist: %.2f %c %.2f = %.2f", firstNum, operator, secondNum, div(firstNum, secondNum));  break;
    default: break;
  }

  return 0;
}