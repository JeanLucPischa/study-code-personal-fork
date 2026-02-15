/*
* File: lab5_mySolution_Sec3.c
* Description: Program to simulate the behaviour of particles
*/

#include <stdlib.h>
#include <time.h>
#include "lab5_mySolution_Sec3.h"

#define ARRAY_SIZE 15
#define INIT_ARRAY_SIZE 3   //amount of particles at start
#define TIME_STEPS 20

int main(){
  srand(time(NULL));

  int my_particle_arr[ARRAY_SIZE] = {0};
  int temp_arr[ARRAY_SIZE] = {0};

  int initial_position[INIT_ARRAY_SIZE] = {3, 7, 13};

  simulateRun(TIME_STEPS, my_particle_arr, initial_position, temp_arr, ARRAY_SIZE, INIT_ARRAY_SIZE);

  return 0;
}