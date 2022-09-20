//#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define myPID getpid()
#define parentID getppid()

void *read_chars(void *pid){
  
}

int main(int argc, char *argv[]){
  int  pid;
  char *charArray;

  charArray = malloc(60);


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