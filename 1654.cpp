//
//  1654.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 10..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int main(){
    int k,n;
    cin >> k >> n;
    v.resize(k);
    for(int i=0; i<k; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long l = 1;
    long long r = v[k-1];
    long long mid;
    
    long long ans = 0;
    while(l<=r){
        long long cnt = 0;

        mid = (l+r)/2;
//        cout << "mid:" << mid << "\n";
        for(auto item : v){
            cnt += item/mid;
        }
//        cout << cnt << "\n";
        if(cnt >= n){
//            cout << mid << "\n";
            if(ans < mid){
                ans = mid;
            }
            l = mid+1;
        }

        else if( cnt < n){
            r = mid-1;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
