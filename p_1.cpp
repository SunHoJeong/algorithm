//
//  p_1.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 6. 17..
//  Copyright © 2017년 수노. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;

int cnt[10];

int solution(string N) {
    int answer = 0;

    for(char c: N){
        cnt[c-'0'] += 1;
    }
    int max = 0;
    for(int i=0; i<10; i++){
        cout << cnt[i] << " ";
        if(cnt[i] % 2 == 0){//짝수
            if(cnt[i] != 0 ){
                answer += cnt[i];
            }
        }
        else{//홀수
            if(cnt[i] > max){
                max = cnt[i];
            }
        }
    }
    answer += max;
    cout << answer << "\n";
    return answer;
}

int main(){
    //solution("1213002");
    solution("123300");
}
