//
//  2293.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 6..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int d[10001];
int n, goal;

int main(){
    cin >> n >> goal;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    d[0] = 1;
    
    for(int i=0; i<n; i++){
        for(int j=v[i]; j<=goal; j++){
            if(d[j-v[i]] >=0){
                d[j] += d[j-v[i]];
            }
        }
    }
    
    cout << d[goal] << "\n";
    
    return 0;
}


//int dp(vector<int>& v, int x){
//    if(x <= 0)
//        return 0;
//    
//    if(d[x] >0)
//        return d[x];
//    
//    for(int i=0; i<n; i++){
//        if(x-v[i] >= 0){
//            d[x] += dp(v, x-v[i]);
//
//        }
//    }
//    
//    return d[x];
//}
//
//int main(){
//    cin >> n >> goal;
//    vector<int> v(n);
//
//    for(int i=0; i<n; i++){
//        cin >> v[i];
//        d[v[i]] = 1;
//    }
//    
//    // 51 222 2211 21111 111111
//    dp(v, goal);
//    for(int i=1; i<=goal; i++){
//        cout << i << ":" << d[i] << "\n";
//    }
//    cout << d[goal] << "\n";
//    
//    return 0;
//}
