////////////////////////////////////////////////////
//                                                //
// Authors    : Ethan Coyle, Jonathan Hogan and   //
//              Dymon Browne                      //
//                                                //
// Teacher    : Dr. Passos                        //
// Class      : Intro to Operating Systems        //
// Assignment : Mini Project 2                    //
//                                                //
// This project includes the use of semaphore and //
// using thread counts  for unix threading        //
////////////////////////////////////////////////////

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_OF_THREADS 5
#define SIZE 10000

//pthread_mutex_t mx;
pthread_cond_t cond[5];
int cnt = 0;

int TOTAL = 0;
int theArray[SIZE];

void wait(S){
    while (S < 0);
    S--;
}

void signal(S){
    S++;
}

void sem_sum(void *thread_id){
    long sum = 0;
    long tid = (long)thread_id;
    long start = ((tid - 1) * 2000);
    long end = start + 2000;

    wait(cnt);

    for (int i = start; i < end; i++){
        sum += theArray[i];
    }

    printf("Thread %ld: Sum is %ld using a semaphore\n", tid, sum);

    signal(cnt);
}

void no_sem_sum(void *thread_id){
    long sum = 0;
    long tid = (long)thread_id;
    long start = ((tid - 1) * 2000);
    long end = start + 2000;

    for (int i = start; i < end; i++){
        sum += theArray[i];
    }

    printf("Thread %ld: Sum is %ld without using a semaphore\n", tid, sum);

}

int main()
{
    pthread_t threads[NUM_OF_THREADS];
    int rc;
    long t;
    void * status;
    pthread_attr_t attr;
    //pthread_mutex_init(&mx,NULL);
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    
    for(int i = 1; i < SIZE; i++){
        theArray[i] = i%257;
    }

    for(int tid = 1; tid <= NUM_OF_THREADS; t++){
        rc = pthread_create(&threads[t], &attr, no_sem_sum, (void *)tid);
        if (rc){
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_attr_destroy(&attr);

    for(int i=0; i<NUM_OF_THREADS; i++){
        pthread_join(threads[i], &status);
    }

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for(int tid = 1; tid <= NUM_OF_THREADS; t++){
        rc = pthread_create(&threads[t], &attr, sem_sum, (void *)tid);
        if (rc){
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_attr_destroy(&attr);

    for(int i=0; i<NUM_OF_THREADS; i++){
        pthread_join(threads[i], &status);
    }
    
    //pthread_mutex_destroy(&mx);
    pthread_exit(NULL);
    return 0;

}

// only thing left is make sure values of array are initialized i%257 i think
// that I got that done and then the only other thing is where Passos specified
// that the value range should be 2000-3999 those are the only two things this
// is lacking and the program will be done