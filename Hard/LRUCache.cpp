#include <vector>
#include <string>
#include <unordered_map>
#include <deque>
#include <iostream>

using namespace std;

class LRUCache {
public:
    // Initialize LRUCache object
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    /* Create get method to access the LRU Cache
        1. If the key doesn't exist or the key is -1, return -1
        2. Push the key onto the deque
        3. Increment key
        4. Return the value at the given key
    */

    int get(int key) {
        if(!m.count(key) || m[key] == -1) return -1;
        q.push_back(key);
        visited[key]++;
        return m[key];
    }
    
    /* Create put method to put (key,value) objects into the LRU Cache
        1. If the key doesn't exist, increment the count to move to the next key.
        2. Else, increment the key.
        3. If the count is more than the size of the cache, decrement the visited value to 0 and pop the value off.
        4. Add the (key, value) pair to the cache.
    */
    void put(int key, int value) {
        if(!m.count(key)|| m[key] == -1) count++;
        else visited[key]++;
        if(count > capacity){
            while(visited[q.front()]) visited[q.front()]--, q.pop_front();
            m[q.front()] = -1;
            q.pop_front();
            count--;
        }
        q.push_back(key);
        m[key] = value;
    }

// Create an unordered map and deque for the put and get methods

private:
    unordered_map<int, int>m;
    unordered_map<int, int>visited;
    deque<int>q;
    int count = 0;
    int capacity = 0;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main() {
LRUCache cache(2);
cache.put(1, 1);
cache.put(2, 2);
std::cout << cache.get(1) << std::endl; // returns 1
cache.put(3, 3);
std::cout << cache.get(2) << std::endl; // returns -1 (not found)
cache.put(4, 4);
std::cout << cache.get(1) << std::endl; // returns -1 (not found)
std::cout << cache.get(3) << std::endl; // returns 3
std::cout << cache.get(4) << std::endl; // returns 4
return 0;
}
