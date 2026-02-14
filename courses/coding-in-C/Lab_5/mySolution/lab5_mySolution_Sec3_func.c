/*
* File: lab5_mySolution_Sec3_func.c
* Description: Functions used for a program to simulate the behaviour of particles
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab5_mySolution_Sec3.h"

void setParticleArray(int *particle_arr, int *temp_arr, int size){
  for(int i=0; i<size; i++){
    particle_arr[i] = 0;

    if((i==1)||(i==3)||(i==5)){ //set to 1 on index 1, 3 and 5
      particle_arr[i] = 1;
    }
  }
}

void displayParticles(int *particle_arr, int size, int counter){
  printf("Time %d: ", counter);

  for(int i=0; i<size; i++){
    printf("%d ", particle_arr[i]);
  }

  printf("\n");
}

void simulateParticles(int *particle_arr, int *temp_arr, int size){
  for(int i=0; i<size; i++){
    temp_arr[i] = 0;
  }

  for(int i=0; i<size; i++){  //check for particles
    if(particle_arr[i]==1){   //particle detected
      if((rand()%2)==1){    //move left
        if(i!=0){
          temp_arr[i-1] += 1;
        }
      }
      else{                   //move right
        if(i!=size-1){
          temp_arr[i+1] += 1;
        }
      }
    }
  }

  for(int i=0; i<size; i++){  //check for collisions
    if(temp_arr[i]>1){
      temp_arr[i] = 0;
      printf("Collision on index %d\n", i);
    }
  }

  for(int i=0; i<size; i++){  //copy temporary array to original
    particle_arr[i] = temp_arr[i];
  }
}

void simulateRun(int times, int *particle_arr, int *temp_arr, int size){
  setParticleArray(particle_arr, temp_arr, size);

  for(int i=0; i<times; i++){
    displayParticles(particle_arr, size, i);
    simulateParticles(particle_arr, temp_arr, size);
  }
}