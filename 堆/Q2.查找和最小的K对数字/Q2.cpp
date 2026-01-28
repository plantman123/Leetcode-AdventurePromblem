#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


typedef struct Node {
    int i;
    int j;
    int sum;
    bool operator<(const Node& other) const {
        return sum > other.sum;
    }
} Node;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Node> min_heap;
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> results;
        map<pair<int, int>, int> hash_table;
        Node bgn;
        bgn.i = 0;
        bgn.j = 0;
        bgn.sum = nums1[bgn.i] + nums2[bgn.j];
        min_heap.push(bgn);
        pair<int, int> pbgn(bgn.i, bgn.j);
        hash_table[pbgn] = 1;
        while(k > 0) {
            k-= 1;
            Node top = min_heap.top();
            min_heap.pop();
            vector<int> new_result;
            printf("top: %d %d\n", top.i, top.j);
            new_result.push_back(nums1[top.i]);
            new_result.push_back(nums2[top.j]);
            results.push_back(new_result);
            // if (results.size() == k) break;

            Node new1, new2;
            if (top.j < n2-1) {
                new1.i = top.i;
                new1.j = top.j+1;
                new1.sum = nums1[new1.i] + nums2[new1.j];
                pair<int, int> pnew1(new1.i, new1.j);
                printf("new1: %d %d\n", new1.i, new1.j);
                if (!hash_table[pnew1]) {
                    min_heap.push(new1);
                    hash_table[pnew1] = 1;
                }
            }

            if (top.i < n1-1) {
                new2.i = top.i+1;
                new2.j = top.j;
                new2.sum = nums1[new2.i] + nums2[new2.j];
                pair<int, int> pnew2(new2.i, new2.j);
                printf("new2: %d %d\n", new2.i, new2.j);
                if (!hash_table[pnew2]) {
                    min_heap.push(new2);
                    hash_table[pnew2] = 1;
                }
            }
        }
        return results;
    }
};