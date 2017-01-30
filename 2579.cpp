//
//  2579.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 31..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int d[301][3];
int a[301];

int main(){
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    d[1][1] = a[1];
    
    for(int i=2; i<=n; i++){
        d[i][2] = d[i-1][1] + a[i];
        d[i][1] = max(d[i-2][1], d[i-2][2]) + a[i];
    }
    
    cout << max(d[n][1], d[n][2]) << "\n";
}
