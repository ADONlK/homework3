#include <gtest/gtest.h>
#include "Heap.h"

TEST(HeapTest, PushPop) {
    Heap<int, 10> h;

    h.push(5);
    h.push(3);
    h.push(8);

    EXPECT_EQ(h.top(), 8);
    h.pop();
    EXPECT_EQ(h.top(), 5);
}

