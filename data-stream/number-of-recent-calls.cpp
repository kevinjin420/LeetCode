class RecentCounter {
public:
    RecentCounter() 
    : pos(0){}
    
    int ping(int t) {
        calls.push_back(t);
        while(calls[pos] < t - 3000){
            pos++;
        }
        return calls.size() - pos;
    }
private:
    vector<int> calls;
    int pos;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */