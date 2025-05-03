#include <stdio.h> 
/* printd: print n in decimal */ 
void printd(int n) 
{ 
   static int iteration=0;
   iteration++;

   printf("Iteration: %d\n", iteration);
  
if (n < 0) { 
    putchar('-'); 
    n = -n; 
} 
if (n / 10) 
    printd(n / 10); 

    putchar(n % 10 + '0'); 

} 


int main()
{
    printd(1356);
}