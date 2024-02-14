#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6
int number_printed=0;

void print_number(int n){
    printf("%10d ", n);
    number_printed++;

    if(number_printed % COLUMNS==0)
      printf("\n");
}

void print_sieves(int n) {

    char* sieveArrayptr =(char*) malloc(7920);


    for (int i = 2; i <= 7920; i++) {
        *(sieveArrayptr+i) = 1; //assume all of them are prime
    }
    for(int i = 2;i*i<=7920;i++)
    {
        if (*(sieveArrayptr+i)==1){//for all primes
          for(int j=2*i;j<=7920;j+=i)//go through all the multiples of this prime
              *(sieveArrayptr+j)=0; //and mark them as non primes
        }
    }

    int counter =0;
    for(int sieveElement =0;sieveElement<7920;sieveElement++)
      {
        //printf(" %d: %d\n", sieveElement, *(sieveArrayptr+sieveElement));
        if(*(sieveArrayptr+sieveElement)==1)
        {
            counter++;
            if(counter==n)
                printf("%10d\n", sieveElement);
        }
      }
      free(sieveArrayptr);
}

int main(int argc, char *argv[]){
  if(argc == 2)
    print_sieves(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}
