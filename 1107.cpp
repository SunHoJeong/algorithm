//
//  1107.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 18..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

bool check[10] = {false,};

int possible(int x){
    int cnt =0;
    
    if(x == 0){
        if(check[0]){
            return 0;
        }
        else{
            return 1;
        }
    }
    
    while(x>0){
        if(check[x%10]){
            return 0;
        }
        cnt ++;
        x /= 10;
    }
    
    return cnt;
}

int main(){
    int n; //이동하고자하는 채널
    int m; //망가진버튼의 개수
    
    cin >> n;
    cin >> m;
    while(m--){
        int ch;
        cin >> ch;
        check[ch] = true; // 버튼고장체크
    }
    
    int ans = n-100;
    
    if (ans < 0) {
        ans = -ans;
    }
    
    for(int i=0; i<=1000000; i++){
        int len = possible(i);
        if(len > 0){
            int btn = n-i;
            if(btn < 0 ){
                btn = -btn;
            }
            
            if(ans > len + btn){
                ans = len+btn;
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
    
    
}
