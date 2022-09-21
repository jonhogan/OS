//#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define myPID getpid()
#define parentID getppid()

void *read_chars(void *pid, char $array){
  
}

int main(int argc, char *argv[]){
  int pid;
  int i = 1;
  char *charArray;

  charArray = malloc(60);

  //Open and read from the file
  FILE *doc;

  doc = fopen("text.dat", "r");

  if(NULL == doc){printf("File not found.\n")};

  charArray[0] = fgetc(doc);

  while(doc != EOF){
    charArray[i] = fgetc(doc);
  }

  for(int j = 0; j < 60; j++){
    printf("%c ", charArray[j]);
  }

 //Create the two child processes 
  fork();
  if(parentID == 1){
    fork();
  }
  
  if(parentID == 1){
    pid = 0;
  }else{
    pid = myPID - parentID;
  }

  waitpid(-1, NULL, 0);
  
  //printf("My ID is %d, my parent is %d. My Process ID is %d\n", myPID, parentID, pid);
}