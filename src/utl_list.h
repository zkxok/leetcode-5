/* utl_list.h --- 
 * Filename: utl_list.h
 * Created: Tue Aug 21 21:41:34 2018 (+0800)
 */

/* Copyright Hamlet zheng.
 * 
 * 允许免费使用，拷贝，修改，发布，但在所有的拷贝上必须保留上述
 * copyright部分和本使用声明部分，除非显示声明，copyright的持有者
 * 不得作为再发布软件的广告。copyright的持有者对使用本软件的适用范围不做任何声明，
 * 
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 */

#ifndef UTL_LIST_H_
#define UTL_LIST_H_

#include <vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

/* A utility function to create list from array */
ListNode* init_list(vector<int>& nums);
/* A utility function to insert a node at the beginning of linked list */
void push(struct ListNode** head_ref, int val);
/* A utility function to print linked list */
void print_list(struct ListNode *node);
/**
 * quick sort list 
 * usage: quick_sort_list1(head, head+node_cnt)
 */
void quick_sort_list1(ListNode* pBegin , ListNode* pEnd);
/**
 * quick sort list 
 * usage: quick_sort_list1(head, NULL)
 */
void quick_sort_list2(ListNode* pBeign, ListNode* pEnd);

// leetcode 2
ListNode* add_two_numbers(ListNode* l1, ListNode* l2);
// leetcode 445
ListNode* add_two_numbers2(ListNode* l1, ListNode* l2);
// leetcode 21
ListNode* merge_two_sorted_lists(ListNode* l1, ListNode* l2);
// leetcode 23
ListNode *merge_k_lists(vector<ListNode *> &lists);
// leetcode 19
struct ListNode* remove_nth_from_end(struct ListNode* head, int n);
// leetcode 25
ListNode *reverse_kgroup(ListNode *head, int k);
ListNode *reverse_one_group(ListNode *pre, ListNode *next);
// leetcode 24
ListNode* swap_pairs(ListNode* head);
// leetcode 147
ListNode* insertion_sort_list(ListNode* head);
// leetcode 148
ListNode* merge_sort_list(ListNode* head);
// leetcode 61
ListNode* rotate_right(ListNode* head, int k);
// leetcode 141
bool has_cycle(struct ListNode *head);
// leetcode 160
ListNode *get_intersection_node(struct ListNode *head1, struct ListNode *head2);
// leetcode 206
ListNode* reverse_list_r(ListNode* head);
ListNode* reverse_list(ListNode* head);
// leetcode 92
ListNode* reverse_between(ListNode* head, int m, int n);
// leetcode 876
ListNode* middle_node(ListNode* head);
// leetcode 83
ListNode* delete_duplicates(struct ListNode* head);
// leetcode 82
ListNode* delete_duplicates2(ListNode* head);
// leetcode 85
ListNode* partition(ListNode* head, int x);
// leetcode 234
bool is_palindrome(ListNode* head);
// leetcode 328
ListNode* odd_even_list(ListNode* head);

#endif
