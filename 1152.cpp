//
//  1152.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 7..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    int ans = 0;
    
    getline(cin, s);

    int len = (int)s.size();
    for(int i=0; i<len; i++){
        if(s[i] == ' '){
            ans++;
        }
    }
    if(s[0] == ' ')
        ans--;
    if(s[len-1] == ' ')
        ans--;
    
    cout << ans+1 << "\n";
    
    return 0;
}
