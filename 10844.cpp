//
//  10844.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 24..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int d[101][11];

int main(){
    int n;
    cin >> n;
    
    for(int i=1; i<=9; i++){
        d[1][i] = 1;
    }
    for(int i=2; i<=n; i++){
        for(int j=0; j<=9; j++){
            d[i][j] = 0;
            if(j-1 >=0){
                d[i][j] += d[i-1][j-1];
            }
            if(j+1 <=9){
                d[i][j] += d[i-1][j+1];
            }
            d[i][j] %= 1000000000;
        }
    }
    
    long long ans =0;
    for(int i=0; i<=9; i++){
        ans += d[n][i];
    }
    ans %= 1000000000;
    
    cout << ans <<"\n";
    
    return 0;
}
