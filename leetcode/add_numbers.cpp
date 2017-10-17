// Add Two Numbers

/*
Single linked list

Examples:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

# include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main(){

}

void createNode(string snode){
    ListNode
    for(int i = 0; i < snode.length(); i++){

    }

    //ListNode* node1 = new ListNode(1);
    ListNode node1(0);
    ListNode* pNode1 = &node1;
    pNode1->next = new ListNode(3);
    pNode1 = pNode1->next;

    pNode1->next = new ListNode(5);
    pNode1 = pNode1->next; // NULL
    pNode1->next = NULL;

    ListNode* pnode = node1.next;
    while(pnode != NULL){
        std::cout << pnode->val << "\n";
        pnode = pnode->next;
    }
}