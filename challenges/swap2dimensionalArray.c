#include <stdio.h>

void printArray(int array[][2]){
  for (int i = 0; i < 2; i++){        //rows
    for(int j = 0; j < 2; j++){       //columns
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
}

void swapArrays(int array1[][2], int array2[][2]){
  for (int i = 0; i < 2; i++){        //rows
    for(int j = 0; j < 2; j++){       //columns
      int temporary = array1[i][j];
      array1[i][j] = array2[i][j];
      array2[i][j] = temporary;
    }
  }
}

int main(){
    
  int arr1[2][2] = {{1, 2}, {3, 4}};
  int arr2[2][2] = {{5, 6}, {7, 8}};

  printf("Current content of arr1 and arr2:\n");
  printArray(arr1);
  printArray(arr2);

  swapArrays(arr1, arr2);

  printf("\nSwapped content of arr1 and arr2:\n");
  printArray(arr1);
  printArray(arr2);

return 0;
}