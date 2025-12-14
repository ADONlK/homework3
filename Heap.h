#pragma once
#include <cassert>

template <typename T, int SIZE>
class Heap {
private:
    T data[SIZE];
    int count;

    void heapifyUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (!(data[parent] < data[idx]))
                break;
            std::swap(data[parent], data[idx]);
            idx = parent;
        }
    }

    void heapifyDown(int idx) {
        while (true) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int largest = idx;

            if (left < count && data[largest] < data[left])
                largest = left;
            if (right < count && data[largest] < data[right])
                largest = right;

            if (largest == idx)
                break;

            std::swap(data[idx], data[largest]);
            idx = largest;
        }
    }

public:
    Heap() : count(0) {}

    bool empty() const {
        return count == 0;
    }

    bool full() const {
        return count == SIZE;
    }

    int size() const {
        return count;
    }

    void push(const T& value) {
        assert(!full());
        data[count] = value;
        heapifyUp(count);
        ++count;
    }

    T pop() {
        assert(!empty());
        T result = data[0];
        data[0] = data[count - 1];
        --count;
        heapifyDown(0);
        return result;
    }

    const T& top() const {
        assert(!empty());
        return data[0];
    }
};


