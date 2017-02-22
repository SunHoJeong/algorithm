//
//  2217.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 22..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int a[100000];
    cin >> n;
    for(int i=0; i<n; i++){
        int temp ;
        cin >> temp;
        a[i] = temp;
    }
    sort(a, a+n);
    
//    for(int i=0; i<n; i++){
//        cout << "i:" << v[i] << "\n";
//    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        //cout << i << "," << ans << "," << a[i-1] << ": " << a[i-1]*(n-i+1)<<"\n";
        if(ans < a[i-1]*(n-i+1)){
            ans = a[i-1]*(n-i+1);
        }
    }
    cout << ans << "\n";
    return 0;
}
