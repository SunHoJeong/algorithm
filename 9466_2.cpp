//
//  9466_2.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 10..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>

using namespace std;

int a[100001];
int s[100001];
int num[100001];
int n;

int dfs(int x, int cnt, int step){
    if(num[x] != 0){//이미 노드가 방문됐으면
        if(s[x] != step){
            return 0;
        }
        return cnt - num[x];
    }
    
    num[x] = cnt;
    s[x] = step;
    return dfs(a[x], cnt+1, step);
}

int main(){
    int t;
    scanf("%d", &t);
    
    while(t--){
        scanf("%d", &n);
        
        for(int i=1; i<=n; i++){
            scanf("%d", &a[i]);
            s[i] = 0;
            num[i] = 0;
        }
        
        int ans = 0; //num of cycle
        for(int i=1; i<=n; i++){
            if(num[i] == 0){
                ans += dfs(i, 1, i);
            }
        }
        printf("%d\n", n-ans);

    }
    
    return 0;
}
