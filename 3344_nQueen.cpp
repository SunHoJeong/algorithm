//
//  3344_nQueen.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 28..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <stdlib.h>

using namespace std;

bool promissing(int a[], int n, int row){
    if(row < 1)
        return true;
    else{
        for(int i=0; i<row; i++){
            if(a[i] == a[row] || row-i == abs(a[row]-a[i])){
                return false;
            }
        }
    }
    
    return true;
}

void n_queen(int a[], int n, int row){
    
    for(int i=0; i<n; i++){
        a[row] = i;
        if(promissing(a, n, row)){
            if(row == n-1){
                for(int k=0; k<n; k++){
                    printf("%d\n", a[k]+1);
                }
                exit(0);
            }
            else{
                n_queen(a, n, row+1);
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    
    n_queen(a, n, 0);
    
    
    return 0;
}
