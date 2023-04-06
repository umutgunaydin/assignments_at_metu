#include <stdio.h>
#include <math.h>

int main()
{
    int i;
    int xcoors[10];
    int ycoors[10];
    int givenX;
    int givenY;
    int nearestPointIndex=0;
    float distance;
    float minDistance;
    
    for (i=0; i<10; i++){
        scanf("%d ", &xcoors[i]);
    }
    
    for (i=0; i<10; i++){
        scanf("%d ", &ycoors[i]);
    }
    

    scanf("\n%d\n%d", &givenX, &givenY);

    minDistance=sqrt(pow(xcoors[0]-givenX, 2)+pow(ycoors[0]-givenY, 2));

    for(i=0; i<10;i++){

        distance=sqrt(pow(xcoors[i]-givenX, 2)+pow(ycoors[i]-givenY, 2));

        if(distance<minDistance){
            minDistance=distance;
            nearestPointIndex=i;
        }
    }

    printf("P = (%d,%d), nearest point index = %d, distance = %.1f\n", givenX, givenY, nearestPointIndex, minDistance);

    return 0;

}