//
//  1037.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 4..
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
    for(int i=1; i<=n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    cout << v.front() * v.back() << "\n";
    
    return 0;
}
