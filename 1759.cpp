//
//  1759.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 18..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<char> save;
int l,c;

bool check(){//1개모음, 2개자음 이상
    int ja = 0;
    int mo = 0;
    for(auto item : save){
        if(item == 'a' || item == 'e' || item == 'i' || item == 'o' || item == 'u'){
            mo += 1;
        }
        else{
            ja += 1;
        }
    }
    
    return ja >= 2 && mo >=1;
}

void sol(vector<char> &v,int index, int depth){
    if(depth == l){
        if(check()){
            for(auto item : save){
                printf("%c", item);
            }
            printf("\n");
            return;
        }
    }
    
    int len = v.size();
    if(index == len)
        return;
    
    save.push_back(v[index]);
    sol(v, index+1, depth+1);
    save.pop_back();
    sol(v, index+1, depth);
    
}

int main(){
    scanf("%d %d", &l, &c);
    
    vector<char> v(c);
    
    for(int i=0; i<c; i++){
        cin >> v[i];
    }
    
    
    sort(v.begin(), v.end());
    
//    for(auto item: v){
//        printf("%c ",item);
//    }
    
    sol(v, 0, 0);
    
}
