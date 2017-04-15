//
//  13458.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 15..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int admin[2];
int people[1000001];

int main(){
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> people[i];
    }
    for(int j=0; j<2; j++){
        cin >> admin[j];
    }
    
    long long ans = 0;
    for(int i=0; i<n; i++){
        people[i] -= admin[0];
        ans += 1;
    }
    
    for(int i=0; i<n; i++){
        if(people[i] > 0){
            if(people[i]%admin[1] == 0){
                int temp = people[i]/admin[1];
                ans += temp;
            }
            else{
                int temp = people[i]/admin[1];
                ans += temp+1;
            }

        }
    }

    printf("%lld\n",ans);
    return 0;
}
