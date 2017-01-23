//
//  11726.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 23..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;
int value[1001];

int df(int n){
    value[1] = 1;
    value[2] = 2;
    for(int i=3; i<=n; i++){
        value[i] = (value[i-1]+ value[i-2])%10007;
    }
    return value[n];
}

int main(){
    int n;
    cin >> n;
    
    int result = df(n);
    cout << result <<"\n";
    return 0;
}
