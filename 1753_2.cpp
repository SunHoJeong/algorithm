//
//  1753_2.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 17..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <vector>

using namespace std;
const int INF = 1000000000;
typedef pair<int, int> P;

vector<P> v[20001];
int dist[20001];
bool visited[20001];

int main(){
    int n,e;
    int st;
    scanf("%d %d", &n,&e);
    for(int i=1; i<=n; i++){
        dist[i] = INF;
    }
    scanf("%d", &st);
    dist[st] = 0;
    visited[st] = true;
    for(int i=0; i<e; i++){
        int t1, t2, t3;
        v[t1].push_back(P(t2,t3));
    }
    
    for(int k=0; k<n; k++){
        int min = INF;
        int index = 0;
        
        for(int i=1; i<=n; i++){
            if(!visited[i] && dist[i] < min){
                min = dist[i];
                index = i;
            }
        }
        visited[index] = true;
        
        for(auto &p: v[index]){
            if(dist[p.first] > dist[index]+p.second){
                dist[p.first] = dist[index]+p.second;
            }
        }
    }
    
    return 0;
}
