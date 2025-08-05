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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* res = slow;
        for (int i=0;i<n;i++) {
            fast = fast->next;
        }
        if (fast==nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        while (fast) {
            fast = fast->next;
            if (fast)
                slow = slow->next;
        }
        ListNode* temp = slow->next;
        cout << temp->val << endl;
        if (temp->next == nullptr) {
            slow->next = nullptr;
        } else {
            slow->next = temp->next;
        }
        return res;
    }
};
int main() {
    Solution solve;
    int A[] = {1};
    ListNode* head = new ListNode(A[0]);
    ListNode* p = head;
    for (int i=1;i<sizeof(A)/sizeof(int);i++) {
        p->next = new ListNode(A[i]);
        p = p->next;
    }
    p = head;
    while (p!=NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout <<endl;
    ListNode* res = solve.removeNthFromEnd(head, 1);
    while (res!=NULL) {
        cout << res->val << " ";
        res = res->next;
    }
}