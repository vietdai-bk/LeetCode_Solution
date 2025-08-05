#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void displayList(ListNode* l) {
    while (l!=NULL) {
        cout << l->val << " ";
        l = l->next;
    }
}
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        while(head != NULL && head->next != NULL) {
            ListNode* first = head; // trỏ vào node đầu tiên
            ListNode* second = head->next; // trỏ vào node thứ 2
            prev->next = second; // node trước first trỏ vào second
            first->next = second->next; // first trỏ vào node sau second
            cout << "first: " << first->next->val << endl;
            second->next = first; // second trỏ vào first
            prev = first; // cập nhật prev
            head = first->next; // cập nhật head
            cout << "head: " << head->val << endl;
            cout << "prev: " << prev->val << endl;
            displayList(dummy->next);
            cout << endl;
        }
        return dummy->next;
    }
};
void createList(int A[], ListNode* p, int n) {
    for (int i=1;i<n;i++) {
        p->next = new ListNode(A[i]);
        p = p->next;
    }
}
int main() {
    Solution sol;
    int A[] = {1,2,3,4,5};
    int n = sizeof(A)/sizeof(int);
    ListNode* head = new ListNode(A[0]);
    ListNode* p = head; 
    createList(A,head,n);
    displayList(head);
    cout << endl;
    head = sol.swapPairs(head);
    displayList(head);
    return 0;
}