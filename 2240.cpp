//
//  2240.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 26..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t,w;
int d[1001][31][3];

int main(){

    cin >> t >> w;
    vector<int> v(t+1);
    
    for(int i=1; i<=t; i++){
        cin >> v[i];
    }
    if(v[1] ==1){
        d[1][0][1] = 1;
    }
    else if(v[1] ==2){
        d[1][1][2] = 1;
    }
   
    for(int i=2; i<=t; i++){
        for(int j=0; j<=w; j++){
            if(v[i] == 1){
                d[i][j][1] = max(d[i][j][1], d[i-1][j][1]+1);
                if(j-1 >= 0){
                    d[i][j][1] = max(d[i][j][1], d[i-1][j-1][2]+1);
                    d[i][j][2] = max(d[i][j][2], d[i-1][j-1][1]);
                }
                d[i][j][2] = max(d[i][j][2], d[i-1][j][2]);
            }
            else if(v[i] == 2){
                d[i][j][1] = max(d[i][j][1], d[i-1][j][1]);
                if(j-1 >= 0){
                    d[i][j][1] = max(d[i][j][1], d[i-1][j-1][2]);
                    d[i][j][2] = max(d[i][j][2], d[i-1][j-1][1]+1);
                }
                d[i][j][2] = max(d[i][j][2], d[i-1][j][2]+1);
            }
        }
    }
    
    int ans_first = 0;
    int ans_second = 0;
    for(int i=0; i<=w; i++){
        if(d[t][i][1] > ans_first){
            ans_first = d[t][i][1];
        }
        if(d[t][i][2] > ans_second){
            ans_second = d[t][i][2];
        }
    }
    //cout << ans_first << "," << ans_second << "\n";
    int ans = max(ans_first, ans_second);
    cout << ans << "\n";
    return 0;
}
