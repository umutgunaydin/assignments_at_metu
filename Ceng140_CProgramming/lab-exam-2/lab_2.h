#ifndef _LAB_2_
#define _LAB_2_

#define MAX_ARRAY_SIZE 100

void minMaxNorm(float Arr[], int size);

void cosineSimilarity(float Vecs[], int vecSize, float Comp[]);

void eraseCollisions(int n, int m,
                     int ObjA[], int ObjB[],
                     int width, int height,
                     int TranslateCommands[], int commandCount);

#endif