#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_s = 0, n = heights.size();
        map<int, int> max_h;  // 不同高对应的长的结束位置
        for (int i=0;i<n;i++) {
            for (int h=1;h<=heights[i];h++) {
                if (max_h[h] != 0 && i <= max_h[h]) continue;
                for (int j=i;j<n;j++) {
                    if (heights[j] < h) {
                        max_h[h] = j-1;
                        int length = j-i;
                        max_s = (h*length > max_s)? h*length: max_s;
                        break;
                    }
                    else if (j == n-1) {
                        max_h[h] = j;
                        int length = j-i+1;
                        max_s = (h*length > max_s)? h*length: max_s;
                        break;
                    }
                }
            }
        }
        return max_s;
    }
};
