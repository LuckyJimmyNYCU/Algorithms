#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // lambda function to compare ListNode value
        auto cmp = [](ListNode *a, ListNode *b)
        {
            return a->val > b->val; // small valy=ue first
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);

        // store each list node to heap
        for (auto node : lists)
        {
            if (node)
                pq.push(node);
        }

        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (!pq.empty())
        {
            ListNode *smallest = pq.top();
            pq.pop();
            tail->next = smallest;
            tail = tail->next;
            if (smallest->next)
                pq.push(smallest->next);
        }

        return dummy.next;
    }
};

// construct linked list
ListNode *buildList(const vector<int> &vals)
{
    ListNode dummy;
    ListNode *tail = &dummy;
    for (int val : vals)
    {
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return dummy.next;
}

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Solution solution;

    // Example 1: [[1,4,5],[1,3,4],[2,6]]
    vector<ListNode *> lists1 = {
        buildList({1, 4, 5}),
        buildList({1, 3, 4}),
        buildList({2, 6})};
    ListNode *result1 = solution.mergeKLists(lists1);
    cout << "Merged List 1: ";
    printList(result1); // Output: 1->1->2->3->4->4->5->6

    // Example 2: []
    vector<ListNode *> lists2 = {};
    ListNode *result2 = solution.mergeKLists(lists2);
    cout << "Merged List 2: ";
    printList(result2); // Output: (empty)

    // Example 3: [[]]
    vector<ListNode *> lists3 = {nullptr};
    ListNode *result3 = solution.mergeKLists(lists3);
    cout << "Merged List 3: ";
    printList(result3); // Output: (empty)

    return 0;
}
