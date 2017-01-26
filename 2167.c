//
//  2167.c
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 26..
//  Copyright © 2017년 수노. All rights reserved.
//
#include <stdio.h>

int i, j, x, y;
int arr[300][300] = { 0, };


int add(int row, int col) {
    int a = 0;
    int b = 0;
    int sum = 0;
    for (a = i; a <= x; a++) {
        
        for (b = j; b <= y; b++) {
            
            sum += arr[a][b];
            //printf("--%d--\n", arr[a][b]);
            
        }
    }
    return sum;
}

void input() {
    int row = 0, col = 0;
    int k;
    int a,b,c;
    
    scanf("%d %d", &row, &col);
    for (b = 1; b <= row; b++) {
        for (c = 1; c <= col; c++) {
            scanf("%d", &arr[b][c]);
        }
    }
    
    /*for (b = 1; b <= row; b++) {
     for (c = 1; c <= col; c++) {
     printf("%d ", arr[b][c]);
     }
     printf("\n");
     }*/
    
    
    scanf("%d", &k);
    for (a = 1; a <= k; a++) {
        scanf("%d %d %d %d", &i, &j, &x, &y);
        //printf("%d %d %d %d", i, j, x, y);
        printf("%d\n", add(row,col));
    }
    
}


int main() {
    
    input();
}
