#include <vector> 
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int data) : val(data), next(nullptr) {}
};

class LinkedList {
public:
    ListNode* head;
    ListNode* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    LinkedList(int data) {
        head = new ListNode(data);
        tail = head;
    }

    int get(int index) {
        int i = 0;
        ListNode* current = head;
        while(current != nullptr && i < index){
            i++;
            current = current->next;
        }
        if(current != nullptr) return current->val;
        
        return -1;
    }

    void insertHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = head;
        head = node;
        if(tail == nullptr) tail = node;   
    }
    
    void insertTail(int val) {
        if(tail != nullptr){
            tail->next = new ListNode(val);
            tail = tail->next;
        }
        else{
            tail = new ListNode(val);
            head = tail;
        }
    }

    bool remove(int index) {
        if(head == nullptr) return false;

        if(index == 0){
            ListNode* tmp = head;
            head = head->next;

            if(head == nullptr) tail = nullptr;
            delete tmp;
            return true;
        }

        int i = 0;
        ListNode* current = head;

        while(current->next != nullptr && i < index-1){
            i++;
            current = current->next;
        } 

        if(current->next != nullptr){
            ListNode* tmp = current->next;
            current->next = tmp->next;
            if (tmp == tail) tail = current;
            delete tmp;
            return true;
        }
        else{
            return false;
        }
    }

    vector<int> getValues() {
        ListNode* current = head;
        vector<int> ans;
        while(current != nullptr){
            ans.push_back(current->val);
            current = current->next;
        }
        return ans;
    }
};
