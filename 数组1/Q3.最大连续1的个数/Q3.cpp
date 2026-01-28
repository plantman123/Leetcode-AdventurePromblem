#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        nums.push_back(0);
        int n = nums.size();
        int max_length = 0;
        int lstart = -1;
        for (int i=0;i<n;i++) {
            if (nums[i] == 0) {
                int length = i-lstart-1;
                lstart = i;
                if (length > max_length){
                    max_length = length;
                }
            }
        }
        return max_length;
    }
};