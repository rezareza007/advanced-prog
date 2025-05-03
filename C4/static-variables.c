#include<stdio.h>

void f(void);

int main()
{
f();
f();
}

void f(void)
{
   static int i=2;
   printf("%d\n", i);

   i++;

}
