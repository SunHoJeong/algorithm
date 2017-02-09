//
//  1931.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 9..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Con{
    int start, end;
};

bool cmp(const Con &u, const Con &v){
    if(u.end == v.end){
        return u.start < v.start;
    }
    else{
        return u.end < v.end;
    }
}

int main(){
    int n;
    cin >> n;
    vector<Con> v(n);
    
    for(int i=0; i<n; i++){
        cin >> v[i].start >> v[i].end;
    }
    
    sort(v.begin(), v.end(), cmp);
    
//    for(int i=0; i<n; i++){
//        cout << v[i].start << "," <<v[i].end <<"\n";
//    }
    
    int now = 0;
    int ans =0 ;
    for (int i=0; i<v.size(); i++) {
        if (now <= v[i].start) {
            now = v[i].end;
            ans += 1;
        }
    }
    printf("%d\n",ans);
    
    return 0;
}
