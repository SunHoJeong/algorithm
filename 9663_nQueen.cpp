//
//  9663.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 28..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int cnt = 0;

bool promissing(int a[], int n, int row){
    if(row <1)
        return true;
    
    for(int i=0; i<row; i++){
        if(a[row] == a[i] || row-i == abs(a[row] - a[i]))//같은 열과 대각선에 존재하는지 확인
            return false;
    }
    return true;
}

void n_queen(int a[], int n, int row){
    for(int i=0; i<n; i++){
        a[row] = i;
        if(promissing(a, n, row)){
            if(row== n-1){
                cnt ++ ;
            }
            else{
                n_queen(a, n, row+1);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    
    int a[n];
    
    n_queen(a, n, 0);
    
    cout << cnt << "\n";
    return 0;
}
