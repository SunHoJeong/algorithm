

#include <iostream>
#include <stack>
#include <string>

using namespace std;
int sum = 0;

int main(){
    stack<int> stack;
    string str;
    cin >> str;
    int n = str.size();
    
    for(int i=0; i<n; i++){
        if(str[i] == '('){
            stack.push(i);
        }
        else if(str[i] == ')'){
            if(!stack.empty()){
                if(stack.top() == i-1){ //razer
                    stack.pop();
                    sum += stack.size();
                }
                else{
                    stack.pop();
                    sum += 1;
                }
            }
        }
    }
    
    cout << sum << '\n';
    
    
    return 0;
}
