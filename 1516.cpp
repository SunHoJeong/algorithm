//
//  1516.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 12..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int a[505];
int d[505];
int ind[505];
vector<int> v[505];
queue<int> q;

int main(){
    //memset(d, 123456789, sizeof(d));
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
        while(true){
            int temp;
            cin >> temp;
            //cout << i << "," << temp << "\n";
            if(temp == -1){
                break;
            }
            else{
                v[temp].push_back(i);
                ind[i] += 1;
            }
        }
    }
    
//    for(int i=1; i<=n; i++){
//        cout << "i:"<<i<<"->";
//        for(int j=0; j<v[i].size(); j++){
//            cout << v[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    
//    for(int i=1; i<=n; i++){
//        cout << ind[i] << " ";
//    }
    
    for(int i=1; i<=n; i++){
        if(ind[i] == 0){
            q.push(i);
            d[i] = a[i];
        }
    }
    
    for(int i=1; i<=n; i++){
        int x = q.front();
        q.pop();
        
        for(int j=0; j<v[x].size(); j++){
            int y = v[x][j];
            ind[y] -= 1;
            
            if(d[y] < d[x] + a[y]){
                d[y] = d[x]+a[y];
            }
            if(ind[y] == 0){
                q.push(y);
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        cout << d[i] << "\n";
    }
    return 0;
}
