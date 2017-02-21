//
//  1238.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 20..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> P;
const int INF = 1000000000;

vector<P> v[1002];
vector<P> rev[1002];
int dist[1002];
int rev_dist[1002];
bool visited[1002];
bool rev_visited[1002];

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    
    for(int i=0; i<m; i++){
        int t1, t2, t3;
        cin >> t1>> t2>> t3;
        v[t1].push_back(P(t2, t3));
        rev[t2].push_back(P(t1, t3));
    }
    
    for(int i=1; i<=n; i++){
        dist[i] = INF; //목적지->각마을
        rev_dist[i] = INF; //각마을->목적지
    }
    
    dist[x] = 0;
    
    for(int k=0; k<n-1; k++){
        int min = INF+1;
        int index= 0;
        
        for(int i=1; i<=n; i++){
            if(!visited[i] && min > dist[i]){
                min = dist[i];
                index = i;
            }
        }
        
        visited[index] = true;
        
        for(auto &p : v[index]){//index -> f : s
            if(dist[p.first] > dist[index] + p.second){
                dist[p.first] = dist[index] + p.second;
            }
        }
    }
    
    rev_dist[x] = 0;
    
    for(int k=0; k<n-1; k++){
        int min = INF+1;
        int index= 0;
        
        for(int i=1; i<=n; i++){
            if(!rev_visited[i] && min > rev_dist[i]){
                min = rev_dist[i];
                index = i;
            }
        }
        
        rev_visited[index] = true;
        
        for(auto &p : rev[index]){//index -> f : s
            if(rev_dist[p.first] > rev_dist[index] + p.second){
                rev_dist[p.first] = rev_dist[index] + p.second;
            }
        }
    }
    
    
//    for(int i=1; i<=n; i++){
//        cout << dist[i] << " ";
//    }
//    cout << "\n";
//    
//    for(int i=1; i<=n; i++){
//        cout << rev_dist[i] << " ";
//    }
    int ans = 0;
    
    for(int i=1; i<=n; i++){
        if(ans < dist[i] + rev_dist[i]){
            ans = dist[i] + rev_dist[i];
        }
    }
    
    cout << ans << "\n";
    return 0;
}
