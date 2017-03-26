//
//  1697_2.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 26..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> P;
const int MAX = 100000;

int n, k;
queue<P> q;
bool visited[100001];
int val[100001];

int main(){
    cin >> n >> k;
    visited[n] = true;
    q.push(P(n,0));
    
    if(k==n){
        cout << 0 << "\n";
        cout << 1 << "\n";
        return 0;
    }
    
    bool find = false;
    int depth = 0;
    
    while(!q.empty()){
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();
        visited[x] = true;
        
        if(x == k ){
            if(!find){
                depth = cnt;
                find = true;
                val[x]++;
            }
            else{
                if(cnt != depth){
                    break;
                }
                val[x]++;
            }
        }
        
        if(0 <= x - 1 && !visited[x-1] ){
            q.push(P(x-1, cnt+1));
        }
        if(x + 1 <= MAX && !visited[x+1]){
            q.push(P(x+1, cnt+1));
        }
        if(x * 2 <= MAX && !visited[x*2]){
            q.push(P(x*2, cnt+1));
        }
    }
    cout << depth << "\n";
    cout << val[k] << "\n";
    
    return 0;
}
