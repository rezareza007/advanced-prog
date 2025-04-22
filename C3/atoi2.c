#include <ctype.h>
#include <stdio.h>

#define MAXLINE 25 /* length of maximum line input */

int getLine(char line[], int maxline);
int atoi(char s[]);

int main(int argc, char *argv[]) {
  int len;            /* length of input line */
  char line[MAXLINE]; /* array to store line input. */

  printf("Please enter an integer value: ");
  while ((len = getLine(line, MAXLINE)) > 0) {
    printf("%d\n", atoi(line));
    printf("Please enter an integer value: ");
  }

  return 0;
}

/* getLine: read a line into s, return length */
int getLine(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* atoi: convert s to integer; version 2 */
int atoi(char s[]) {
  int i, n, sign;

  for (i = 0; isspace(s[i]); i++) /* skip white space */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') /* skip sign */
    i++;
  for (n = 0; isdigit(s[i]); i++)
    n = 10 * n + (s[i] - '0');
  return sign * n;
}