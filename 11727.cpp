//
//  11727.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 23..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int value[1001];

int df(int x){
    value[1] = 1;
    value[2] = 3;
    
    for(int i=3; i<=x; i++){
        value[i] = (value[i-1] + 2*value[i-2])%10007;
    }
    
    return value[x];
}

int main(){
    int n;
    cin >> n;
    
    cout << df(n) << "\n";
}
