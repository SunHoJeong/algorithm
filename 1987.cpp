//
//  1987.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 19..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int row, col;

int sol(vector<string> &graph, vector<bool> &check, int start){
    int r = start/10000;
    int c = start%10000;
    int ans = 0;
    
    //printf("r:%d c+1:%d\n", r,c+1);
    if(0 <= r-1 && r-1 <graph.size() && 0 <= c && c<graph[0].size() && !check[graph[r-1][c]-'A']){
        check[graph[r-1][c]-'A'] = true;
        int temp = sol(graph, check, (r-1)*10000+c);
        if(ans < temp){
            ans = temp;
        }
        check[graph[r-1][c]-'A'] = false;
    }
    if(0 <= r && r <graph.size() && 0 <= c+1 && c+1<graph[0].size()  && !check[graph[r][c+1]-'A']){
        check[graph[r][c+1]-'A'] = true;
        int temp = sol(graph, check, r*10000+c+1);
        if(ans < temp){
            ans = temp;
        }
        check[graph[r][c+1]-'A'] = false;
    }
    if(0 <= r+1 && r+1 <graph.size() && 0 <= c && c<graph[0].size() && !check[graph[r+1][c]-'A']){
        check[graph[r+1][c]-'A'] = true;
        int temp = sol(graph, check, (r+1)*10000+c);
        if(ans < temp){
            ans = temp;
        }
        check[graph[r+1][c]-'A'] = false;
    }
    if(0 <= r && r <graph.size() && 0 <= c-1 && c-1<graph[0].size()  && !check[graph[r][c-1]-'A']){
        check[graph[r][c-1]-'A'] = true;
        int temp = sol(graph, check, r*10000+c-1);
        if(ans < temp){
            ans = temp;
        }
        check[graph[r][c-1]-'A'] = false;
    }
    
    return ans +1;
    
}

int main(){
    cin >> row >> col;
    
    vector<string> graph(row);
    for(int i=0; i<row; i++){
        cin >> graph[i];
    }
    
    vector<bool> check(26);
    //cout << graph[0][0] << "\n";
    check[graph[0][0] - 'A'] = true;
    cout << sol(graph, check, 0) << "\n";
   
    
    

    return 0;
}
