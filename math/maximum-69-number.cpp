class Solution {
public:
    int maximum69Number (int num) {
        string str = to_string(num);
        int left = 0;
        while(left < str.size() && str[left] == '9') left++;
        if(left == str.size()) return num;
        str[left] = '9';
        return stoi(str);
    }
};