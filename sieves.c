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
    char sieveArray[n+1];

    for (int i = 2; i <= n; i++) {
        sieveArray[i] = 1; //assume all of them are prime
    }
    for(int i = 2;i*i<=n;i++) 
    {
        if (sieveArray[i]==1){//for all primes
          for(int j=2*i;j<=n;j+=i)//go through all the multiples of this prime
              sieveArray[j]=0; //and mark them as non primes
        }
    }

    for(int sieveElement =0;sieveElement<n;sieveElement++)
      {
        //printf(" %d: %d\n", sieveElement, sieveArray[sieveElement]);
        if(sieveArray[sieveElement]==1)
        {
            print_number(sieveElement);
        }    
      }
}

int main(int argc, char *argv[]){
  if(argc == 2)
    print_sieves(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}