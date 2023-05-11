#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
char* map(char *array, int array_length, char (*f) (char)){
  char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
  /* TODO: Complete during task 2.a */
  for(int i=0; i<array_length; i++){
    mapped_array[i] = f(array[i]);
  }
  free(array);
  return mapped_array;
}
 
char my_get(char c){
  /*Ignores c, reads and returns a character from stdin using fgetc. */
  return fgetc(stdin);
} 

char cprt(char c){
/* If c is a number between 0x20 and 0x7E, cprt prints the character of ASCII value c followed by a new line.
otherwise, cprt prints the dot ('.') character. After printing, cprt returns the value of c unchanged. */
  if((c >= 0x20) & (c <= 0x7E))
    printf("%c\n", c);
  else
    printf(".\n");
  return c;
}

char encrypt(char c){
/* Gets a char c and returns its encrypted form by adding 1 to its value. If c is not between 0x20 and 0x7E it is returned unchanged*/
  if((c >= 0x20) & (c <= 0x7E))
    return c+1;
  else
    return c;
}

char decrypt(char c){
/* Gets a char c and returns its decrypted form by reducing 1 to its value. If c is not between 0x20 and 0x7E it is returned unchanged*/
  if((c >= 0x20) & (c <= 0x7E))
    return c-1;
  else
    return c;
}

char xprt(char c){
  /* xprt prints the value of c in hexadecimal representation followed by a new line, and returns c unchanged. */
  if((c >= 0x20) & (c <= 0x7E))
    printf("The hexadecimal value of '%c' is %x\n", c,c);
  else
    printf(".\n");
  return c;
}

    struct fun_desc {
    char *name;
    char (*fun)(char);
    };

    struct fun_desc menu[] = {{"Get string", my_get}, {"Print string", cprt},{"Encrypt",encrypt},{"Decrypt", decrypt}, {"Print Hex", xprt}, {NULL, NULL}};

int main(int argc, char **argv){
  /* TODO: Test your code */
  /* define an array of length 5 initialized to the empty string */
  char* carray = malloc(5); 
  carray[0] = '\0';
  int MenuSize = 0;
  while(menu[MenuSize].name != NULL)
    MenuSize++;
  while(1){
    printf("Select operation from the following menu by selecting the number or Ctrl^D for exit:\n");
    int j = 0;
    while(menu[j].name != NULL){
      printf("%d) %s \n", j, menu[j].name);
      j++;
      }
      char InputString[5];
      if(fgets(InputString,5 ,stdin) == NULL){
        free(carray);
        exit(0);
      }
      else{
        int number = atoi(InputString);
        if((number >= 0) & (number < MenuSize)){
          printf("Within bounds\n");
          carray = map(carray, 5, menu[number].fun);
          }
          else {
            printf("Not within bounds\n");
            free(carray);
            exit(0);
          }
      }
  }
}

