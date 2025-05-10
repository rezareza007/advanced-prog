
#include<stdio.h>

void swap_wrong(int x, int y) /* WRONG */ 
 { 
 int temp; 
 temp = x; 
 x = y; 
 y = temp; 
 } 


 void swap_right(int *px, int* py) 
 { 
 int temp; 
 temp = *px;  //temp equals the value that px points to 
 *px = *py; 
 *py = temp; 
 } 


int main()
{
    int x=1, y=20;

    swap_wrong(x,y);
    printf("swap_wrong: %d, %d\n", x,y);

    swap_right(&x, &y);
    printf("swap_right: %d, %d\n", x,y);

} 

