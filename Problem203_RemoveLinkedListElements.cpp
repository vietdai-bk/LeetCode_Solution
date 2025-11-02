#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head==nullptr) return head;
        ListNode* res = new ListNode();
        ListNode* dummy=res;
        while (head!=nullptr) {
            if (head->val!=val) {
                res->next = new ListNode(head->val);
                res = res->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};