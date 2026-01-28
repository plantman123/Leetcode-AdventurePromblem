#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    static int cmp(int a, int b) {
        return a < b;
    }
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums_backup, res;
        for (int i=0;i<n;i++) {nums_backup.push_back(nums[i]);}
        sort(nums.begin(), nums.end(), cmp);
        map<int, int> less_cnt, num_appear;

        for (int i=0;i<n;i++) {
            if (less_cnt[nums[i]] == 0 && num_appear[nums[i]] == 0) {
                less_cnt[nums[i]] = i;
                num_appear[nums[i]] = 1;
            }
        } 

        for (int i=0;i<n;i++) {
            res.push_back(less_cnt[nums_backup[i]]);
        }
        return res;
    }
};



