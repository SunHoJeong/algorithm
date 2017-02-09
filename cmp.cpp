//
//  cmp.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 9..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const int &v, const int &u){
    if(v<u){
        return false;
    }
    else
        return true;
}

int main(){
    vector<int> v(10);
    for(int i=0; i<10; i++){
        cin >> v[i];
    }
    for(auto item: v){
        cout << item<< " ";
    }
    cout << "\n";
    
    sort(v.begin(), v.end(),cmp);
    
    for(auto item : v){
        cout << item << " ";
    }
    cout << "\n";
    return 0;
}
