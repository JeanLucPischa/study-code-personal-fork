/*
* File: lab5_mySolution_Sec3_func.c
* Description: Functions used for a program to simulate the behaviour of particles
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab5_mySolution_Sec3.h"

#define COLLISION_MARKER "\x1b[31m"       //red
#define PARTICLE_MARKER "\x1b[34m"        //blue
#define COLOR_RESET "\x1b[m"

#define PARTICLE 1
#define EMPTY_SPACE 0

#define NO_COLLISION -1                   //value out of range for collision detection

void setParticleArray(int *particle_arr, const int size, const int *init_pos, const int size_init_pos_arr){
  int init_index = 0;

  for(int i=0; i<size; i++){
    particle_arr[i] = EMPTY_SPACE;
    
    for(int j=0; j<size_init_pos_arr; j++){   //check if position in particle-array is supposed to have particle
      if(init_pos[j]==i){
        particle_arr[i] = PARTICLE;
      }
    }
  }
}

void displayParticles(const int *particle_arr, const int size, int timestep_counter, const int collision_index){
  printf("Time %d: ", timestep_counter);

  for(int i=0; i<size; i++){
    if(i == collision_index){                               //print index where collision happend in red color
      printf(COLLISION_MARKER "%d " COLOR_RESET, particle_arr[i]);
    }
    else{
      if(particle_arr[i]==PARTICLE){                        //print index with particles in blue color
        printf(PARTICLE_MARKER "%d " COLOR_RESET, particle_arr[i]);
      }
      else{
        printf("%d ", particle_arr[i]);
      }
    }
  }

  printf("\n");
}

void simulateParticles(int *particle_arr, int *temp_arr, const int size, int *ptr_collision_index){
  //initialize temporary array
  for(int i=0; i<size; i++){
    temp_arr[i] = 0;
  }

  //check for particles
  for(int i=0; i<size; i++){  
    if(particle_arr[i]==PARTICLE){
      if((rand()%2)){         //move left
        if(i > 0){
          temp_arr[i-1] += 1;
        }
        else{                 //particle next to border; no movement to the left
          temp_arr[i]++;
        }
      }
      else{                   //move right
        if(i < size-1){
          temp_arr[i+1] += 1;
        }
        else{                 //particle next to border; no movement to the right
          temp_arr[i]++;
        }
      }
    }
  }

  //check for collisions
  for(int i=0; i<size; i++){  
    if(temp_arr[i]>PARTICLE){ //check if there is more than one particle on one spot
      temp_arr[i] = 0;
      printf(COLLISION_MARKER "Collision on index %d\n" COLOR_RESET, i);
      *ptr_collision_index = i;
    }
  }

  //copy temporary array to original
  for(int i=0; i<size; i++){  
    particle_arr[i] = temp_arr[i];
  }
}

void simulateRun(int times, int *particle_arr, const int *init_pos, int *temp_arr, const int size, const int size_init_pos_arr){
 int collision_index = NO_COLLISION;

  setParticleArray(particle_arr, size, init_pos, size_init_pos_arr);

  for(int i=0; i<times; i++){
    displayParticles(particle_arr, size, i, collision_index);

    collision_index = NO_COLLISION;   //reset collision memory
    
    simulateParticles(particle_arr, temp_arr, size, &collision_index);
  }
}