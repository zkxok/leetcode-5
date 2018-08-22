// utl_list.cpp --- 
// Filename: utl_list.cpp
// Created: Tue Aug 21 21:41:51 2018 (+0800)
// 
// 
// Copyright Hamlet zheng.
// 
// 允许免费使用，拷贝，修改，发布，但在所有的拷贝上必须保留上述
// copyright部分和本使用声明部分，除非显示声明，copyright的持有者
// 不得作为再发布软件的广告。copyright的持有者对使用本软件的适用范围不做任何声明，
// 
// THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
// INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
// EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
// CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
// DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
// TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.
// 
// 

#include "utl_list.h"

using namespace std;

ListNode* init_list(vector<int>& nums)
{
    if (nums.size() <= 0)
        return NULL;
    ListNode* head, *p;
    head = new ListNode(nums[0]);
    p = head;
    for (int i = 1; i < nums.size(); ++i) {
        p->next = new ListNode(nums[i]);
        p = p->next;
    }
    return head;
}

ListNode* add_two_numbers_helper(ListNode* l1, ListNode* l2, int carry)
{
    ListNode* node = NULL;
    if (l1 && l2) {
        node = new ListNode((l1->val + l2->val + carry) % 10);
        carry = (l1->val + l2->val + carry) / 10;
        node->next = add_two_numbers_helper(l1->next, l2->next, carry);
    } else if (l1 && !l2) {
        node = new ListNode((l1->val + carry) % 10);
        carry = (l1->val + carry) / 10;
        node->next = add_two_numbers_helper(l1->next, NULL, carry);
    } else if (!l1 && l2) {
        node = new ListNode((l2->val + carry) % 10);
        carry = (l2->val + carry) / 10;
        node->next = add_two_numbers_helper(NULL, l2->next, carry);
    } else {
        if (carry != 0)
            node = new ListNode(carry);
    }
    return node;
}

ListNode* add_two_numbers(ListNode* l1, ListNode* l2)
{
    if (NULL == l1)
        return l2;
    if (NULL == l2)
        return l1;
    return add_two_numbers_helper(l1, l2, 0);
}

ListNode* merge_two_sorted_lists(ListNode* l1, ListNode* l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    ListNode* head = NULL;
    ListNode* p = NULL;
    while (l1 || l2) {
        if (l1 && l2) {
            if (!head) {
                head = l1->val <= l2->val ? new ListNode(l1->val) : new ListNode(l2->val);
                p = head;
                    
            } else {
                p->next = l1->val <= l2->val ? new ListNode(l1->val) : new ListNode(l2->val);
                p = p->next;
            }
            if (l1->val <= l2->val)
                l1 = l1->next;
            else
                l2 = l2->next;
        } else if (l1 && !l2) {
            p->next = new ListNode(l1->val);
            p = p->next;
            l1 = l1->next;
        } else if (!l1 && l2) {
            p->next = new ListNode(l2->val);
            p = p->next;
            l2 = l2->next;
        }
    }
    return head;
}

struct ListNode* remove_nth_from_end(struct ListNode* head, int n)
{
    if (!head->next)
        return NULL;
    struct ListNode *pre = head, *cur = head;
    for (int i = 0; i < n; ++i) 
        cur = cur->next;
    if (!cur) 
        return head->next;
    while (cur->next) {
        cur = cur->next;
        pre = pre->next;
    }
    pre->next = pre->next->next;
    return head;
}
