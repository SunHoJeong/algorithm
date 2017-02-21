//
//  bellman-ford-algorithm.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 20..
//  Copyright © 2017년 수노. All rights reserved.
//

//bellman-ford-algorithm
// 시작 노드부터 i노드까지의 최단경로
//dist[i] = INF로 초기화
//1번 노드부터 n번 노드까지 최소경로를 업데이트 -> 총 n-1번 해줌


#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> P;
const int INF = 123456789;

vector<P> v[10001];
int dist[10001];
int n,c;

int main(){
    for(int i=1; i<=500; i++){
        dist[i] = INF;
    }
    
    cin >> n >> c;
    
    for(int i=0; i<c; i++){
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        v[t1].push_back(P(t2, t3));
    }
    
    dist[1] = 0;
    bool flag = false;
    
    for(int k = 0; k<n; k++){
        for(int i=1; i<=n; i++){// i->p.first : p.second
            for(auto &p : v[i]){ //des, cost
                if(dist[i] > dist[p.first] + p.second){
                    dist[i] = dist[p.first] + p.second;
                    if(k==n-1)
                        flag = true; //음의 사이클 체크
                }
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        cout << "dist<" << i << ">" << dist[i] << "\n";
    }
    
    return 0;
}
