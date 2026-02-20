#include <stdio.h>

typedef struct {
  float fuel_level;
  float max_fuel_level;
  char *model;
} car;

void refuel(car *ptr_car, float add_fuel);

int main(){

  car Volvo = {10, 100, "V90"};
  car *ptr_Volvo = &Volvo;

  printf("Model: %s\nFuel-Level: %f\nMaximum Fuel-Level: %f\n", ptr_Volvo->model, ptr_Volvo->fuel_level, ptr_Volvo->max_fuel_level);

  refuel(ptr_Volvo, 300);

  printf("Model: %s\nFuel-Level: %f\nMaximum Fuel-Level: %f\n", ptr_Volvo->model, ptr_Volvo->fuel_level, ptr_Volvo->max_fuel_level);

  return 0;
}

void refuel(car *ptr_car, float add_fuel){
  if(((ptr_car->fuel_level)+add_fuel)<=ptr_car->max_fuel_level){
    ptr_car->fuel_level += add_fuel;
  }
  else{
    ptr_car->fuel_level = ptr_car->max_fuel_level;
  }
}