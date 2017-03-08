//
//  1764_set.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 8..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

set<string>::iterator itr;

int main(){
    int n,m;
    cin >> n >> m;
    set<string> input;
    vector<string> ans;
    
    for(int i=0; i<n; i++){
        string a;
        cin >> a;
        input.insert(a);
    }
    
    for(int i=0; i<m; i++){
        string b;
        cin >> b;
        set<string>::iterator com;
        com = input.find(b);
        if(com != input.end()){
            ans.push_back(*com);
        }
    }
    
    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << "\n";
    }
    return 0;
}
