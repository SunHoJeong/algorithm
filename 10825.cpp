//
//  10825.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 2..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Score{
    string name;
    int kor;
    int en;
    int math;
};

bool cmp(const Score &u, const Score &v){
    if(u.kor > v.kor){
        return true;
    }
    else if(u.kor == v.kor){
        if(u.en < v.en){
            return true;
        }
        else if(u.en == v.en){
            if(u.math > v.math){
                return true;
            }
            else if(u.math == v.math){
                if(u.name < v.name){
                    return true;
                }
            }
        }
    }
    
    return false;
}

int main(){
    int n;
    
    cin >> n;
    vector<Score> v(n);
    
    for(int i=0; i<n; i++){
        cin >> v[i].name >> v[i].kor >> v[i].en >> v[i].math;
        
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0; i<n; i++){
        cout << v[i].name << '\n';
    }
}
