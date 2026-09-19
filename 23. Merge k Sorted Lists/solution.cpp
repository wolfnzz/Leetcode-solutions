#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minQueue;

        for (ListNode* head: lists) {
            if (head != nullptr) {
                minQueue.push(head);
            }
        }

        ListNode* temp = new ListNode(0);
        ListNode* tail = temp;

        while (!minQueue.empty()) {
            ListNode* minNode = minQueue.top();
            minQueue.pop();

            tail->next = minNode;
            tail = tail->next;

            if (minNode->next != nullptr) {
                minQueue.push(minNode->next);
            }
        }

        ListNode* result = temp->next;
        return result;
    }
};


ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}


void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solver;

    ListNode* l1 = createList({1, 4, 5});
    ListNode* l2 = createList({1, 3, 4});
    ListNode* l3 = createList({2, 6});

    vector<ListNode*> lists = {l1, l2, l3};
    ListNode* mergedList = solver.mergeKLists(lists);

    printList(mergedList);
}
