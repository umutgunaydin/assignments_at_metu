#include <stdio.h>
#include <stdlib.h>

int isPath(char **lab,int size_of_row,int size_of_col,int x,int y);

int main() {
    int x, y;
    int i;
    int j = 0;
    int size_of_row;
    int size_of_col;
    char temp;
    char **labyrinth;
    char first_row[100000];
    int result;

    scanf("%d %d\n", &x, &y);

    for (i = 0; i < 100000; i++) {
        if (scanf("%c", &temp) == EOF || temp == '\n') {
            first_row[i] = temp;
            break;
        } else {
            first_row[i] = temp;
        }
    }
    size_of_row = i + 1;
    size_of_col = 100000;

    labyrinth = (char **)malloc(sizeof(char *) * size_of_col);
    labyrinth[0] = (char *)malloc(sizeof(char) * size_of_row);
    for (i = 0; i < size_of_row; i++) {
        labyrinth[0][i] = first_row[i];
    }

    for (j = 1; j < size_of_col; j++) {
        if (scanf("%c", &temp) == EOF || temp == '\n') {
            break;
        }
        labyrinth[j] = (char *)malloc(sizeof(char) * size_of_row);
        labyrinth[j][0] = temp;

        for (i = 1; i < size_of_row; i++) {
            scanf("%c", &temp);
            if (temp == EOF || temp == '\n') {
                labyrinth[j][i] = '\n';
                break;
            } else {
                labyrinth[j][i] = temp;
            }
        }

    }
    size_of_col=j;

    result=isPath(labyrinth,size_of_row-1,size_of_col,x,y);
    if (result==1){
        for (j = 0; j < size_of_col; j++) {
            for (i = 0; i<size_of_row-1; i++) {
                if (labyrinth[j][i]=='.'){
                    labyrinth[j][i]='*';
                }
            }

        }
    }

    for (j = 0; j < size_of_col; j++) {
        for (i = 0; labyrinth[j][i] != '\0'; i++) {
            printf("%c", labyrinth[j][i]);
        }

    }

    for (j = 0; j < size_of_col; j++) {
        free(labyrinth[j]);
    }
    free(labyrinth);

    return 0;


}

int isPath(char **lab,int size_of_row,int size_of_col,int x,int y){

    if (x<0||x>=size_of_row||y<0||y>=size_of_col){
        return 1;
    }
    if (lab[y][x]=='X'||lab[y][x]=='.'){
        return 0;
    }

    lab[y][x]='.';

    return isPath(lab,size_of_row,size_of_col,x-1,y)||
    isPath(lab,size_of_row,size_of_col,x+1,y)||
    isPath(lab,size_of_row,size_of_col,x,y-1)||
    isPath(lab,size_of_row,size_of_col,x,y+1);

}

