//
//  1697_2.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 26..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;
const int MAX = 100000;

int n, k;
queue<P> q;
bool visited[100001];
int from[100001];

int main(){
    cin >> n >> k;
    visited[n] = true;
    from[n] = -1;
    q.push(P(n,0));
    
    if(k==n){
        cout << 0 << "\n";
        cout << k << "\n";
        return 0;
    }
    
    int depth = 0;
    
    while(!q.empty()){
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(x == k ){
            depth = cnt;
            cout << depth << "\n";
            vector<int> v(depth+1);
            v.push_back(x);
            while(from[x] != -1){
                v.push_back(from[x]);
                x = from[x];
            }
            reverse(v.begin(), v.end());
            for(int i=0; i<=depth; i++){
                cout << v[i] << " ";
            }
            cout << "\n";
            break;
        }
        
    
        if(0 <= x - 1 && !visited[x-1] ){
            visited[x-1] = true;
            from[x-1] = x;
            q.push(P(x-1, cnt+1));
        }
        if(x + 1 <= MAX && !visited[x+1]){
            visited[x+1] = true;
            from[x+1] = x;
            q.push(P(x+1, cnt+1));
        }
        if(x * 2 <= MAX && !visited[x*2]){
            visited[x*2] = true;
            from[x*2] = x;
            q.push(P(x*2, cnt+1));
        }
    }
    
    return 0;
}
