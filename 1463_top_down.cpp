//
//  1463_top_down.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 24..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;
int memo[1000001];

int dp(int x){
    if(x==1){
        return 0;
    }
    if(memo[x] >0){
        return memo[x];
    }
    
    memo[x] =dp(x-1)+1;
    
    if(x%3 == 0){
        int temp = dp(x/3) +1;
        if(memo[x] > temp){
            memo[x] = temp;
        }
    }
    
    if(x%2 == 0){
        int temp = dp(x/2) +1;
        if(memo[x] > temp){
            memo[x] = temp;
        }
    }
    
    return memo[x];
}

int main(){
    int n;
    cin >> n;
    cout << dp(n) << "\n";
    
}
