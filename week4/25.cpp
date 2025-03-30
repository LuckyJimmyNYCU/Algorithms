#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy, *curr = head;

        int length = 0;
        while (curr) {
            length++;
            curr = curr->next;
        }

        curr = head;
        while (length >= k) {
            ListNode *next = curr->next, *tail = curr;
            for (int i = 1; i < k; i++) {
                ListNode *temp = next->next;
                next->next = curr;
                curr = next;
                next = temp;
            }

            ListNode *temp = prev->next;
            prev->next = curr;
            tail->next = next;
            prev = tail;
            curr = next;

            length -= k;
        }

        return dummy.next;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* createList(initializer_list<int> vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int val : vals) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return dummy.next;
}

int main() {
    Solution solution;

    ListNode* test1 = createList({1, 2, 3, 4, 5});
    cout << "Input: [1,2,3,4,5], k=2\nOutput: ";
    printList(solution.reverseKGroup(test1, 2));

    ListNode* test2 = createList({1, 2, 3, 4, 5});
    cout << "Input: [1,2,3,4,5], k=3\nOutput: ";
    printList(solution.reverseKGroup(test2, 3));

    return 0;
}
