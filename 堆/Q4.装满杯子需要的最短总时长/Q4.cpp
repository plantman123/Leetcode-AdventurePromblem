// #include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> max_heap;
        for (int i=0;i<amount.size();i++) max_heap.push(amount[i]);
        int t = 0;
        while(max_heap.top() > 0) {
            int new_top1, new_top2;
            new_top1 = max_heap.top();
            max_heap.pop();
            if (max_heap.top() > 0) {
                new_top2 = max_heap.top();
                max_heap.pop();
                max_heap.push(new_top2-1);
            }
            max_heap.push(new_top1-1);
            t += 1;
        }
        return t;
    }
};