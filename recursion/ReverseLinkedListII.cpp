#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *head) {
    while (head != NULL) {
        cout << head->val << "->";
        head = head->next;
    }
    cout <<"null" << endl;
}


class Solution {
public:
    // recursive solution
    ListNode *reverse(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;

        // reverse the rest of the nodes and then return the new head
        ListNode *rest = reverse(head->next);
        // append the first node to the end of the list
        head->next->next = head;
        // the last node must point to NULL
        head->next = NULL;

        return rest;
    }

    // reverse with 3 pointers
    ListNode *reverse2(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *p = head; // prev
        ListNode *c = head->next; // current
        ListNode *n = c->next; // next

        while (true) {
            c->next = p;
            p = c;
            c = n;
            if (n == NULL)
                break;
            else
                n = n->next;
        }

        head->next = NULL;
        
        return p;
    }

    // reverse with 2 pointers(with the help of 'head')
    ListNode *reverse3(ListNode *head) {
        ListNode *p = NULL; // prev
        // head is the current
        ListNode *n; // next
        
        while(head != NULL) {
            n = head->next;
            head->next = p;
            p = head;
            head = n;
        }

        return p;
    }
};

int main()
{
    Solution s;

    ListNode head(2);
    ListNode n1(1);
    ListNode n2(4);
    ListNode n3(3);
    head.next = &n1;
    n1.next = &n2;
    n2.next = &n3;

    printList(&head);
    ListNode *newHead = s.reverse3(&head);
    printList(newHead);

    return 0;
}
