//
//  1766.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 15..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[32005];
int ind[32005];
priority_queue<int, vector<int>, greater<int>> q;

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int t1, t2;
        cin >> t1 >> t2;
        v[t1].push_back(t2);
        ind[t2] += 1;
    }
    
    for(int i=1; i<=n; i++){
        if(ind[i]==0){
            q.push(i);
        }
    }
    
    for(int i=0; i<n; i++){
        int x = q.top();
        cout << x << " ";
        q.pop();
        
        for(int j=0; j<v[x].size(); j++){
            int temp = v[x][j];
            ind[temp] -= 1;
            if(ind[temp] == 0){
                q.push(temp);
            }
        }
    }
    cout << "\n";
    
    return 0;
}
