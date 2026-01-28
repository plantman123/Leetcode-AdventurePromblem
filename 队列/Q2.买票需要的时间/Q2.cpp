#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


typedef struct person {
    int ticket;
    int idx;
}person;
 
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        deque<person> people(tickets.size());
        int t=0;
        for (int i=0;i<tickets.size();i++) {
            people[i].ticket = tickets[i];
            people[i].idx = i;
        }
        while (!people.empty()) {
            t += 1;
            person now_person = people.front();
            now_person.ticket -= 1;
            people.pop_front();
            if (now_person.ticket > 0) people.push_back(now_person);
            if (now_person.ticket == 0 && now_person.idx == k) break;
        }
        return t;
    }
};