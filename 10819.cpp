//
//  10819.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 16..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int>::iterator itr;
int sum = 0;
int temp_sum;

void sumArray(){
    temp_sum = 0;
    for(int i=1; i<v.size(); i++){
        int temp = fabs(v[i] - v[i-1]);
        temp_sum += temp;
        
    }
    //printf("--temp_sum:%d\n",temp_sum);
    if(sum < temp_sum){
        sum = temp_sum;
        //printf("sum: %d %d \n",temp_sum,sum);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    do{
        sumArray();
    }while(next_permutation(v.begin(), v.end()));
    
    printf("%d\n",sum);
    
    return 0;
}
