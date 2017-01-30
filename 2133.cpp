//
//  2133.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 31..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int d[31];
int main(){
    int n;
    cin >> n;
    
    d[0] = 1;
    
    for(int i=2; i<=n; i++){
        d[i] = 3*d[i-2];
        
        for(int j= i-4; j>=0; j-=2 ){
            d[i] += d[j]*2;
        }
    }
    
    cout << d[n] <<"\n";
    return 0;
}
