#include <stdio.h>

int main(){

  FILE* data = fopen("test_file.txt", "r");

  if(data == NULL){
    printf("Datei konnte nicht geoeffnet werden.");
    return 1;
  }

  /*int c = 0;
  while((c = fgetc(data)) != EOF){
    printf("%c", c);  
  }*/

  char *string = NULL;
  char *puffer = NULL;
  while((string = fgets(puffer, 20, data)) != NULL){
    printf("%s", string);
  }

  int success = fclose(data);

  if(success){
    printf("Datei konnte nicht geschlossen werden.");
    return 1;
  }

  return 0;
}