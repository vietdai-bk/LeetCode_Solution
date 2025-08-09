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
    ListNode* deleteDuplicates(ListNode* head) {  
        if (head == nullptr) return nullptr;
        ListNode* root = head;
        ListNode* res = new ListNode(102);
        ListNode* p = res;
        while (root->next!=nullptr) {
            if (root->val != root->next->val) {
                res->next = new ListNode(root->val);
                res = res->next;
            }
            root = root->next;
        }
        if (res->val != root->val) {
            res->next = new ListNode(root->val);
        }
        return p->next;
    }
};
void createList(int A[], ListNode* p, int n) {
    for (int i=1;i<n;i++) {
        p->next = new ListNode(A[i]);
        p = p->next;
    }
}
void displayList(ListNode* l) {
    while (l!=NULL) {
        cout << l->val << " ";
        l = l->next;
    }
}
int main() {
    Solution solve;
    int A[] = {1, 1, 2, 2, 3, 4, 5, 6, 6, 7, 8};
    int n = sizeof(A)/sizeof(A[0]);
    ListNode* head = new ListNode(A[0]);
    createList(A, head, n);
    displayList(head);
    ListNode* res = solve.deleteDuplicates(head);
    cout << endl;
    displayList(res);
    return 0;
}