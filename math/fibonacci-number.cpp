class Solution {
public:
    int fib(int n) {
        int numEven = 0;
        int numOdd = 1;
        for(int i = 2; i <= n; i++){
            (i % 2 == 0) ? numEven += numOdd : numOdd += numEven;
        }
        return (n % 2 == 0) ? numEven : numOdd;
    }
};