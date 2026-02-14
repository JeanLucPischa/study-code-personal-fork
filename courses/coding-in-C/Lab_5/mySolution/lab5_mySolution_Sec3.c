/*
* File: lab5_mySolution_Sec3.c
* Description: Program to simulate the behaviour of particles
*/

#include <stdlib.h>
#include <time.h>
#include "lab5_mySolution_Sec3.h"

#define ARRAY_SIZE 10
#define TIME_STEPS 10

int main(){
  srand(time(NULL));

  int my_particle_arr[ARRAY_SIZE];

  int temp_arr[ARRAY_SIZE];

  simulateRun(TIME_STEPS, my_particle_arr, temp_arr, ARRAY_SIZE);

  return 0;
}