//
//  10809.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 31..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string>
#include <string.h>

using namespace std;
int check[26];

int main(){
    string str;
    cin >> str;
    
    memset(check, -1, sizeof(check));
    for(int i=0; i<str.size(); i++){
            if(check[str[i]-'a'] == -1){
            check[str[i]-'a'] = i;
        }
    }
    
    for(int i=0; i<26; i++){
        cout << check[i] << " ";
    }
    cout << "\n";
    return 0;
}
