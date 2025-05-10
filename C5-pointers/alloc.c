#include<stdio.h> 
#include<stdlib.h>
#define ALLOCSIZE 100000 /* size of available space */ 
 static char allocbuf[ALLOCSIZE]; /* storage for alloc */ 
 static char *allocp = allocbuf; /* next free position */ 
 
char *alloc(int n) /* return pointer to n characters */ 
 { 
 if (allocbuf + ALLOCSIZE - allocp >= n) 
 { /* it fits */ 
    printf("Allocated the memory!\n");
 allocp += n; 
 return allocp - n; /* old p */ 
 } 
 else /* not enough room */ 
 {  printf("Not enough memory!\n");
    return 0; 
 } 
 }

 int main()
{
   char number[10]; 
   int n;
   char * array;
   
   printf("Enter a number.\n");

   fgets(number, 9, stdin);
   n=atoi(number);

   array=alloc(n);



 }