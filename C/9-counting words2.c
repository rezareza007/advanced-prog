#include<stdio.h>

#define IN 0
#define OUT 1

/* count lines, words, and characters in input */ 
main() 
{ 
int c, nl, nw, nc, state; 
state = OUT; 
nl = nw = nc = 0; 
while ((c = getchar()) != EOF) { 
++nc; 
if (c == '\n') 
++nl; 

//When we encounter a white space, it means we are outside words
if (c == ' ' || c == '\n' || c = '\t') 
    state = OUT; 
//Here c is NOT a white space and we have been outside a word
//This means we have got to the beginning of a word    
else if (state == OUT) 
{ 
    state = IN; 
    ++nw; 
} 
} 
printf("%d %d %d\n", nl, nw, nc); 
} 
