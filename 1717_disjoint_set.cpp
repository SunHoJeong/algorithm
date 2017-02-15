//
//  1717.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 15..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>

using namespace std;

int p[1000001];

int Find(int x){
    if(x == p[x]){
        return x;
    }
    else{
        return p[x] = Find(p[x]);
    }
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    
    p[b] = a;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++){
        p[i] = i;
    }
    
    for(int i=0; i<m; i++){
        int cmd, t1, t2;
        scanf("%d", &cmd);
        if(cmd == 0){ //union
            scanf("%d %d",&t1, &t2);
            Union(t1, t2);
            
        }else if(cmd ==1){ //find
            scanf("%d %d",&t1, &t2);
            if(Find(t1) == Find(t2)){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
    return 0;
}
