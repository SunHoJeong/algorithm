//
//  2662.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 23..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int com[21][21];
int main(){
    int n, comNum;
    cin >> n >> comNum;
    
    for(int i=1; i<=n; i++){
        int temp;
        cin >> temp;
        for(int j=1; j<=comNum; j++){
            cin >> com[temp][j];
        }
    }
 
    return 0;
}
