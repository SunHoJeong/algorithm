//
//  2193.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 25..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

long long d[91][2];
int main(){
    int n;
    cin >> n;
    
    d[1][0] = 0;
    d[1][1] = 1;
    
    for(int i=2; i<=n; i++){
        d[i][0] = d[i-1][1] + d[i-1][0];
        d[i][1] = d[i-1][0];
    }
    
    long long ans = 0;
    ans = d[n][0] + d[n][1];
    cout << ans << "\n";
    return 0;
}
