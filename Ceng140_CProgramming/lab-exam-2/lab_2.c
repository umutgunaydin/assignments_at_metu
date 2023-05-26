#include <math.h>
#include <stdio.h>

#include "lab_2.h"


/*
    This function takes:
        - array of floats (Arr)
        - the size of the array (size)
    as parameters and modifies the contents of Arr with
    normalized values as explained in the description
*/
void minMaxNorm(float Arr[], int size)
{
    /* 
       THIS FUNCTION DOES NOT RETURN ANYTHING
       you only have to update the values of Arr
    */
    int i;
    float max=0.0, min=200.0;
    
    for(i=0;i<size;i++){
        if(max<Arr[i]){
            max=Arr[i];
        }
        if(min>Arr[i]){
            min=Arr[i];
        }
    }
    
    for(i=0;i<size;i++){
        Arr[i]=(Arr[i]-min)/(max-min);
    }
    
    
    
}

/*
    This function takes:
        - data of 3D vectors (Vecs)
        - number of 3D vectors inside array Vecs (vecSize)
        - a 3D vector to be compared with vectors of Vecs array (Comp)
    as parameters and PRINTS
        - the 3D vector inside "Vecs" that has the highest similarity
          score with the "Comp" vector
        - index of the vector with highest similarity score
*/
void cosineSimilarity(float Vecs[], int vecSize, float Comp[])
{
    /*
        THIS FUNCTION DOES NOT RETURN ANYTHING
        use printfs for printing
    */
    int i;
    float cos_sims[100];
    float max=0.0;
    int index;
    for(i=0;i<vecSize*3;i=i+3){
    
        cos_sims[i]=(Vecs[i]*Comp[0]+Vecs[i+1]*Comp[1]+Vecs[i+2]*Comp[2])
        /(sqrt(pow(Vecs[i],2)+pow(Vecs[i+1],2)+pow(Vecs[i+2],2))*sqrt(pow(Comp[0],2)+pow(Comp[1],2)+pow(Comp[2],2)));
        if(max<cos_sims[i]){
            max=cos_sims[i];
            index=i/3+1;
        }
    }
    
    printf("V%d %.4f",index,max);
    
    
}

/*
    This function takes:
        - width of the frame (width)
        - height of the frame (height)
        - 2D vertices of ObjA (ObjA)
        - 2D vertices of ObjB (ObjB)
        - 2D translate commands for the camera (TranslateCommands)
    as parameters and prints the resulting 2D grid as explained in the description
*/
void eraseCollisions(int n, int m,
                     int ObjA[], int ObjB[],
                     int width, int height,
                     int TranslateCommands[], int commandCount)
{
    /*
        THIS FUNCTION DOES NOT RETURN ANYTHING
        use printfs for printing
    */  
    char frame[200][200];
    int i,j;
    int totalX=0;
    int totalY=0;
    
     for(i=0;i<commandCount*2;i++){
        
        if(i%2==0){
            totalX+=TranslateCommands[i];
        }else{
            totalY+=TranslateCommands[i];
        }
        
    }
    
    for(i=0;i<n*2;i=i+2){
        frame[ObjA[i+1]-totalY][ObjA[i]-totalX]='a';
    }
    for(i=0;i<m*2;i=i+2){
        if(frame[ObjB[i+1]-totalY][ObjB[i]-totalX]=='a'){
              frame[ObjB[i+1]-totalY][ObjB[i]-totalX]='-';
              continue;
        }
        frame[ObjB[i+1]-totalY][ObjB[i]-totalX]='b';
    }
    
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            
            if(j==width-1){
                if(frame[i][j]=='a') printf("a");
                else if(frame[i][j]=='b') printf("b");
                else printf("-");
                
                continue;
            }
            
            
            if(frame[i][j]=='a') printf("a  ");
            else if(frame[i][j]=='b') printf("b  ");
            else printf("-  ");
        }
        if(i==height-1) continue;
        
        printf("\n");
    }
   
    
    
    
    
}




