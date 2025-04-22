#include<stdio.h>

void escape(char s[],char t[]) {
    int i = 0, j = 0;

    while (s[i] != '\0') {
        switch (s[i]) {
            case '\t': 
                t[j] = '\\';
                j++;
                t[j] = 't';
                break;
            case '\n':
                t[j] = '\\';
                j++;
                t[j] = 'n';
                break;
            default:
                t[j] = s[i];
                break;
        }
        i++;
        j++;

        t[j]='\0';
    }


} 


int main ()
{

    char s[20]="Hamid\tReza";
    char t[20];

    escape(s,t);
    printf(s);
    printf("\n");
    printf(t);
}