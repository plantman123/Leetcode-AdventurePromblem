#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 思路：
        // 原始解法：对每个高都左右遍历寻找其最大的宽，得到最大的面积s
        // 遍历高O(n)找宽O(n)，共计O(n^2)
        // 优化方法：单调栈（递增）保存每个高的位置
        // 每次遍历一个高，如果栈空或者高大于栈顶，说明栈内所有的元素都小于新的高，宽的左侧为栈内第一个小于这个高的位置
        // 由此可以计算出栈顶位置对应高的最大面积，由此递推得到结果
        // 优化为O(n)
        if (heights.size() == 1) {return heights[0];}
        vector<int> stack_idx;
        heights.push_back(0);
        int max_s = 0;
        int lidx, new_s;
        for (int i=0;i<heights.size();i++) {
            lidx = -1;
            while(!stack_idx.empty() && heights[i] < heights[stack_idx.back()]) {
                lidx = stack_idx.back();
                stack_idx.pop_back();
                if (stack_idx.empty()) {break;}
                new_s = heights[lidx] * (i-stack_idx.back()-1);
                cout << lidx << " " << i << endl;
                if (new_s > max_s) {
                    max_s = new_s;
                }
            }
            if (lidx != -1) {
                int min_height = heights[lidx];
                while(lidx >= 0 && heights[lidx] >= min_height) {
                    lidx -= 1;
                }
                new_s = min_height * (i-lidx-1);
                cout << lidx << " " << i << endl;
                if (new_s > max_s) {
                    max_s = new_s;
                }
            }
            stack_idx.push_back(i);
        }
        return max_s;
    }
};

// cout << lidx << " " << i << endl;