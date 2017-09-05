//
//  kakao_2.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 8. 5..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int alphaCnt[26] = {0,};
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    string answer = "";
    vector<string> save;
    
    for(int i=0; i<sentence.size(); i++){
        //cout << sentence.at(i) <<"," << sentence.at(i)-'a' << "\n";
        if(0 <= (int)(sentence.at(i)-'a') && (int)(sentence.at(i)-'a') <= 26){ //특수문자
            alphaCnt[sentence.at(i)-'a'] += 1;
        }
    }
    
//    for(int k=0; k<26; k++){
//        cout << alphaCnt[k] << "\n";
//    }
    
    string str = "";
    
    for(int i=0; i<sentence.size(); i++){
        if(0 <= (int)(sentence.at(i)-'a') && (int)(sentence.at(i)-'a') <= 26){
            if(alphaCnt[sentence.at(i)-'a'] == 2){ // 특수문자 -> 양옆 문자열
                if(str != ""){
                    save.push_back(str);
                }
                str = "";
                
                char c = sentence.at(i);
                
                while(sentence.at(i) != c){
                    str.push_back(sentence.at(i));
                }
                
                if(str != ""){
                    save.push_back(str);
                }
                
                str = "";
            }
            else{ // 특수문자 -> 사이 문자열
                str.push_back(sentence.at(i));
            }
        }
        else if(sentence.at(i) ==' '){
            //cout << "공백이에요 무시할게요 \n";
        }
        else{
            str.push_back(sentence.at(i));
        }
        
    }
    
    if(str != ""){
        save.push_back(str);
    }
    
    for(string str : save){
        cout << str << "\n";
    }
    
    for(int i=0; i<save.size(); i++){
        int first = 1;
        char comp = '\0';
        string curStr = save[i];
        string tempStr = "";
        
        for(int j=0; j<curStr.size(); j++){
            if(0 <= (int)(curStr.at(j)-'a') && (int)(curStr.at(j)-'a') <= 26){ // 특수문자
                if(j == 0 || j == curStr.size()-1){
                    answer = "invalid";
                    return answer;
                }
                else{
                    if(first){
                        comp = curStr.at(j);
                        first = 0;
                    }
                    
                    if(tempStr != ""){
                        tempStr.pop_back(); //하나 빼고
                        if(tempStr.size() != 0){
                            tempStr += " ";
                            answer += tempStr;
                            tempStr = "";
                        }
                        
                    }
                    
                    while(j < curStr.size() && curStr.at(j) == comp){
                        tempStr.push_back(curStr.at(j-1));
                        j += 2;
                    }
                    
                    tempStr.push_back(curStr.at(j-1));
                    answer += tempStr;
                    if(i != save.size()-1){
                        answer += " ";
                    }
                    if(j<curStr.size() && 0 <= (int)(curStr.at(j)-'A') && (int)(curStr.at(j)-'A') <= 26){
                        answer.push_back(curStr.at(j));
                    }
                    tempStr = "";
                    first = 1;
                    
                    if(j < curStr.size() && curStr.at(j) != comp){
                        if(0 <= (int)(curStr.at(j)-'a') && (int)(curStr.at(j)-'a') <= 26){
                            answer = "invalid";
                            return answer;
                        }
                    }
                    
                }
            }
            else if(sentence.at(i) ==' '){
                //cout << "공백이에요 무시할게요 \n";
            }
            else{ //원문
                tempStr.push_back(curStr.at(j));
            }
            
            if(j == curStr.size()-1){
                answer += tempStr;
                if(i != save.size()-1){
                    answer += " ";
                }
                tempStr = "";
            }
            
        }
        
    }
    
    return answer;
}

int main(){
    string str = solution("HELLO WORLD");
    cout << str << "\n";
    return 0;
}
