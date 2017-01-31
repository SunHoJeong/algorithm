//
//  10872.cpp
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
    int ans = 1;
    for(int i=1; i<=n; i++){
        ans *=i;
    }
    
    cout << ans << "\n";
    return 0;
}
