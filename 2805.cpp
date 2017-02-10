//
//  2805.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 10..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    long long l = 1;
    long long r = v[n-1];
    long long mid;
    long long ans = 0;
    
    while(l<=r){
        mid = (l+r)/2;
//        cout << mid << "\n";
        
        long long cnt = 0;
        
        for(int i=0; i<n; i++){
            if(mid < v[i]){
                cnt += v[i]-mid;
            }
        }
        
        if(cnt >= m){
            if(ans < mid){
                ans = mid;
            }
            l = mid +1;
            }
        else{
            r = mid - 1;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
