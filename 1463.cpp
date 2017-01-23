//
//  1463.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 23..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;
int value[1000001];

int df(int x){
    if(x==1){
        return 0;
    }
    if(value[x]>0){
        return value[x];
    }
    
    value[x] = df(x-1) +1;
    
    if(x%3 == 0){
        int temp = df(x/3)+1;
        if(value[x] > temp){
            value[x] = temp;
        }
    }
    
    if(x%2 == 0){
         int temp = df(x/2)+1;
        if(value[x] >temp){
            value[x] = temp;
        }
    }
    return value[x];
}

int main(){
    int n;
    cin >> n;
    int result = df(n);
    
    cout << result << "\n";
    return 0;
}
