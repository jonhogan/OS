/****************************************************
                                                
Authors    : Ethan Coyle, Jonathan Hogan and   
             Dymon Browne                      
                                               
Teacher    : Dr. Passos                        
Class      : Intro to Operating Systems        
Assignment : Mini Project 4                    
                                                
****************************************************/


#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

class MemoryBlock{
    private:
        int refBit = 0;
        int secondChance = 0;
        int segment = 0;

};



void FIFOCODE(vector<int> &v, int address, int &oldest, int &fault);
//create a prototype for the second change replacement algorithm
void SecondChance(vector<int> &v, int address, int &oldest, int &fault);

int main() 
{
  //Variable Declarations
  int FIFOPageFaults,SRCPageFaults=0;
  int FIFOOldest;
  int SecondChanceOldest;
  vector<int> FIFO;
  vector<int>SRC; // for the second chance algorithm
  //Changes the seed to generate truly random numbers
  srand((int)time(0));
  //generate a random number
  int randNum;
  //Run 1000 times for 4096 different addresses
  for (int i = 0; i < 4096; i++)
  {
    //Bitwise & operation perform the & bitwise
    randNum = rand();
    randNum = randNum & 0x0000FFFF;
    //Used to retrieve the page number,
    //because the page size takes up the first 11 bits
    //of the address.
    randNum = randNum & 0x0000F800;
    FIFOCODE(FIFO, randNum, FIFOOldest, FIFOPageFaults);
    SecondChance(SRC,randNum,SecondChanceOldest,SRCPageFaults);
}
  cout << "Number of FIFO Page Faults: " << FIFOPageFaults << "\n";
  cout<< SRCPageFaults<< " the sec chance faults";//system("pause");
  return 0;
}
//write a function that performs a second change page replacement algorithm and returns the number of page faults

void SRC(vector<int> &v, int address, int &oldest, int &fault)
{
  //If the vector is empty, add the address to the vector
  if (v.empty())
  {
    v.push_back(address);
    fault++;
    }
    else
    {
      //If the vector is not empty, check to see if the address is already in the vector
      if (find(v.begin(), v.end(), address) == v.end())
      {
        //If the address is not in the vector, add it to the vector
        v.push_back(address);
        fault++;
        //If the vector is full, remove the oldest address
        if (v.size() > 4)
        {
          v.erase(v.begin() + oldest);
          oldest++;
        }
      }


    }
}
void FIFOCODE(vector<int> &v, int address, int &oldest, int &fault)
{
  bool inVector = false;

  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] == address)
    {
      inVector = true;
    }
  }

  //Is the page number in our vector?
  if (inVector)
  {
    //If yes, do nothing
  }

  //If no, Add it to the list
  else
  {
    //Increment FIFO Page faults
    fault++;

    //If there are open spots
    if (v.size() < 5)
    {
      v.push_back(address);

      //If there are open spots, the oldest
      //entry will always be the first one.
      oldest = 0;
    }

    //If there are no open spots
    else
    {
      //Replace the oldest address with the new address
      v[oldest] = address;

      //Increment oldest counter
      if (oldest == 4)
      {
        oldest = 0;
      }
      else
      {
        oldest++;
      }
    }
  }
}
