//
//  10824.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 20..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    string a,b,c,d;
    
    cin >> a >> b >> c >> d;
    
    string str1 = a+b;
    string str2 = c+d;
    
    long long first = stoll(str1);
    long long second = stoll(str2);
    
    cout << first + second << "\n";
    
    return 0;
}
