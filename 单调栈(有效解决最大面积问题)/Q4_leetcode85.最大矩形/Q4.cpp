#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int max_s = 0;
        for (int i=0;i<row;i++) {
            vector<int> heights;
            vector<int> stack_idx;
            for (int c=0;c<=col;c++) {
                heights.push_back(0);
                for (int b=i;b<row;b++) {
                    if (c == col) break;
                    if (matrix[b][c] == '0') break;
                    heights[c] += 1;
                }

                int lidx = -1, new_s;
                while (!stack_idx.empty() && heights[c] < heights[stack_idx.back()]) {
                    lidx = stack_idx.back();
                    stack_idx.pop_back();
                    if (stack_idx.empty()) {break;}
                    new_s = heights[lidx] * (c-stack_idx.back()-1);
                    if (new_s > max_s) {
                        max_s = new_s;
                    }
                }
                if (lidx != -1) {
                    int min_height = heights[lidx];
                    while(lidx >= 0 && heights[lidx] >= min_height) {
                        lidx -= 1;
                    }
                    new_s = min_height * (c-lidx-1);
                    if (new_s > max_s) {
                        max_s = new_s;
                    }
                }
                stack_idx.push_back(c);
            }
        }
        return max_s;
    }
};