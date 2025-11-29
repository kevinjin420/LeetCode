class Solution {
public:
    string decodeString(string s) {
        stack<char> stack;
        string mult;
        string copy;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ']'){
                while(stack.top() != '['){
                    copy = stack.top() + copy;
                    stack.pop();
                }
                stack.pop();
                while(!stack.empty() && isdigit(stack.top())){
                    mult = stack.top() + mult;
                    stack.pop();
                }
                for(int j = 0; j < stoi(mult); j++){
                    for(char c : copy){
                        stack.push(c);
                    }
                }
                copy = "";
                mult = "";
            }
            else{
                stack.push(s[i]);
            }
        }
        string ans;
        while(!stack.empty()){
            ans = stack.top() + ans;
            stack.pop();
        }
        return ans;
    }
};