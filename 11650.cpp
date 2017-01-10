//
//  11650.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 2..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int main(){
    int n;
    scanf("%d" ,&n);
    vector<pair<int, int> > v(n);

    
    for(int i =0; i<n; i++){
        scanf("%d %d", &v[i].first, &v[i].second);
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++){
        printf("%d %d\n", v[i].first, v[i].second);
    }
    
    
}
