//
//  2747.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 7. 28..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int d[46];

int main(){ //d[n] = d[n-1] + d[n-2]
    
    d[0] = 0;
    d[1] = 1;
    
    for(int i=2; i<=45; i++){
        d[i] = d[i-1] + d[i-2];
    }
    
    int n;
    cin >> n;
    cout << d[n] << "\n";
    
    return 0;
}
