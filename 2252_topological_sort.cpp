//
//  2252_topological_sort.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 12..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[32005];
queue<int> q;
int ind[32005];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        v[temp1].push_back(temp2);
        ind[temp2] += 1;
    }
    
    for(int i=1; i<=n; i++){
        if(ind[i] == 0){
            q.push(i);
        }
    }
    
    for(int i=0; i<n; i++){
        int x = q.front();
        q.pop();
        cout << x << " ";
        for(int j=0; j<v[x].size(); j++){
            int a = v[x][j];
            ind[a] -= 1;
            if(ind[a] == 0){
                q.push(a);
            }
        }
    }
    
    cout <<"\n";
    return 0;
}
