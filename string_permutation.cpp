//
//  string_permutation.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 21..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> save;
int limit, n;

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

void permu(vector<char> &v, int index, int depth){
    if(depth == limit){
        //print
        if(check()){
            for(char a : save){
                printf("%c",a);
            }
            cout << "\n";
            return;
        }
    }
    if(index == v.size())
        return;
    
    save.push_back(v[index]);
    permu(v, index+1, depth+1);
    save.pop_back();
    permu(v, index+1, depth);
}

int main(){
    cin >> limit >> n;
    vector<char> v(n);
    
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    permu(v, 0, 0);
    
    return 0;
}
