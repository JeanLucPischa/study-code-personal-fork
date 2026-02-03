#include <stdio.h>

#define board_size 8

void printHorizontalBorder(){
  printf("  ");
  for(int i=0; i<board_size; i++){
    printf("+---");
  }
  printf("+\n");
}

void printSquares(int row){
  int counter = row%2;
  char *color[2] = {"###", "   "};

  printf("%d ", row);

  for(int i=0; i<board_size; i++){
    counter = counter%2;
    printf("|%s", color[counter]);
    counter++;
  }

  printf("| %d\n", row);
}

void printColumnLetters(){
  printf("    ");
  for(int i=0; i<board_size; i++){
    printf("%c   ", i+65);
  }
  printf("\n");
}

void printChessboard(){
  printColumnLetters();

  for(int row=board_size; row>0; row--){
    printHorizontalBorder();
    printSquares(row);
  }
  printHorizontalBorder();
  
  printColumnLetters();
}

int main(){

  printChessboard();
  
  return 0;
}