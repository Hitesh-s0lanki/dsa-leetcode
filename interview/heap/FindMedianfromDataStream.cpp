#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    double median;
    int size;

public:
    MedianFinder() {
        size = 0;
    }

    void addNum(int num) {
        if (max_heap.empty() || max_heap.top >= num) {
            max_heap.push(num);
            if (abs(max_heap.size() - min_heap.size()) > 1) {
                int top = max_heap.top();
                max_heap.pop();
                min_heap.push(top);
            }
        } else {
            min_heap.push(num);
            if (abs(max_heap.size() - min_heap.size()) > 1) {
                int top = min_heap.top();
                min_heap.pop();
                max_heap.push(top);
            }
        }
        size++;
    }

    double findMedian() {
        if (size == 0)
            return median;

        if (size % 2 == 0)
            return median = (min_heap.top() + max_heap.top()) / 2;

        return median = max_heap.top();
    }
};

int main() {
    return 0;
}