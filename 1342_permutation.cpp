//
//  1342_permutation.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 5..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

bool check(char* str, int len){
    for(int i=1; i<len; i++){
        if(str[i-1] == str[i]){
            return false;
        }
    }
    return true;
}

int main(){
    char input[11];
    cin >> input;
    int len = (int)strlen(input);
    sort(input, input+len);
    
    int ans = 0;
    do{
        cout << input << "\n";
        if(check(input, len)){
            ans++;
        }
    }while(next_permutation(input, input+len));

    cout << ans << "\n";
    return 0;
}
