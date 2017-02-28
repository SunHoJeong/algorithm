//
//  7568.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 27..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <vector>

using namespace std;
typedef pair<int, int> P;

int d[55];

int main(){
    int n;
    scanf("%d",&n);
    vector<P> v(n+1);
    
    for(int i=1; i<=n; i++){
        int w, h;
        scanf("%d %d", &w, &h);
        v[i] = P(w,h);
        d[i] = 1;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i != j){
                if(v[i].first < v[j].first && v[i].second < v[j].second){
                    d[i] ++;
                }
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        printf("%d ", d[i]);
    }
    
    return 0;
}
