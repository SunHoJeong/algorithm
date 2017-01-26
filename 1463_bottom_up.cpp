//
//  1463_bottom_up.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 24..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int memo[1000001];
int n;

int main(){
    int n;
    
    cin >> n;
    
    memo[1] = 0;
    
    for(int i=2; i<=n; i++){
        memo[i] = memo[i-1] +1;
        if(i%2 == 0){
            int temp = memo[i/2] + 1;
            if(memo[i] > temp){
                memo[i] = temp;
            }
        }
        if(i%3 == 0){
            int temp = memo[i/3] +1;
            if(memo[i] > temp){
                memo[i] = temp;
            }
        }
    }
    
    cout << memo[n] << "\n";
    
    return 0;
    
}
