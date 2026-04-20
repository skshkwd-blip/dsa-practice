// Problem: Linked List Cycle (LeetCode)
// Approach: Floyd’s Cycle Detection (Tortoise & Hare)

#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public: 
    bool hasCycle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};
int main() {
    // Create nodes
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Create cycle: last node (4) points back to node 2
    head->next->next->next->next = head->next;

    Solution s;
    if(s.hasCycle(head)) {
        cout << "Cycle detected in the list." << endl;
    } else {
        cout << "No cycle in the list." << endl;
    }

    return 0;
}