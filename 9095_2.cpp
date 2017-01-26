//
//  9095_2.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 24..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int d[12];

int dp(int x){
    if(x<1){
        return 0;
    }
    
    if(d[x] >0){
        return d[x];
    }
    
    d[x] = dp(x-1) + dp(x-2) + dp(x-3);
    
    return d[x];
}

int main(){
    int n;
    cin >>n;
    d[1] =1;
    d[2] =2;
    d[3] =4;
    cout << dp(n) << "\n";
    for(int i=1; i<5; i++){
        cout << "i:"<<i<<":"<<d[i] << "\n";
    }
    
    return 0;
}
