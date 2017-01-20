//
//  1963.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 20..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

bool prime[10001];
bool check[10001];
int value[10001];

int mod(int before, int index, int mod_num){
    if(index ==0 && mod_num == 0){
        return -1;
    }
    
    string str = to_string(before);
    str[index] = mod_num +'0';
    
    return stoi(str);
    
}

int main(){
    for(int i=2; i<=10000; i++){
        if(prime[i] == false){
            for(int j=i*i; j<=10000; j+=i){
                prime[j] = true;
            }
        }
    }
    
    int t;
    cin >> t;
    
    while(t--){
        int before, after;
        cin >> before >> after;
        if(prime[before] || prime[after]){
            cout << "Impossible" << "\n";
            return 0;
        }
        queue<int> q;
        memset(check, false, sizeof(check));
        memset(value, 0, sizeof(value));
        value[before] = 0;
        check[before] = true;
        
        q.push(before);
        while(!q.empty()){
            int start = q.front();
            //cout << "start" << start << "\n";
            q.pop();
            
            for(int i=0; i<4; i++){
                for(int j=0; j<=9; j++){
                    int temp = mod(start, i, j);
                    
                    if(temp != -1){
                        if(!prime[temp] && !check[temp]){
                            q.push(temp);
                            check[temp] = true;
                            value[temp] = value[start]+1;
                        }
                    }
                    
                }
            }
        }
        cout << value[after] << "\n";

    }
    
    return 0;
}
