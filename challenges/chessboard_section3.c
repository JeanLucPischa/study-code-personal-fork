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
  int counter = 0;
  char *color[2] = {"###", "   "};

  if(row%2){
    counter++;
  }

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
  for(int k=0; k<2; k++){
    printColumnLetters();
    if(k==1){
      break;
    }
    for(int row=board_size; row>0; row--){
      printHorizontalBorder();
      printSquares(row);
    }
    printHorizontalBorder();
  }
}

int main(){

  printChessboard();
  
  return 0;
}