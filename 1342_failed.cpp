//
//  1342.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 5..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <string>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

char str[11];
bool visited[11];
int len = 0;
set<string> result;

void back(int depth, vector<char> v){
    
    if(depth > 1){
        //printf("%c,%c\n",v[depth-1], v[depth-2]);
        if(v[depth-1] == v[depth-2]){
            //printf("yes\n");
            return;
        }
    }
    
    if(depth == len){
        string temp(v.begin(), v.end());
        result.insert(temp);
        return;
    }
    
    for(int i=0; i<len; i++){
        if(!visited[i]){
            visited[i] = true;
            v[depth] = str[i];
            back(depth+1, v);
            visited[i] = false;
            v[depth] = ' ';
        }
    }
}

int main(){
    vector<char> v(11);
    
    scanf("%s", str);
    //cout << str << "," << strlen(str);
    len = strlen(str);
    
    back(0,v);
    int ans = (int)result.size();
    printf("%d\n", ans);
    
    
    return 0;
}
