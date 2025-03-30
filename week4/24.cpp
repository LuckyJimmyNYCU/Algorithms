#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (head && head->next) {
            ListNode* first = head;
            ListNode* second = head->next;

            prev->next = second;
            first->next = second->next;
            second->next = first;

            prev = first;
            head = first->next;
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

    ListNode* test1 = createList({1, 2, 3, 4});
    cout << "Input: [1,2,3,4]\nOutput: ";
    printList(solution.swapPairs(test1));

    ListNode* test2 = createList({});
    cout << "Input: []\nOutput: ";
    printList(solution.swapPairs(test2));

    ListNode* test3 = createList({1});
    cout << "Input: [1]\nOutput: ";
    printList(solution.swapPairs(test3));

    ListNode* test4 = createList({1, 2, 3});
    cout << "Input: [1,2,3]\nOutput: ";
    printList(solution.swapPairs(test4));

    return 0;
}
