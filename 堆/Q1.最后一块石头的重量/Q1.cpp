#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap;
        for (int i=0;i<stones.size();i++) max_heap.push(stones[i]);
        while(max_heap.size() >= 2) {
            int x, y;
            y = max_heap.top();
            max_heap.pop();
            x = max_heap.top();
            max_heap.pop();
            if (y - x > 0) max_heap.push(y - x);
        }
        if (max_heap.size() > 0) return max_heap.top();
        return 0;
    }
};