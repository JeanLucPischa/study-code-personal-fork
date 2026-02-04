#include <stdio.h>

int main(){

  int row = 8;

  for(int j=row; j>0; j--){
    for(int i=0; i<8; i++){
      printf("%c%d  ", i+'A', row);
    }
    printf("\n\n"); 
    row--;
  }

  return 0;
}