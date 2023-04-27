#include <stdio.h>

int combinations(int n,int k);

int main(){
    int a=combinations(24,4);
    printf("%d",a);
}

int combinations(int n, int k) {
    printf("(%d %d)\n",n,k);
    if (n - k < k) {
        return combinations(n,n-k);
    }
    if (k < 1) {
        return 1;
    } else {
        return ((float )n /(float ) k) * combinations(n - 1, k - 1);
    }
}
