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

void setParticleArray(int *particle_arr, int size, const int *init_pos, int size_init_pos_arr, int *collision_memory){
  int init_index = 0;

  for(int i=0; i<size; i++){
    particle_arr[i] = EMPTY_SPACE;

    if(init_index<size_init_pos_arr && init_pos[init_index]==i){  //check all content of init_pos[] and place ones accordingly
      particle_arr[i] = PARTICLE;
      init_index++;
    }
  }

  for(int i=0; i<((int)(size_init_pos_arr/2)); i++){        //initialize collision memory with value out of range
    collision_memory[i] = size+1;
  }
}

void displayParticles(int *particle_arr, int size, int counter, int *collision_memory){
  printf("Time %d: ", counter);

  for(int i=0; i<size; i++){
    if(i == collision_memory[0]){                           //print index where collision happend in red color
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

void simulateParticles(int *particle_arr, int *temp_arr, int size, int *collision_memory){
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
      printf("Collision on index %d\n", i);
      collision_memory[0] = i;
    }
  }

  //copy temporary array to original
  for(int i=0; i<size; i++){  
    particle_arr[i] = temp_arr[i];
  }
}

void simulateRun(int times, int *particle_arr, const int *init_pos, int *temp_arr, int size, int size_init_pos_arr){
  int max_collisions = (int)(size_init_pos_arr/2);  //max amount of collisions possible is particles / 2 (floored); e.g. 7 particles -> max 3 collisions possible
  int collision_memory[max_collisions];    

  setParticleArray(particle_arr, size, init_pos, size_init_pos_arr, collision_memory);

  for(int i=0; i<times; i++){
    displayParticles(particle_arr, size, i, collision_memory);

    collision_memory[0] = size+1;                   //reset collision memory
    
    simulateParticles(particle_arr, temp_arr, size, collision_memory);
  }
}