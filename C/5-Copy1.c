#include <stdio.h> 
/* copy input to output; 1st version */ 
int main() 
{ 
int c; 

c = getchar(); //Inputs a char from keyboard 

while (c != EOF) { 
putchar(c);   // Prints a char into the screen

c = getchar(); 
} 
} 
