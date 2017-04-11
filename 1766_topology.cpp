//
//  1766_topology.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 11..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int ind[32005];
vector<int> v[32005];
priority_queue<int, vector<int>, greater<int>> q;

int main(){
    int n,m;
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int t1, t2;
        cin >>t1 >> t2;
        v[t1].push_back(t2);
        ind[t2] += 1;
    }
    
    for(int i=1; i<=n; i++){
        if(ind[i] == 0){
            q.push(i);
        }
    }
    
    for(int i=0; i<n; i++){
        int x = q.top();
        cout << x << " ";
        q.pop();
        
        for(int a : v[x]){
            int temp = a;
            ind[temp] -= 1;
            if(ind[temp] == 0){
                q.push(temp);
            }
        }
    }
    cout << "\n";
    
    return 0;
}
