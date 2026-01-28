#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> sort_num(2*n);
        for (int i=0;i<2*n;i++) {
            if (i%2 == 0) {
                sort_num[i] = nums[i/2];
            } 
            else {
                sort_num[i] = nums[(i-1)/2 + n];
            }
        }
        return sort_num;
    }
};