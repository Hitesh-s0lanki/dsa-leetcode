#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void insertAtTail(ListNode *&head, ListNode *&tail, int val) {
    ListNode *temp = new ListNode(val);

    if (head == NULL)
        head = temp;
    else
        tail->next = temp;

    tail = temp;
}

void print(ListNode *head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        int minPoint = INT_MAX;
        int maxPoint = -1;

        // store the index
        int firstCricticalPoint = -1;
        int lastCricticalPoint = -1;

        ListNode *prev = head;
        ListNode *curr = head->next;

        int cnt = 1;

        while (curr != NULL && curr->next != NULL) {
            // next node to the current;
            ListNode *currNext = curr->next;

            // check the local minima
            if ((prev->val > curr->val && curr->val < currNext->val) || (prev->val < curr->val && curr->val > currNext->val)) {
                if (lastCricticalPoint != -1) {
                    minPoint = min(minPoint, cnt - lastCricticalPoint);
                } else {
                    firstCricticalPoint = cnt;
                }
                lastCricticalPoint = cnt;
            }

            prev = curr;
            curr = curr->next;

            cnt++;
        }

        if (lastCricticalPoint - firstCricticalPoint) {
            maxPoint = lastCricticalPoint - firstCricticalPoint;
        }
        if (minPoint == INT_MAX)
            minPoint = -1;

        return {minPoint, maxPoint};
    }
};

int main() {
    ListNode *head = NULL, *tail = NULL;

    // vector<int> arr = {5, 3, 1, 2, 5, 1, 2};
    vector<int> arr = {3, 1};

    for (int element : arr)
        insertAtTail(head, tail, element);

    print(head);

    Solution s;

    vector<int> ans = s.nodesBetweenCriticalPoints(head);

    for (int i : ans)
        cout << i << ", ";

    cout << endl;

    return 0;
}