// Copies the string s into the string t while removing the 
// decimal point. Returns the number of digits after the decimal point
#include<stdio.h>

int remove_point(char s[], char t[]){
    int i;
    int num_digits=0; // Number of digits after decimal point
    int reached_point=0; 
    
    for (i=0; s[i]!='\0' ;  i++) 
    {
           if(s[i]!='.') 
           { 
              if (reached_point) 
              { num_digits++;
                   t[i-1]=s[i] ;
              }
              else 
              {
                t[i]=s[i];
              }
           }
           else{
               reached_point=1;
           }
    }

    t[i]='\0';


    return num_digits;

}

float atof(char s[])
{

    char t[100];
    int num_digits, i;
    float f;
    num_digits=remove_point(s,t);
    
    f=atoi(t);

    for (i=0; i<num_digits; i++)
       f/=10;

    return f;   


}

int main()
{
    char s[]="1532.6410";
    char t[20];
    int num_digits;

    num_digits=remove_point(s,t);

    printf("%s\n %d", t, num_digits);
    

}