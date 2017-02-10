//
//  11399.cpp
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
    int n;
    cin >> n;
    v.resize(n);
    
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    int sum = 0;
    for(int i=1; i<=n; i++){
        int temp = 0;
        for(int j=0; j<i; j++){
             temp += v[j];
        }
        sum += temp;
    }
    
    cout << sum << "\n";
    return 0;
}
