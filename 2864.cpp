//
//  2864.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 8..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    string a;
    string b;
    
    cin >> a >> b;
    int a_len = (int)a.size();
    int b_len = (int)b.size();
    
    string a_max = a;
    string a_min = a;
    string b_max = b;
    string b_min = b;
    
    for(int i=0; i<a_len; i++){
        if(a[i] == '5'){
            a_max[i] = '6';
        }
        else if(a[i] == '6'){
            a_min[i] = '5';
        }
    }
    
    for(int i=0; i<b_len; i++){
        if(b[i] == '5'){
            b_max[i] = '6';
        }
        else if(b[i] == '6'){
            b_min[i] = '5';
        }
    }
    
    int ans_max = stoi(a_max) + stoi(b_max);
    int ans_min = stoi(a_min) + stoi(b_min);
    cout << ans_min << " " << ans_max << "\n";
    return 0;
}
