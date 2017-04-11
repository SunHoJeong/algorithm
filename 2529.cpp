//
//  2529.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 11..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
char arr[11];
bool visited[11];
vector<string> v;

void sol(int depth, string result){
    if(depth > n+1)
        return;
    if(depth == n+1){
        v.push_back(result);
    }
    
    char num = result[depth-1]-'0';
    for(int i=0; i<=9; i++){
        if(arr[depth] == '<'){
            if(!visited[i] && num < i){
                visited[i] = true;
                char ss = i+'0';
                string ns = result + ss;
                sol(depth+1, ns);
                visited[i] = false;
            }
        }
        else{
            if(!visited[i] && num > i){
                visited[i] = true;
                char ss = i+'0';
                string ns = result + ss;
                sol(depth+1, ns);
                visited[i] = false;
            }
        }
    }
}

int main(){
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    

    for(int i=0; i<=9; i++){
        if(!visited[i]){
            visited[i] = true;
            string result="";
            char c = i+'0';
            result += c;
            sol(1, result);
            visited[i] = false;
        }
    }
    
    sort(v.begin(), v.end());
    cout << v[v.size()-1] << "\n";
    cout << v[0] << "\n";
    
    return 0;
}
