//
//  1912_dp.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 7..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int d[100001];

int main(){
    int n;
    int a[100001];
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    
    //d[n] == n까지의 최대합
    d[1] =a[1];
    int ans = d[1];
    
    for(int i=2; i<=n; i++){
        d[i] = max(d[i-1]+a[i], a[i]);
        if(ans < d[i]){
            ans = d[i];
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
