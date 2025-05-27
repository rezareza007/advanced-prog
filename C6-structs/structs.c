#include<stdio.h>
#include<math.h>

struct point
   {
    /* data */
    float x;
    float y;
   };

float norm(struct point pt)
{
   return sqrt(pt.x*pt.x+pt.y*pt.y  );
}   

float dist(struct point pt1, struct point pt2)
{
    return norm(subtract(pt1,pt2));
}

struct point subtract(struct point pt1, struct point pt2)
{ 
   struct point sub;

   sub.x=pt1.x-pt2.x;
   sub.y=pt1.y-pt2.y;

   return sub;
}
int main()
{
   
   struct point pt;

   pt.x=1;
   pt.y=0; 
   
   printf("%f, %f\n", pt.x, pt.y);
   

}