//
//  2331.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 9..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int a, p; //1<=a<=9999, 1<=p<=5
vector<int> v;
int graph[250000] = {0,};
bool visited[250000] = {false,};
bool visited2[250000] = {false,};
queue<int> q;
int cnt = 1;

void bfs(){
    while(!q.empty()){
        int start = q.front();
        q.pop();
        cnt--;
        
        //printf("start%d\n",start);
        if(visited2[graph[start]] == false && graph[start] != 0){
            q.push(graph[start]);
            visited2[graph[start]] = true;
            
        }
        
    }
}

int makeNum(int n){
    if(n==0){
        return 0;
    }
    string str = to_string(n);
    int size = (int)str.size();
    //printf("size:%d\n",size);
    int result = 0;
    
    for(int i=0; i<size; i++){
        int mul = str[i] - '0';
        int temp = mul;
        for(int j=1; j<p; j++){
            temp *= mul;
            //printf("--temp:%d\n", temp);
        }
        //printf("temp:%d\n",temp);
        result += temp;
    }
    //printf("result: %d\n",result);
    return result;
}

int main(){
    bool flag = true;
    
    scanf("%d %d", &a, &p);
    visited[a] = true;
    v.push_back(a);
    int i=0;
    while(flag){
        int temp = makeNum(v[i]);
        if(visited[temp] == false){
            visited[temp] = true;
            v.push_back(temp);
            //printf("push:%d\n", temp);
            cnt ++;
            i++;
            graph[v[i-1]] = v[i];
            
            //printf("cnt: %d\n",cnt);

            
        }
        else if(visited[temp] == true){
            
            //printf("cnt:%d, size:%d\n", cnt, v.size());
            flag = false;
            q.push(temp);
            bfs();
        }
        
    }
    
    printf("%d\n",cnt);
    
    
}
