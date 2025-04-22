#include <stdio.h>
#include <string.h>

#define MAXLINE 100 /* maximum line length for strings */

int getLine(char line[], int maxline);
void reverse(char s[]);

int main(int argc, char *argv[]) {
  int len;              /* length of input line */
  char string[MAXLINE]; /* for storing strings */

  while ((len = getLine(string, MAXLINE)) > 0) {
    reverse(string);
    printf("%s\n", string);
  }

  return 0;
}

/* getLine: read a line into s, return length */
int getLine(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

/* reverse: reverse string s in place */
void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    c = s[i], s[i] = s[j], s[j] = c;
}

#include <string.h>
void reverse(char s[]) {
    int temp, i;
    int n = strlen(s);
    for(i = 0; i < n/2; i++) {
        temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
        
    }
}