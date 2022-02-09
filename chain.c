/*
Jacob Drew
CS 4760 Project 1

external resoruces:
getopt tutorial:
https://www.geeksforgeeks.org/getopt-function-in-c-to-parse-command-line-arguments/

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
    int opt;
    pid_t childpid = 0;
    int i;
    int n;
    n=0;
    int m,k = 0;
    // getopt
    while ((opt = getopt(argc, argv, ":p:c:s:i:f:h")) != -1)
    {
        switch (opt)
        {
        case 'h':
            printf("Help:\n");
            printf("How to run:\n");
            printf("chain [-h] [-p nprocs] [-c nchars] [-s sleeptime] [-i niters] < textfile\n");
            printf("n nprocs Number of processes [default 4]\n");
            printf("nchars Number of characters read into the buffer [default 80]\n");
            printf("sleeptime Time to sleep in each iteration [default 3s]\n");
            printf("niters Numbner of iterations in the loop\n");
            printf("textfile File containing text to be read through 'stdin'\n");
            //if -h is the only arg exit program
            if(argc==2){
                exit(0);
            }
            
            break;
        case 'p':
            n = atoi(optarg);
            printf("input: %d\n", n);
            break;
        case 'c':
        case 's':
            m = atoi(optarg);
            printf("Sleep time: %d\n", m);
            break;
        case 'i':
            k = atoi(optarg);
            printf("Loop iterations time: %d\n", k);
            break;
        case 'f':
            printf("filename: %s\n", optarg);
            break;
        case ':':
            printf("option needs a value\n");
            break;
        case '?':
            printf("unknown option: %c\n", optopt);
            break;
        }
    }

    //program 3.1 from text
    if (n != 0)
    {
        for (i = 1; i < n; i++)
            if (childpid = fork())
                break;
        for(i=1; i<=k; i++){
            sleep(m);
            wait(NULL);
            fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
                i, (long)getpid(), (long)getppid(), (long)childpid);
        }
        
    }
    
    return 0;
}