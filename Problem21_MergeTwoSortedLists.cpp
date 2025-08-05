#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1=list1, *p2=list2;
        ListNode* res = new ListNode(0);
        ListNode* current = res;
        while (p1!=nullptr && p2!=nullptr) {
            if (p1->val < p2->val) {
                current->next = p1;
                p1 = p1->next;
            } else {
                current->next = p2;
                p2 = p2->next;
            }
            current = current->next;
        }
        while (p1!=nullptr) {
            current->next = p1;
            p1 = p1->next;
            current = current->next;
        }
        while (p2!=nullptr) {
            current->next = p2;
            p2 = p2->next;
            current = current->next;
        }
        return res->next;
    }
};
int main() {
    Solution solve;
    int A[] = {1,2,4};
    int B[] = {1,3,4};
    int n1 = sizeof(A)/sizeof(int);
    int n2 = sizeof(B)/sizeof(int);
    ListNode* l1 = new ListNode(A[0]), *l2 = new ListNode(B[0]);
    ListNode* p1 = l1, *p2 = l2;
    createList(A,p1,n1), createList(B,p2,n2);
    displayList(l1);
    cout << endl;
    displayList(l2);
    ListNode* results = solve.mergeTwoLists(l1, l2);
    cout << endl;
    displayList(results);
}