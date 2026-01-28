#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operate_vec;
        vector<int> num_appear(n+1, 0);
        int last_appear = 0;
        for (int i=0;i<target.size();i++) {
            num_appear[target[i]] = 1;
            last_appear = target[i];
        }
        for (int i=1;i<=n;i++) {
            operate_vec.push_back("Push");
            if (i == last_appear) {break;}
            if (num_appear[i] == 0) {
                operate_vec.push_back("Pop");
            }
        }
        return operate_vec;
    }
};