class Solution {
public:
    int reverse(int x) {
        double reversed = 0;

        while(x != 0){
            reversed = reversed * 10.0 + x % 10;
            x = x / 10;
        }

        if(reversed > INT_MAX || reversed < INT_MIN){
            return 0;
        }
        return static_cast<int>(reversed);
    }
};