class LRUCache {
public:
    LRUCache(int capacity) : capa_(capacity) {
    }
    
    int get(int key) {
        if (!map_.count(key)) {
            return -1;
        }
        // It key exists, update it.
        const auto value = map_[key]->second;
        update(key, value);
        return value;
    }
    
    void put(int key, int value) {
        if (capa_ <= 0) {
            return;
        }

        // If cache is full while inserting, remove the last one.
        if (!map_.count(key) && list_.size() == capa_) {
            auto del = list_.front(); list_.pop_front();
            map_.erase(del.first);
        }
        update(key, value);
    }
    
private:
    list<pair<int, int>> list_; // key, value
    unordered_map<int, list<pair<int, int>>::iterator> map_; // key, list iterator
    int capa_;
    
    // Update (key, iterator of (key, value)) pair
    void update(int key, int value) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            list_.erase(it->second);
        }
        list_.emplace_back(key, value);
        map_[key] = prev(end(list_));
    }
};