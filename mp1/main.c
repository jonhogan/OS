/***************************************************************
  Ethan Coyle
  Dymon Brown
  Jonathan Hogan

  CMPS-4103-101 Intro to Operating Systems
  Dr. Passos
  Mini Project 1
  
****************************************************************/


#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define myPID getpid()
#define parentID getppid()

void *read_chars(int pid, char array[]) {
  int readptr;
  int start = pid * 10;

  //open the input file to read from
  readptr = open("input.txt", O_RDWR);

  lseek(readptr, start, SEEK_SET);
  read(readptr, array, 5);
  close("input.txt");
  
  //open a file to print to
  FILE *f_write;
  f_write = fopen("output.txt", "a");
  fprintf(f_write,"From process %d: %c%c%c%c%c\n", pid, array[0], array[1], array[2], array[3], array[4]);
  fclose(f_write);
}

int main(int argc, char *argv[]) {
  int pid;
  int i = 1;

  // Create the child processes
  fork();

  //The first process will have a parent ID of one this
  //will block the first child from creating a fork
  if (parentID == 1) {
    fork();
  }

  // Assign process ids
  if (parentID == 1) {
    pid = 0;
  } else {
    // Will give a process ID of 1 and 2
    pid = myPID - parentID;
  }
  char charArray[5];
  read_chars(pid, charArray);
  waitpid(-1, NULL, 0);

  return 0;
}