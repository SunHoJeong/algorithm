//
//  11057.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 25..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int d[1001][11];
int main(){
    int n;
    cin >> n;
    
    for(int i=0; i<=9; i++){
        d[0][i] = 0;
        d[1][i] = 1;
    }
    
    for(int i=2; i<=n; i++){ //N
        for(int j=0; j<=9; j++){ //L
            for(int k=0; k<=j; k++){
                d[i][j] += d[i-1][k];
                d[i][j] %= 10007;
            }
        }
    }
    long long ans = 0;
    for(int i=0; i<=9; i++){
        ans += d[n][i];
    }
    ans %= 10007;
    cout << ans << "\n";
    
    return 0;
}
