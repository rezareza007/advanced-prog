#include <stdio.h> 
 #include <ctype.h> 
 #include <string.h> 
 
 #define MAXWORD 100 
 int getword(char *, int); 

 struct key { 
    char *word; 
    int count; 
    };
    
    struct key keytab[] = 
    { 
    "auto", 0, 
    "break", 0, 
    "case", 0, 
    "char", 0, 
    "const", 0, 
    "continue", 0, 
    "default", 0, 
    /* ... */ 
    "unsigned", 0, 
    "void", 0, 
    "volatile", 0, 
    "while", 0 
    };

int NKEYS =11;


/* binsearch: find word in tab[0]...tab[n-1] */ 
int binsearch(char *word, struct key tab[], int n) 
{ 
   int cond; 
   int low, high, mid; 
   low = 0; 
   high = n - 1; 
   while (low <= high) 
   { 
       mid = (low+high) / 2; 
       if ((cond = strcmp(word, tab[mid].word)) < 0) 
           high = mid - 1; 
       else if (cond > 0) 
           low = mid + 1; 
       else 
           return mid; 
       } 
   return -1; 
} 


 /* count C keywords */ 
 int main(int argc, char* argv[]) 
 { 
    if( argc<1)
    {
       printf("Please supply a file name!\n");
       return 1;
    }

    char *filename=argv[1];
    FILE* f;
    f=fopen(filename, "r");

    if (f==NULL)
    {
        printf("%s", "Can't open the file!\n");
        return 1;
    }

    int n; 
    char word[MAXWORD]; 

    while ( fscanf(f, "%s", word, MAXWORD)!=EOF )
    {
        //printf("%s\n", word);
        //if (isalpha(word[0])) 
        n = binsearch(word, keytab, NKEYS);
        if (n >= 0) 
            keytab[n].count++; 

    
     }

    fclose(f);

        for (n = 0; n < NKEYS; n++) 
        { if (keytab[n].count > 0) 
            printf("%4d %s\n", keytab[n].count, keytab[n].word); 
        }
        return 0; 
 } 
 