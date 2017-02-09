//
//  1744.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 7..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> pl;
    vector<int> mi;
    int zero=0;
    int one=0;

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        
        if(temp == 1){
            one += 1;
        }
        else if(temp > 0){
            pl.push_back(temp);
        }
        else if(temp < 0){
            mi.push_back(temp);
        }
        else {
            zero += 1;
        }
    }
    
    sort(pl.begin(), pl.end());
    reverse(pl.begin(), pl.end());
    sort(mi.begin(), mi.end());
    
    if(pl.size() %2 == 1){
        pl.push_back(1);
    }
    if(mi.size() %2 == 1){
        if(zero>0){
            mi.push_back(0);
        }
        else{
            mi.push_back(1);
        }
    }
    
    int ans = one;
    
    for(int i=0; i< pl.size(); i+=2){
        ans += pl[i]*pl[i+1];
    }

    for(int i=0; i<mi.size(); i+=2){
        ans += mi[i]*mi[i+1];
    }
    
    cout << ans << "\n";
    return 0;
}
