//
//  1049.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 2..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> pack(m);
    vector<int> unit(m);
    
    for(int i=0; i<m; i++){
        int t1, t2;
        cin >> t1 >> t2;
        pack[i] = t1;
        unit[i] = t2;
    }
    
    sort(pack.begin(), pack.end());
    sort(unit.begin(), unit.end());
    
    int ans = 1000000000;
    if(n<6){
        ans = min(n*unit[0], 1*pack[0]);
    }
    else{
        if(n%6==0){
            ans = min((n/6)*pack[0], n*unit[0]);
        }
        else{
            ans = min(min((n/6+1)*pack[0], (n/6)*pack[0]+(n%6)*unit[0]), n*unit[0]);
        }
        
    }
    
    cout << ans <<"\n";
    
    return 0;
}
