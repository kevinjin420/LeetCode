class Solution {
public:
    int compress(vector<char>& chars) {
        int res = 0;
        for(int i = 0; i < chars.size();){
            char curr = chars[i];
            int length = 0;
            while(i < chars.size() && chars[i] == curr){
                length++;
                i++;
            }
            chars[res++] = curr;
            if(length > 1){
                for (const char c : to_string(length)) {
                    chars[res++] = c;
                }
            }
        }
        return res;

    }
};