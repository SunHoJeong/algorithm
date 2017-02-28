//
//  1966.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 27..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    
    for(int k=1; k<=t; k++){
        int n, m;
        int save;
        queue<int> q;
        scanf("%d %d", &n, &m);
        
        for(int i=0; i<n; i++){
            int t1;
            scanf("%d",&t1);
            if(i == m){
                save = t1;
            }
            q.push(t1);
        }
        
        
        
    }
    
    return 0;
}
