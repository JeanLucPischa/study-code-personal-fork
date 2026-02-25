/*
 *  File: string_util.c
 *  Description: 
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/string_utils.h"

#define MAX_STRING_LEN 100

int custom_len(char *string){
  int correction = 0;
  int length;

  if(string[sizeof(string)] == '\0'){   //remove '\0' from string
    correction = 1;
  }
  
  length = ((sizeof(string)/sizeof(char))-correction);

  if(length<1){   //is string empty?
    return -1;
  }

  return length;
}

char *read_line_dynamic(){
  char string[MAX_STRING_LEN];

  printf("Bitte Zeichenkette eingeben: \n");

  fgets(string, sizeof(string), stdin);   //Zeichen einlesen
  if(string == NULL){   //Fehlerhafte Eingabe?
    return "ERROR";
  }

  char *memory = malloc(custom_len(string));    //Speicher für den String reservieren

  for(int i=0; i<custom_len(string); i++){    //Inhalt von string in memory kopieren
    memory[i] = string[i];
  }

  return memory;
}