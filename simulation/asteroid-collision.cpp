class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        for(int i = 0; i < asteroids.size(); i++){
            if(asteroids[i] < 0 && i != 0 && asteroids[i-1] > 0){
                if(abs(asteroids[i]) > abs(asteroids[i-1])){
                    asteroids.erase(asteroids.begin() + i - 1);
                    i -= 2;
                }
                else if(abs(asteroids[i]) < abs(asteroids[i-1])){
                    asteroids.erase(asteroids.begin() + i);
                    i -= 2;
                }
                else{
                    asteroids.erase(asteroids.begin() + i);
                    asteroids.erase(asteroids.begin() + i - 1);
                    i -= 2;
                }
            }
        }
        return asteroids;
    }
};