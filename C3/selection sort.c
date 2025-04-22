#include<stdio.h>


int max(int A[] , int n); // Returns the index of the maximum of A[:n]

int selection_sort(int A[], int N); //Sorts the array A in place


int main()
{
    int i;
    int A[8]={9,6,7,3,5,4,2,1};

    selection_sort(A, 8);

    

}

int max(int A[] , int n) // Returns the index of the maximum of A[:n]
{
    int i, max=0;

   for(i=0 ; i<n ; ++i)
   {
       if (A[i]>A[max] )  max=i;

   }

   return max;

}


int selection_sort(int A[], int N) //Sorts the array A in place
{
  int m, temp, i;

  for(; N>1; N--)
  {
      m=max(A,N);
      if (A[m]> A[N-1])
      {
        temp=A[m];
        A[m]=A[N-1];
        A[N-1]=temp;

      }
      for (i=0;i<8; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

  }

}