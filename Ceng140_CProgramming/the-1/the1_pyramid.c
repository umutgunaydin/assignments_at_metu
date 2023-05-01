#include <stdio.h>

double calculate_pressure_on_block(int row, int column, double block_weight) {
    double left_pressure = 0.0;
    double right_pressure = 0.0;
    double total_pressure = 0.0;
    /* if it's the top row, there is no pressure on it */
    if (row == 0) {
        return 0.0;
    }


    /* calculating the pressure on the upper left and upper right blocks exerted on current block */
    if (row > 0 && column > 0) {
        left_pressure = block_weight / 2.0 + calculate_pressure_on_block(row - 1, column - 1, block_weight) * 0.15;
    }
    if (row > 0 && column < row) {
        right_pressure = block_weight / 2.0 + calculate_pressure_on_block(row - 1, column, block_weight) * 0.15;
    }

    total_pressure = left_pressure + right_pressure;
    return total_pressure;
}

void print_pressures(int row,int column,int layer,int weight){
    if(row>=layer){
        return;
    }
    if(row==0){
        printf("(%d,%d) %.8f\n", row, column, 0.0);
        print_pressures(row+1,column,layer,weight);
        return;
    }

    if(column<=row){
        printf("(%d,%d) %.8f\n", row, column, calculate_pressure_on_block(row,column,weight));
        print_pressures(row,column+1,layer,weight);
    }else{
        print_pressures(row+1,0,layer,weight);
    }
    return;
}

int main() {
    int N, W;
    scanf("%d %d", &N, &W);

    print_pressures(0,0,N,W);

    return 0;
}
