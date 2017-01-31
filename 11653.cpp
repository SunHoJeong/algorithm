//
//  11653.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 31..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    if(n==1){
        return 0;
    }
    else{
        for(int i=2; n>1; i++){
            while(n%i == 0){
                cout << i << "\n";
                n /= i;
            }
        }
    }
    return 0;
}
