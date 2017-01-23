//
//  11052.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 23..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int value[10001];

int df(int x){
    
    for(int i=2; i<=x; i++){
        for(int j=i-1; j>=(i/2); j--){
            if(value[i] < value[j] + value[i-j]){
                value[i] = value[j] + value[i-j];
            }
        }

    }
    
    return value[x];
}

int main(){
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> value[i];
    }
    
    cout << df(n) << "\n";
    
    return 0;
}
