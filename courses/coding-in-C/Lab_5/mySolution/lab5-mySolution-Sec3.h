#ifndef LAB5_MYSOLUTION_SEC3_H
#define LAB5_MYSOLUTION_SEC3_H

/*
* @brief  fill given array with zeros except index 1, 3 and 5, fill them with 1
*
* @param[in]  particle_arr  given array to store the numbers / particles in
*             size          size of the given array
*/
void setParticleArray(int *particle_arr, int size);

/*
* @brief  display the current state of the particle-array
*
* @param[in]  particle_arr  given array with the particles
*             size          size of the particle-array
*             counter       current time-step
*/
void displayParticles(int *particle_arr, int size, int counter);

#endif