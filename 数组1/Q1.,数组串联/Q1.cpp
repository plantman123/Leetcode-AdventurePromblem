#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int length = nums.size();
        vector<int> ans(2*length);
        for (int i=0;i<length;i++) {
            ans[i] = nums[i];
            ans[i+length] = nums[i];
        }
        return ans;
    }
};

