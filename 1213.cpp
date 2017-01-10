#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <stack>
#include <queue>

using namespace std;

int main(){
    int check[100] = {0,};
    vector<char> v;
    stack<char> stack;
    queue<char> queue;
    string str;
    int index = -1;
    int cnt = 0;
    
    cin >> str;
    
    for(int i=0; i<str.size(); i++){
        check[str[i] - 'A']++;
        v.push_back(str[i]);
    }
    
    sort(v.begin(), v.end());
    
    //    for(int i=0; i<v.size(); i++){
    //        cout << v[i];
    //    }
    
    for(int i=0; i<26; i++){
        if(v.size() % 2 ==0 && check[i]%2 != 0){
            cout << "I'm Sorry Hansoo" << '\n';
            return 0;
        }
        else if(v.size() % 2 == 1 && check[i]%2 != 0){
            cnt ++;
            index = i;
        }
    }
    
    if(cnt > 1){
        cout << "I'm Sorry Hansoo" << '\n';
        return 0;
    }
    if(index != -1){
        check[index] --;
        
    }
    //cout << "check:" << index << "," << check[0] << "," << check[1] << '\n';
    for(int i=0; i<26; i++){
        while(check[i] >0){
            //cout << check[i] << '\n';
            char temp = 'A'+i;
            stack.push(temp);
            queue.push(temp);
            
            check[i] -= 2;
        }
    }
    if(index != -1){
        char center = 'A' +index;
        queue.push(center);
    }
    
    while(!queue.empty()){
        cout << queue.front();
        queue.pop();
    }
    
    while(!stack.empty()){
        cout << stack.top();
        stack.pop();
    }
    
    cout << '\n';
    return 0;
}
