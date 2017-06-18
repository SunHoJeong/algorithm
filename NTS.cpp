//
//  NTS.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 5. 22..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <vector>

using namespace std;
typedef pair<int, int> P;
const int N = 1322;

int money = 1000000;
vector<P> v;

int main(){
    //v[0] = 100, v[1] = 50, v[2] = 20, v[3] = 10, v[4] = 5, v[5] = 1
    
    money -= 4*(100*N+50*N); //100N과 50N은 4장씩 -> 남은잔돈 : 206800
    money -= 20*1*N; // 1N은 최소 20장이기 때문에 20장 환전하고 시작
    
    //vector에 P(단위, 장수) push
    v.push_back(P(100,4));
    v.push_back(P(50,4));
    v.push_back(P(20,0));
    v.push_back(P(10,0));
    v.push_back(P(5,0));
    v.push_back(P(1,20));
    
    int st = 2;// vector index = 2(20N)부터 라운드 로빈
    while(money > 2000){
        for(int i=st; i<v.size(); i++){//20N, 10N, 5N, 1N만 라운드 로빈
            if(money - v[i].first*N < 0){
                if(i == st){
                    st += 1; //가장 큰 단위의 지폐를 바꿀수 없으면 라운드 로빈에서 제외시킴
                }
            }
            else{
                money -= v[i].first*N;
                v[i].second += 1;
            }
        }
    }
    
    for(int i=0; i<v.size(); i++){
        printf("%dN : %d장\n",v[i].first, v[i].second);
    }
    
    printf("\n");
    printf("잔돈: %d\n", money);

    return 0;
}
