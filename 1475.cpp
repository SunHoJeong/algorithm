//
//  1475.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 7..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;
int cnt[10];

int main(){
    string str;
    getline(cin, str);
    
    int len = (int)str.size();
    for(int i=0; i<len; i++){
        if(str[i] == '6' || str[i] == '9')
            cnt[6]++;
        else{
            int temp = str[i] - '0';
            cnt[temp]++;
        }
    }
    
    int ans = 0;
    for(int i=0; i<9; i++){//0~9
        if(i==6){
            if(cnt[i]%2==0){
                if(cnt[i]/2 > ans){
                    ans = cnt[i]/2;
                }
            }
            else{
                if(cnt[i]/2+1 > ans){
                    ans = cnt[i]/2+1;
                }
            }
        }
        else{
            if(cnt[i] > ans){
                ans = cnt[i];
            }
        }
        
    }
    
    cout << ans << "\n";
    
    return 0;
}
