/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* temp = head;
        while(temp != NULL) {
            Node* front = temp->next;
            Node* copy = new Node(temp->val);
            temp->next = copy;
            copy->next = front;
            temp = front;
        }
        temp = head;
        while(temp != NULL) {
            Node* copyNode = temp->next;
            if(temp->random)
                copyNode->random = temp->random->next;
            else
                copyNode->random = NULL;
            temp = temp->next->next;
        }
        Node* dummy = new Node(-1);
        Node* res = dummy;
        temp = head;
        while(temp != NULL) {
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};