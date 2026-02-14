//#include "lab5-mySolution-Sec3.h"

void setParticleArray(int *particle_arr, int size){
  for(int i=0; i<size; i++){
    particle_arr[i] = 0;
    if((i==1)||(i==3)||(i==5)){ //set to 1 on index 1, 3 and 5
      particle_arr[i] = 1;
    }
  }
}

void displayParticles(int *particle_arr, int size, int counter){
  printf("Time %d:", counter);

  for(int i=0; i<size; i++){
    printf("%d", particle_arr[i]);
  }

  printf("\n");
}