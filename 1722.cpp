//
//  1722.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 3..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

long long value[21];

using namespace std;

long long fac(int x){
    if(x==1){
        return 1;
    }
    return x*fac(x-1);
}

int main(){
    int n;
    cin >> n;
    int c;
    cin >> c;
    
    for(int i=1; i<=20; i++){
        value[i] = fac(i);
        cout << value[i] << "\n";
    }
    
    if(c==1){
        
    }
    else if(c==2){
        
    }
    return 0;
}
