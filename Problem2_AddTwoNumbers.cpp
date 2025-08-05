#include <iostream>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* results = new ListNode(0); // tạo linked list kết quả
        ListNode* current = results;
        int carry = 0; // phần dư
        while (l1!=nullptr || l2!=nullptr || carry) {
            int sum = carry;
            if (l1!=nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2!=nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }
        return results->next;
    }
};
int main() {
    Solution solve;
    int A[] = {2,4,3};
    int B[] = {5,6,4};
    int n1 = sizeof(A)/sizeof(int);
    int n2 = sizeof(B)/sizeof(int);
    ListNode* l1 = new ListNode(A[0]), *l2 = new ListNode(B[0]);
    ListNode* p1 = l1, *p2 = l2;
    createList(A,p1,n1), createList(B,p2,n2);
    displayList(l1);
    cout << endl;
    displayList(l2);
    ListNode* results = solve.addTwoNumbers(l1, l2);
    cout << endl;
    displayList(results);
}