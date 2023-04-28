#include "pointerUpdate.h"

void update(int * arr[], int length){
    int i;
    int *addressOfRealArr=arr[0];

    for (i = 0; i < length; i++) {
        arr[i] = addressOfRealArr + ((*arr[i])%length);
    }

}