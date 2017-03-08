//
//  2512.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 8..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int sum = 0;
    int limit;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
        sum += v[i];
    }
    cin >> limit;
    
    sort(v.begin(), v.end());
    
    if(sum > limit){ //충족x
        int l = 1;
        int r = limit;
        int ans = 0;
        
        while(l<=r){// l  min  r
            int mid = (l+r)/2;
            int save = 0;
            for(int i=0; i<n; i++){
                if(v[i] > mid){
                    save += mid;
                }
                else{
                    save += v[i];
                }
            }
            
            if(save > limit){ //mid를 낮춰야함
                r = mid-1;
            }
            
            else{
                if(ans < mid){
                    ans = mid;
                }
                l = mid+1;
            }
        }
        cout << ans << "\n";
    }
    else{ //충족o
        cout << v[n-1] << "\n";
    }
    
    return 0;
}
