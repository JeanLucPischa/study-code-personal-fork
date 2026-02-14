/*
* File: lab5_mySolution_Sec3.c
* Description: Program to simulate the behaviour of a particle
*/

#include "lab5-mySolution-Sec3.h"

#define ARRAY_SIZE 10

int main(){

  int my_particle_array[ARRAY_SIZE];
  int counter = 0;

  setParticleArray(my_particle_array, ARRAY_SIZE);

  displayParticles(my_particle_array, ARRAY_SIZE, counter);

  return 0;
}