class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;
        vector<char> valid = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while(left <= right){
            if(find(valid.begin(), valid.end(), s[left]) == valid.end()){
                left++;
            }
            else if(find(valid.begin(), valid.end(), s[right]) == valid.end()){
                right--;
            }
            else{
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
        }
        return s;
    }
};