//
//  1912.c
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 30..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[100001];

int main(){
    int n;
    int ans = 0;
    cin >> n;
    vector<int> v(n);
    
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    d[0] = v[0];
    ans = d[0];
    //cout << ans << "," << v[0] <<"\n";
    for(int i=1; i<n; i++){
        d[i] = max(d[i-1]+v[i], v[i]);
        if(d[i] > ans){
            ans = d[i];
        }
    }
   
    cout << ans << "\n";
    
    return 0;
}
