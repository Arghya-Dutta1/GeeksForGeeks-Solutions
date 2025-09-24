class SpecialQueue {
private:
    deque<int> mainQueue;
    deque<int> minDeque;
    deque<int> maxDeque;

public:
    void enqueue(int x) {
        // Push to main queue
        mainQueue.push_back(x);

        // Maintain minDeque (increasing order)
        while (!minDeque.empty() && minDeque.back() > x) {
            minDeque.pop_back();
        }
        minDeque.push_back(x);

        // Maintain maxDeque (decreasing order)
        while (!maxDeque.empty() && maxDeque.back() < x) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(x);
    }

    void dequeue() {
        if (mainQueue.empty()) return;

        int frontElement = mainQueue.front();
        mainQueue.pop_front();

        if (!minDeque.empty() && frontElement == minDeque.front()) {
            minDeque.pop_front();
        }
        if (!maxDeque.empty() && frontElement == maxDeque.front()) {
            maxDeque.pop_front();
        }
    }

    int getFront() {
        return mainQueue.empty() ? -1 : mainQueue.front();
    }

    int getMin() {
        return minDeque.empty() ? -1 : minDeque.front();
    }

    int getMax() {
        return maxDeque.empty() ? -1 : maxDeque.front();
    }
};
