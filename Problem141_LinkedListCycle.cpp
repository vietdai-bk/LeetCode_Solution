#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head==nullptr) return false;
        unordered_set<ListNode*> visited;
        while (head->next!=nullptr) {
            if (visited.find(head)!=visited.end()) return true;
            visited.insert(head);
            head = head->next;
        }
        return false;
    }
};