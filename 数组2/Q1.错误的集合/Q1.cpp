#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        map<int, int> num_cnt;
        int n = nums.size();
        for (int i=0;i<n;i++) {
            num_cnt[nums[i]] += 1;
            if (num_cnt[nums[i]] == 2) {
                res.push_back(nums[i]);
            }
        }
        for (int i=1;i<=n;i++) {
            if (num_cnt[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};