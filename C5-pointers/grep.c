// Program that gets a file name and a query string from command line and prints all the 
// lines in the file that contain the query string.
//Usage: grep filename query

#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{ 
    char* filename, *query;
    char line[1000];
    FILE* fptr;

    if(argc<2)  
    {
        printf("Two arguments are needed!\n");
        return 1;
    }

    filename=argv[0];
    query=argv[1];

    fptr=fopen(filename, "r");

    if (fptr==NULL)
    {
       printf("Could not open the file!\n");
       return 1;
    }

    while(fgets(line,1000,fptr)!=NULL)
    {
        if(strstr(line, query)!=NULL)
        {
            printf("%s", line);
        }
    }

    fclose(fptr);

}