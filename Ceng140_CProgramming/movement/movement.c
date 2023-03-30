#include <stdio.h>

int main()
{
   
    char direction;
    int x;
    int y;
    int n;

    scanf("%c %d %d %d", &direction, &x, &y, &n);

    if (direction=='W' && x>0){
        x-=1;
    }else if (direction=='E' && x<n-1){
        x+=1;
    }else if (direction=='N' && y>0){
        y-=1;
    }else if (direction=='S' && y<n-1){
        y+=1;
    }
    
    printf("%d %d",x ,y);
    
    return 0;
}
