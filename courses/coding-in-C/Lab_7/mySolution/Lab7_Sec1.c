/*
 *  File: Lab7_Sec1.c
 *  Description: demonstrate key differences between malloc and calloc. 
 *                ->  malloc: reserve defined amount of memory; declaration of defined object
 *                ->  calloc: reserve memory for declaration of array
 */

#include <stdio.h>
#include <stdlib.h>

int main(){

  int N = 0;

  printf("Please put in integer number: \n");
  scanf("%d", &N);
  printf("------------------------------------\n");

  int *ptr_memory = malloc(sizeof(N));
  int *ptr_memory2 = calloc(N, sizeof(N));

  if(ptr_memory == NULL){
    printf("memory allocation for ptr_memory failed");
    return 1;
  }
  if(ptr_memory2 == NULL){
    printf("memory allocation for ptr_memory2 failed");
    return 1;
  }

  *ptr_memory = N;

  for(int i=0; i<N; i++){
    ptr_memory2[i] = i*i;
  }

  ptr_memory2 = realloc(ptr_memory2, sizeof(N)*2);
  for(int i=0; i<(2*N); i++){
    ptr_memory2[i] = i*i;
  }

  for(int i=0; i<(2*N); i++){
    printf("%d\n", ptr_memory2[i]);
  }
  printf("------------------------------------");

  free(ptr_memory);
  free(ptr_memory2);

  return 0;
}