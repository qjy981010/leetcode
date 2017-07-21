/*一开始的思路是把每个节点递归遍历，给每个节点新建一个copy，并让原节点的next指向他的copy，
然后在递归回来时把random指针赋值，并返回新建节点，让上一个节点的next接受返回值即可构建完整链表
但是果然骗不了leetcode，原链表改变出错。
然后，就想先让新建节点的next指向原节点的next，这样就可以在最后把原链表恢复*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) return nullptr;
        RandomListNode *my_iterator = head;
		RandomListNode *newnode;
		for (; my_iterator; my_iterator = my_iterator->next->next) { // 新建节点并插入原链表
			newnode = new RandomListNode(my_iterator->label);
			newnode->next = my_iterator->next;
			my_iterator->next = newnode;
		}
		for (my_iterator = head; my_iterator; my_iterator = my_iterator->next->next) { // 处理random指针
			my_iterator->next->random = my_iterator->random ? my_iterator->random->next : nullptr;
		}
		my_iterator = head;
		RandomListNode *newhead = my_iterator->next;
		for (; ; my_iterator = my_iterator->next) { // 复原新旧链表
			newnode = my_iterator->next;
			if (my_iterator->next = newnode->next) newnode->next = my_iterator->next->next;
            else {
                newnode->next = nullptr;
                return newhead;
            }
		}
    }
};

// 效率可以到84%
