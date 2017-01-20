//
//  6603.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 18..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
vector<int> lot;

void lotto(vector<int> &v, int index, int depth){
    if(depth == 6){
        for(int x : lot){
            printf("%d ", x);
        }
        printf("\n");
        return;
    }
    
    int len = v.size();
    if(index == len)
        return;
    
    lot.push_back(v[index]);
    lotto(v, index+1, depth+1);
    lot.pop_back();
    lotto(v, index+1, depth);
}

int main(){
    while(true){
        int n;
        cin >> n;
        
        if(n==0)
            break;
        
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        lotto(v, 0, 0);
        cout << "\n";
    }
    
    return 0;
    
    
}
