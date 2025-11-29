class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int l = 0, r = height.size() - 1;
        int lmax = 0, rmax = 0;
        int res = 0;
        while(l < r){
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if(lmax < rmax) res += lmax - height[l++];
            else res += rmax - height[r--];
        }
        return res;
    }
};