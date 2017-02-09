//
//  2875.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 6..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    
    int ans =0;
    while(n>=2 && m>=1 && m+n >= k+3){
        n -= 2;
        m -= 1;
        ans += 1;
    }
    cout << ans << "\n";
    return 0;
}
