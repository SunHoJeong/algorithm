//
//  2156.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 25..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[10001][3];

int main(){
    int n;
    cin >> n;
    
    vector<int> v(n+1);
    
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    
    d[1][0] = 0;
    d[1][1] = v[1];
    d[1][2] = 0;
    
    for(int i=2; i<=n; i++){
        int temp = max(d[i-1][0], d[i-1][1]);
        d[i][0] = max(temp, d[i-1][2]);
        d[i][1] = d[i-1][0] + v[i];
        d[i][2] = d[i-1][1] + v[i];
    }
    
    long long ans = 0;
    ans = max(max(d[n][0] , d[n][1]) , d[n][2]);
    //cout << d[n][0] << "," << d[n][1] << "," << d[n][2] << "\n";
    cout << ans << "\n";
    return 0;
}
