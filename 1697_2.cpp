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
queue<P> q;
bool visited[100001];

int main(){
    int n, k;
    cin >> n >> k;
    visited[n] = true;
    q.push(P(n,0));
    
    
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        if(temp.first == k){
            cout << temp.second << "\n";
            cout << cnt << "\n";
            break;
        }
        else{
            if(0 <= temp.first-1 && !visited[temp.first-1]){
                if(temp.first-1 == k){
                    
                }
                visited[temp.first-1] = true;
                q.push(P(temp.first-1, temp.second+1));
            }
            if(temp.first+1 <= MAX && !visited[temp.first+1]){
                visited[temp.first+1] = true;
                q.push(P(temp.first+1, temp.second+1));
            }
            if(temp.first * 2 <= MAX && !visited[temp.first*2]){
                visited[temp.first*2] = true;
                q.push(P(temp.first*2, temp.second+1));
            }
        }
    }
    
    return 0;
}
