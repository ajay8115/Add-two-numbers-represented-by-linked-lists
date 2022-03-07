// CODE BY :- AJAY PAL IIT (BHU) VARANASI
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *reverse(struct Node *head)
    {
        Node *cur = NULL;
        while (head != NULL)
        {
            Node *next = head->next;
            head->next = cur;
            cur = head;
            head = next;
        }
        return cur;
    }

    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        Node *p1 = reverse(first);
        Node *p2 = reverse(second);

        Node *dummy = new Node(0);
        Node *temp = dummy;
        int cary = 0;
        while (p1 != NULL || p2 != NULL || cary != 0)
        {
            int sum = 0;
            if (p1 != NULL)
            {
                sum += p1->data;
                p1 = p1->next;
            }

            if (p2 != NULL)
            {
                sum += p2->data;
                p2 = p2->next;
            }

            sum += cary;
            cary = sum / 10;
            Node *node = new Node(sum % 10);

            temp->next = node;
            temp = temp->next;
        }

        return reverse(dummy->next);
    }
};

 