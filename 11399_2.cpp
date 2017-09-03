//
//  11399_2.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 9. 4..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    int answer = 0;
    
    for(int i=0; i<n; i++){
        answer += v[i] * (n-i);
    }
    
    cout << answer << "\n";
    
    return 0;
}
