//
//  2056_topological_sort.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 12..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

queue<int> q;
vector<int> v[10005];
int work[10005];
int ind[10005];
int result[10005];

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> work[i];
        cin >> ind[i];
        for(int j=0; j<ind[i]; j++){
            int temp;
            cin >> temp;
            v[temp].push_back(i);
        }
    }
    
//    for(int i=1; i<=n; i++){
//        cout << "i:" << i << "->";
//        for(int j=0; j<v[i].size(); j++){
//            cout << v[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    
//    for(int i=1; i<=n; i++){
//        cout << ind[i] << " ";
//    }
//    cout << "\n";
//    for(int i=1; i<=n; i++){
//        cout << work[i] << " ";
//    }
    
    for(int i=1; i<=n; i++){
        if(ind[i] == 0){
            q.push(i);
            result[i] = work[i];
        }
    }
    
    for(int i=1; i<=n; i++){
        int x = q.front();
        q.pop();
        
        for(int j=0; j<v[x].size(); j++){
            int y = v[x][j];
            ind[y] -= 1;
            if(result[y] < result[x] + work[y]){
                result[y] = result[x] + work[y];
            }
            if(ind[y]==0){
                q.push(y);
                //cout << y << "," << result[y] << "," << result[x] << "," << work[x] << "\n";
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(ans < result[i]){
            ans = result[i];
        }
    }
    cout << ans << "\n";
    
    return 0;
}
