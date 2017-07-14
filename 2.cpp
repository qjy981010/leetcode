/* 将两个链表对应位置的值相加，若需进位则另j为1，循环版本的parent保存父节点以赋值其next*/

#include<iostream>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* head;

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* iter1 = l1, *iter2 = l2;
		ListNode* parent;
		int i = 1, j = 0, value; // i用于判断是否是第一次循环，若为第一次循环则将head赋值；
		for (;;) {				// j用于判断是否需要进位；
			if (iter1) {
				if (iter2) {
					value = iter1->val + iter2->val + j;
					j = value / 10;
					ListNode* newone = new ListNode(value%10);
					if (i) head = parent = newone;
					else parent = parent->next = newone;
					iter1 = iter1->next;
					iter2 = iter2->next;
				}
				else {
					value = iter1->val + j;
					iter1 = iter1->next;
					parent = parent->next = new ListNode(value>9 ? (j=1,value%10) : (j=0,value));
				}
			}
			else {
				if (iter2) {
					value = iter2->val + j;
					iter2 = iter2->next;
					parent = parent->next = new ListNode(value>9 ? (j=1,value%10) : (j=0,value));
				}
				else {
					break;
				}
			}
			i = 0;
		}
		if (j) parent->next = new ListNode(1);
		
		return head;
    }
};
// 效率超过73%

int main() {
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(2);
	l1->next = new ListNode(2);
	ListNode* l2 = new ListNode(2);
	l2->next = new ListNode(2);
	l2->next = new ListNode(2);
	Solution solve;
	ListNode* head = solve.addTwoNumbers(l1, l2);
	for(; head; head = head->next) {
		cout << head->val << ' ';
	}
	cout << endl;
}

/*
效率差不多，代码更简洁，不过不清真的是把原链表改变了；
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(0); // 代替head
        ListNode* p = &dummy;

        int cn = 0;

        while(l1 || l2) {
            int val = cn + (l1 ? l1->val : 0) + (l2 ? l2->val : 0); // 简化了if-else
            cn = val / 10;
            val = val % 10;
            p->next = new ListNode(val);
            p = p->next;
            if(l1) {
                l1 = l1->next;
            }
            if(l2) {
                l2 = l2->next;
            }
        }

        if(cn != 0) {
            p->next = new ListNode(cn);
            p = p->next;
        }

        return dummy.next;
    }
};
*/

