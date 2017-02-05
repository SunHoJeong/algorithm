//
//  1563.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 2..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int d[1001][2][3];

int main(){
    int n;
    cin >> n;
    
    d[1][0][0] = 1;
    d[1][0][1] = 1;
    d[1][1][0] = 1;

    for(int i=2; i<=n; i++){
        d[i][0][0] = (d[i-1][0][0]+d[i-1][0][1]+d[i-1][0][2])%1000000;
        d[i][0][1] = d[i-1][0][0]%1000000;
        d[i][0][2] = d[i-1][0][1]%1000000;
        d[i][1][0] = (d[i-1][0][0]+d[i-1][0][1]+d[i-1][0][2]
                    +d[i-1][1][0]+d[i-1][1][1]+d[i-1][1][2])%1000000;
        d[i][1][1] = d[i-1][1][0]%1000000;
        d[i][1][2] = d[i-1][1][1]%1000000;
    }
    
    long long ans = 0;
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            ans += d[n][i][j];
            ans %= 1000000;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
