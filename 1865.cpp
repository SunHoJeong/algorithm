//
//  1865.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 13..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

const int INF = 123456789;
typedef pair<int, int> P;

int dist[501];

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n,m,w;
        cin >> n >> m >> w;
        vector<P> v[501];
        for(int i=1; i<=n; i++){
            dist[i] = INF;
        }

        for(int i=0; i<m; i++){
            int t1, t2, t3;
            cin >> t1 >> t2 >> t3;
            v[t1].push_back(P(t2,t3));
            v[t2].push_back(P(t1,t3));
        }
        for(int j=0; j<w; j++){
            int t1, t2, t3;
            cin >> t1 >> t2 >> t3;
            v[t1].push_back(P(t2, -t3));
        }
        
//        for(int i=1; i<=n; i++){
//            for(auto &p : v[i]){
//                cout << p.first << ","<< p.second << "\n";
//            }
//        }
        
        dist[1] = 0;
        bool flag = false;
        for(int k=0; k<n; k++){
            for(int i=1; i<=n; i++){
                for(auto &p : v[i]){
                    if(dist[i] != INF && dist[p.first] > dist[i] + p.second){
                        dist[p.first] = dist[i] + p.second;
                        if(k == n-1){
                            flag = true;
                        }
                    }
                }
            }
        }
        
//        for(int i=1; i<=n; i++){
//            cout << dist[i] << " ";
//        }
//        cout << "\n";
        if(flag){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
