#include<stdio.h>

static char daytab[2][13] = { 
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} 
    }; 

/* month_day: set month, day from day of year */ 
 void month_day(int year, int yearday, int *pmonth, int *pday) 
 { 
 int i, leap; 
 leap = year%4 == 0 && year%100 != 0 || year%400 == 0; 
 for (i = 1; yearday > daytab[leap][i]; i++) 
 yearday -= daytab[leap][i]; 
 *pmonth = i; 
 *pday = yearday; 
 } 

 int main()
 {  
    int year=2025, yearday=200, month, day;

    month_day(year, yearday, &month, &day);

    printf("%d, %d", month, day);



 }