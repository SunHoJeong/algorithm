//
//  1157.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 7..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int cnt[26];

int main(){//65~90, 97~122
    string str;
    getline(cin, str);

    int len  = (int)str.size();
    for(int i=0; i<len; i++){
        if(65 <= (int)str[i] && (int)str[i] <= 90){
            cnt[(int)(str[i]-'A')]++;
        }
        else if(97<= (int)str[i] && (int)str[i] <=122){
            cnt[(int)(str[i]-'a')]++;
        }
    }
    
    int max = cnt[0];
    int index = 0;
    
    for(int i=0; i<26; i++){
        if(max < cnt[i]){
            max = cnt[i];
            index = i;
        }
    }
    
    int ans_cnt = 0;
    for(int i=0; i<26; i++){
        if(cnt[i] == max){
            ans_cnt++;
        }
    }
    if(ans_cnt>1){
        cout << "?\n";
    }
    else{
        cout << (char)(index+'A') << "\n";
    }
    return 0;
}
