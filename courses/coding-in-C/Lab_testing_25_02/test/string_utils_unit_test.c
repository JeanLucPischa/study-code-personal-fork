/*
 *  File: string_util.c
 *  Description: 
 */

#include <assert.h>
#include <stdio.h>
#include "../include/string_utils.h"

int main(){

  char *string1 = "Dies ist ein Test"; //Länge: 17 (ohne '\0')
  char *string2 = '\0';

  /*
  assert(custom_len(string1) == 17);
  assert(custom_len("") == -1);
  assert(custom_len(string2) == 0);
  */

  assert(read_line_dynamic() == "Hallo");

  return 0;
}