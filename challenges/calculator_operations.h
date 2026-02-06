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