#include <iostream>

using namespace std;

class LRUCache {
public:
    int capacity;

    // store

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
    }

    void put(int key, int value) {
    }
};

int main() {
    return 0;
}

class LRUCache {
public:
    int cap;

    // stores {key, value}
    list<pair<int, int>> dll;

    // key -> iterator pointing to node in dll
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        // Move accessed node to front because it is recently used
        auto it = mp[key];
        int value = it->second;

        dll.erase(it);
        dll.push_front({key, value});
        mp[key] = dll.begin();

        return value;
    }

    void put(int key, int value) {
        // If key already exists, remove old node
        if (mp.find(key) != mp.end()) {
            dll.erase(mp[key]);
        }

        // Insert new / updated node at front
        dll.push_front({key, value});
        mp[key] = dll.begin();

        // If capacity exceeded, remove least recently used node
        if (dll.size() > cap) {
            auto last = dll.back();
            int lruKey = last.first;

            dll.pop_back();
            mp.erase(lruKey);
        }
    }
};