//
//  9328.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 11..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int row, col;
        cin >> row >> col;
        char graph[102][102];
        bool visited[102][102];
        bool key[26];
        
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
        memset(key, 0, sizeof(key));
        
        for(int i=0; i<row; i++){
            cin >> graph[i];
        }
       
        char k[26]; //보유한 key 
        cin >> k;
        int len = (int)strlen(k);
        for(int i=0; i<len; i++){
            if(k[i] == '0')
                break;
            key[k[i]-'a'] = true;
        }
        
    }
    return 0;
}
