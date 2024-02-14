/*
 print-prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6
int number_printed=0;

int is_prime(int n){
  for(int i=2; i<n;i++)
  {
    //printf("i=%d\n",i);
    if(n%i==0) //n i dividible by i : n is not a prime
      return 0; //end program here
  }
  return 1;
}

void print_number(int n){
    printf("%10d ", n);
    number_printed++;

    if(number_printed % COLUMNS==0)
      printf("\n");
}

void print_primes(int n){
  // Should print out all prime numbers less than 'n'
  // with the following formatting. Note that
  // the number of columns is stated in the define
  // COLUMNS

  for(int number=2;number<=n;number++)
  {
    if(is_prime(number))
    {
        print_number(number);
    }    
  }
  printf("\n");
}



// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
  if(argc == 2)
    print_primes(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}

 
