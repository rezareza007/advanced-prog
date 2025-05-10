/* strlen: return length of string s */ 
#include <stdio.h>

 int strlen(char *s) 
 { 
 int n; 
 for (n = 0; *s != '\0'; s++) 
 n++; 
 return n; 
 } 

int main()
{
    char s[]="Today is Saturday.";
    int n;
    printf("%d\n", s);
    n=strlen(s);

    printf("%d\n", s);


}