#include <stdio.h>

int main(){

  char shipClass[] = "NCC-1701-D";
  int crewNumber = 183;
  int daysIntoMission = 251;
  long long distanceKM = 41245279304903218;
  float distanceLY = 4359.62946;
  float distanceC = 72.6;
  float shipRange = 82.914;

  printf("Class of ship: ");
  scanf("%s", shipClass);
  printf("\n");
  printf("Count of crew: ");
  scanf("%d", &crewNumber);
  printf("\n");
  printf("Time since missions begin: ");
  scanf("%d", &daysIntoMission);
  printf("\n");

  printf("\n\n\n%-40s %-30s %s\n", "Unit", "Value", "Unit");
  for(int i = 0; i < 100; i++){
    printf("-");
  }
  printf("\n");
  printf("%-40s %s\n","Class", shipClass);
  printf("%-40s %d\n", "Crew Count", crewNumber);
  printf("%-40s %-30d %s\n", "Time since missions begin", daysIntoMission, "days");
  printf("%-40s %-30lld %s\n", "Distance", distanceKM, "km");
  printf("%-40s %-30.2f %s\n", "Distance", distanceLY, "lightyears");
  printf("%-40s %-30.1f %s\n", "Flown with lightspeed", distanceC, "% of distance");
  printf("%-40s %.3f %s\n\n\n\n", "Current range", shipRange, "lightyears");

  return 0;
}