//
//  9019.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 20..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

bool check[10001];
int value[10001];
char how[10001];
int from[10001];

int main(){
    int t;
    cin >> t;
    while(t--){
        int before;
        int after;
        
        cin>> before >> after;
        memset(check, false, sizeof(check));
        memset(value, 0, sizeof(value));
        memset(how, 0, sizeof(how));
        memset(from, 0, sizeof(from));
        check[before] = true;
        value[before] = 0;
        from[before] = -1;
        
        queue<int> q;
        q.push(before);

        while(!q.empty()){
            int start = q.front();
            q.pop();
            
            int temp = (start*2) % 10000;
            if(!check[temp]){ //D
                q.push(temp);
                check[temp] = true;
                value[temp] = value[start] + 1;
                from[temp] = start;
                how[temp] = 'D';
            }
            
            temp = start -1;
            if(temp == -1){
                temp = 9999;
            }
            
            if(!check[temp]){
                q.push(temp);
                check[temp] = true;
                value[temp] = value[start] +1;
                from[temp] = start;
                how[temp] = 'S';
            }
            
            temp = (start%1000)*10 + start/1000;
            
            if(!check[temp]){
                q.push(temp);
                check[temp] = true;
                value[temp] = value[start] +1;
                from[temp] = start;
                how[temp] = 'L';
            }
            
            temp = (start/10) + (start%10)*1000;
            if(!check[temp]){
                q.push(temp);
                check[temp] = true;
                value[temp] = value[start]+1;
                from[temp] = start;
                how[temp] = 'R';
            }
        }
        
        string str;
        while(after != before){
            //cout << before << "," << after << "\n";
            str += how[after];
            after = from[after];
        }
        
        reverse(str.begin(), str.end());
        cout << str << "\n";
    }
    return 0;
}
