#include <stdio.h>

struct point
{
    float x;
    float y;
};

struct rect
{
    struct point pt1;
    struct point pt2;
}

int main()
{
    struct point pt={0,1};
    struct point ptt={1,2};
    struct point *spt;

    spt=&pt;
    
    printf("%f,  %f\n", spt -> x, spt -> y );

    struct rect R;

    R.pt1=pt;
    R.pt2=ptt;

    struct rect * rectpt=&R;

    rectpt ->pt1.x == R.pt1.x;

}