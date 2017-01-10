//
//  1076.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 8..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

int  main(){
    map<string, int> m;
    map<string, int>::iterator iter;
    
    m.insert(pair<string, int>("black", 0));
    m.insert(pair<string, int>("brown", 1));
    m.insert(pair<string, int>("red", 2));
    m.insert(pair<string, int>("orange", 3));
    m.insert(pair<string, int>("yellow", 4));
    m.insert(pair<string, int>("green", 5));
    m.insert(pair<string, int>("blue", 6));
    m.insert(pair<string, int>("violet", 7));
    m.insert(pair<string, int>("grey", 8));
    m.insert(pair<string, int>("white", 9));
    
//    cout << m["black"] << '\n';
//    
//    for(iter = m.begin(); iter != m.end(); iter++){
//        cout << iter->first <<" " << iter->second << '\n';
//    }
    
    string str[3];
    cin >> str[0];
    cin >> str[1];
    cin >> str[2];
    
    long long result = 10 * m[str[0]] + m[str[1]];
    //cout <<"notation:"<< result << '\n';
    int notation = 1;
    for(int i=0; i<m[str[2]]; i++){
        notation *= 10;
    }
    
    cout << result * notation << '\n';
}
