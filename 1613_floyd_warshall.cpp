//
//  1613.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 10..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int graph[405][405];

int main(){
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=k; i++){
        int t1, t2;
        cin >> t1 >> t2;
        graph[t1][t2] = -1;
        graph[t2][t1] = 1;
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n ;j++){
                if(graph[i][k] != 0 && graph[i][k] == graph[k][j]){
                    graph[i][j] = graph[i][k];
                }
            }
        }
    }
    
    int s;
    cin >> s;
    for(int i=1; i<=s; i++){
        int t1, t2;
        cin >> t1 >> t2;
        cout << graph[t1][t2]<<"\n";
    }
    
    return 0;
}
