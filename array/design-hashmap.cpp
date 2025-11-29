class MyHashMap {
private:
    static const int SIZE = 10000;
    vector<list<pair<int, int>>> buckets;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() : buckets(SIZE) {}

    void put(int key, int value) {
        int idx = hash(key);
        for (auto& p : buckets[idx]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        buckets[idx].push_back({key, value});
    }

    int get(int key) {
        int idx = hash(key);
        for (auto& p : buckets[idx]) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int idx = hash(key);
        buckets[idx].remove_if([key](const pair<int, int>& p) {
            return p.first == key;
        });
    }
};