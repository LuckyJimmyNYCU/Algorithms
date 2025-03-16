#include <iostream>
#include <unordered_map>
#include <list>

class LRUCache {
private:
    int capacity;
    std::list<std::pair<int, int>> cache; //  (key, value)
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;//find key

public:
    //initial = LRUCache(int capacity) : capacity(capacity) {}
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        // if the key does not exist
        if (map.find(key) == map.end()) {
            return -1; // map.end(), downn't exist
        }
        //move key to the front and return key value
        cache.splice(cache.begin(), cache, map[key]);
        return map[key]->second;
    }

    void put(int key, int value) {
        // pre->key->value
        if (map.find(key) != map.end()) {
            // if key exist¡Achange value and to front
            map[key]->second = value;
            cache.splice(cache.begin(), cache, map[key]);
            return;
        }

        // if capacity is full, remove old
        if (cache.size() >= capacity) {
            int lru_key = cache.back().first; // find LRU
            map.erase(lru_key);
            cache.pop_back();
        }

        // instet new link¡Aupdate map
        cache.emplace_front(key, value);
        map[key] = cache.begin();
    }

};

int main() {
    LRUCache* obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    std::cout << obj->get(1) << std::endl; // Output: 1
    obj->put(3, 3);
    std::cout << obj->get(2) << std::endl; // Output: -1 (evicted)
    obj->put(4, 4);
    std::cout << obj->get(1) << std::endl; // Output: -1 (evicted)
    std::cout << obj->get(3) << std::endl; // Output: 3
    std::cout << obj->get(4) << std::endl; // Output: 4

    delete obj;
    return 0;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
