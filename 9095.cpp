//
//  9095.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 18..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int sol(int depth, int sum,  int goal){
    if(depth > 10){
        return 0;
    }
    if(sum > goal){
        return 0;
    }
    if(sum == goal){
        return 1;
    }
    
    int temp =0;
    
    for(int i=1; i<=3; i++){
        temp += sol(depth+1, sum+i, goal);
    }
    
    return temp;
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        cout << sol(0, 0, n) << "\n";
    }
    
    return 0;
}
