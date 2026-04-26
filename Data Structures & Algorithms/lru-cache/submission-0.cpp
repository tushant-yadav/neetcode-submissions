class LRUCache {
        list<int> order;
        unordered_map<int,pair<int, list<int>::iterator>> cache;
        int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()) return -1;

        order.remove(key);
        order.push_back(key);
        cache[key].second = --order.end();
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            order.remove(key);
        }
        else if(order.size() == this->capacity){
            int lru = order.front();
            order.pop_front();
            cache.erase(lru);
        }
        order.push_back(key);
        cache[key].second = --order.end();
        cache[key].first = value;
    }
};
