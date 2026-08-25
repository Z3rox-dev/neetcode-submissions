/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* l2 = slow->next;
        slow->next = nullptr;      
        ListNode* l1 = head;

        ListNode* prev = nullptr;
        ListNode* current = l2;
        while(current != nullptr){
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        l2 = prev;
        while(l2 != nullptr && l1 != nullptr){
            ListNode* l1_next = l1->next;
            ListNode* l2_next = l2->next;

            l1->next = l2;
            if (l1_next == nullptr) break;
            l2->next = l1_next;

            l2 = l2_next;
            l1 = l1_next;
        }
    }
};
