#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    static int cmp(int a, int b) {return a > b;}
    bool isPossible(vector<int>& target) {
        if (target.size() == 1 && target[0] != 1) return false;
        priority_queue<int> max_heap;
        long sum = 0;
        for (int i=0;i<target.size();i++) { 
            max_heap.push(target[i]);
            sum += target[i];
        }

        while (max_heap.top() > 1) {
            int sub_sum = sum - max_heap.top();
            printf("%d %d\n", max_heap.top(), sub_sum);
            if (max_heap.top() <= sub_sum) return false;
            int new_top = max_heap.top() % sub_sum;
            if (sub_sum == 1) new_top = 1;
            if (new_top < 1) return false;
            sum = sub_sum + new_top;
            max_heap.pop();
            max_heap.push(new_top);
        }
        return true;
    }
};