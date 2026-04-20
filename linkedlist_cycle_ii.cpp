// Problem: Linked List Cycle II (LeetCode)
// Approach: Floyd’s Cycle Detection (Tortoise & Hare)

#include<iostream>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        bool isCycle = false;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                isCycle = true;
                break;
            }
        }
        if(!isCycle){
            return NULL;
        }

        slow = head;

        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

int main() {
    // Create list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Create cycle: 4 -> 2
    head->next->next->next->next = head->next;

    Solution s;
    ListNode* startNode = s.detectCycle(head);

    if(startNode != NULL){
        cout << "Cycle starts at node with value: " << startNode->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}