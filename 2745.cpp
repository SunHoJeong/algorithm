//
//  2745.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 6..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void convert(string n, int b){
    int temp;
    int temp2 = 1;
    int sum = 0;
    //cout << "nsize:" << n.size() << '\n';
    int len = n.size();
    
    for(int i=0; i<len; i++){
        int temp = n[i];
        if(65 <= temp && temp <= 90){
            temp -= 55;
        }else{
         temp = n[i] - '0';
        }
        if(i == 0){
            temp2 = 1;
        }
        else{
            temp2 *= b;
        }
        sum += temp2*temp;
        //cout << "temp: " << temp << ",temp2:"<<temp2<<  '\n';
    }
    cout << sum << '\n';
    //cout << "sum:" << sum << '\n';
    
}

int main(){
    string n;
    int b;
    
    cin >> n >> b;
    //cout <<n << "," << b<< '\n';
    
    reverse(n.begin(), n.end());
    
    //cout << "reverse" << n <<'\n';
    convert(n,b);
    
}
