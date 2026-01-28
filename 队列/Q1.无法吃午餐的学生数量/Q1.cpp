#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int countStudents(vector<int>& stu, vector<int>& sdw) {
        deque<int> students, sandwiths;
        int stun = stu.size(), sdwn = sdw.size();
        for (int i=0;i<stun;i++) students.push_back(stu[i]);
        for (int i=0;i<sdwn;i++) sandwiths.push_back(sdw[i]);
        int cnt = 0;

        while (cnt < students.size() && !sandwiths.empty() && !students.empty()) {
            if (sandwiths.front() == students.front()) {
                sandwiths.pop_front();
                students.pop_front();
                cnt = 0;
            }
            else {
                students.push_back(students.front());
                students.pop_front();
                cnt += 1;
            }
        }
        return students.size();
    }
};
