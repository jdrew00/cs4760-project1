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

int main(int argc, char *argv[])
{
   int opt;
   //int n=0;

   while((opt = getopt(argc, argv, ":pcsif:h")) != -1) 
    { 
        switch(opt) 
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
                break;
            case 'p': 
            case 'c': 
            case 's': 
            case 'i':  
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

    
   return 0;

/*
Program 3.1 from text
pid_t childpid = 0;
   int i, n;

   if (argc != 2)
   {
      fprintf(stderr, "Usage: %s processes\n", argv[0]);
      return 1;
   }
   n = atoi(argv[1]);
   for (i = 1; i < n; i++)
      if (childpid = fork())
         break;
   fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
           i, (long)getpid(), (long)getppid(), (long)childpid);
   return 0;
*/

}