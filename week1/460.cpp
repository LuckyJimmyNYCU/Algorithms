#include <iostream>
#include <unordered_map>
#include <list>

class LFUCache {
    int capacity;
    int minFreq;
    std::unordered_map<int, std::pair<int, int>> keyToValueFreq;  // key -> {value, freq}
    std::unordered_map<int, std::list<int>> freqToList;           // freq -> keys list
    std::unordered_map<int, std::list<int>::iterator> keyToIter;  // key -> iterator in freq list

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    int get(int key) {
        // if the key does not exist
        if (keyToValueFreq.find(key) == keyToValueFreq.end()) {
            return -1; // map.end(), downn't exist
        }


        // get value and freq
        int value = keyToValueFreq[key].first;
        int freq = keyToValueFreq[key].second;

        // remove freq number
        freqToList[freq].erase(keyToIter[key]);
        if (freqToList[freq].empty()) {
            freqToList.erase(freq);
            if (minFreq == freq) minFreq++; // update minFreq
        }

        // insert new freq number
        freqToList[freq + 1].push_front(key);
        keyToIter[key] = freqToList[freq + 1].begin();

        //add 1 to freq of key and return key value
        keyToValueFreq[key].second++;

        return value;
    }

    void put(int key, int value) {
        if (capacity == 0){
            return;
            }

        if (keyToValueFreq.find(key) != keyToValueFreq.end()) {
            // Key exist
            keyToValueFreq[key].first = value;// change value
            get(key); // add freq to key
            return;
        }

        if (keyToValueFreq.size() >= capacity) {
            // remove less freq key
            int lfuKey = freqToList[minFreq].back();
            freqToList[minFreq].pop_back();
            if (freqToList[minFreq].empty()) {
                freqToList.erase(minFreq);
            }
            keyToValueFreq.erase(lfuKey);
            keyToIter.erase(lfuKey);
        }

        // insert new key¡Asetting freq as 1
        keyToValueFreq[key] = {value, 1};
        freqToList[1].push_front(key);
        keyToIter[key] = freqToList[1].begin();
        minFreq = 1;

    }
};

int main() {
    LFUCache* obj = new LFUCache(2);
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
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
