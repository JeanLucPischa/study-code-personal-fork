/*
* File: lab5_mySolution_Sec3.h
* Description: Declaration of the functions used for a program to simulate the behaviour of particles
*/

#ifndef LAB5_MYSOLUTION_SEC3_H
#define LAB5_MYSOLUTION_SEC3_H

/*
* @brief  fill given array with zeros except index 1, 3 and 5, fill them with 1
*
* @param[in]  particle_arr  given array to store the numbers / particles in
*             size          size of the given array
*/
void setParticleArray(int *particle_arr, int *temp_arr, int size);

/*
* @brief  display the current state of the particle-array
*
* @param[in]  particle_arr  given array with the particles
*             size          size of the particle-array
*             counter       current time-step
*/
void displayParticles(int *particle_arr, int size, int counter);

/*
* @brief  simulate the movement of the particles
*
* @param[in]  particle_arr  given array with the particles
*             temp_arr      temporary array to store momentary positions of particles
*             size          size of the particle-array
*/
void simulateParticles(int *particle_arr, int *temp_arr, int size);

/*
* @brief  simulate the movement of the particles for a given amount of steps
*
* @param[in]  times         times of steps simulated
*             particle_arr  given array with the particles
*             temp_arr      temporary array to store momentary positions of particles
*             size          size of the particle-array
*/
void simulateRun(int times, int *particle_arr, int *temp_arr, int size);

#endif