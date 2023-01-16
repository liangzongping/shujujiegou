#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};
int isPalindrome(struct ListNode* head) {

    struct ListNode* h1 = head;
    struct ListNode* h2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    h2->val = h1->val;
    h2->next = NULL;
    while (h1)
    {

        h1 = h1->next;//复制原链表，有链表不改变

        struct ListNode* h = (struct ListNode*)malloc(sizeof(struct ListNode));
        h->next = NULL;
        struct ListNode* tail = h2;
        while (tail->next)
        {
            tail = tail->next;
        }
        tail->next = h;
        if (h1 != NULL)
            h->val = h1->val;

    }

    struct ListNode* newhead = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        //链表的反转，原链表发生了改变
        struct ListNode* next = cur->next;//head的路线已改变
        cur->next = newhead;
        newhead = cur;
        cur = next;
    }
    while (h2 && newhead)
    {
        if (newhead->val != h2->val)
            return 0;
        h2 = h2->next;
        newhead = newhead->next;
    }
    return 1;
}
int main()
{
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));

    n1->val = 3;
    n2->val = 1;
    n3->val = 1;
    n4->val = 3;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;
    if (isPalindrome(n1))
        printf("true");
    else
        printf("false");

    return 0;
}