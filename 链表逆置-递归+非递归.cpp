#include <iostream>
#include <climits>

using namespace std;
/*
Problem:链表逆置,递归&&非递归
Solution:递归和非递归都要用返回值返回新的链表头节点
*/

struct node{
    int val;
    node *next;
    node(int val):val(val), next(NULL){}
};

void printList(node *root);
node * rever_recur(node *root);
node * rever_nonrecur(node *root);

int main()
{
    node *root=new node(1);
    root->next=new node(2);
    root->next->next=new node(3);
    root->next->next->next=new node(4);

    printList(root);
    node *pr=rever_recur(root);
    printList(pr);

    node *pnr=rever_nonrecur(pr);
    printList(pnr);

    return 0;
}

void printList(node *root){
    node *p=root;
    while(p){
        cout<<p->val<<endl;
        p=p->next;
    }
}
node * rever_recur(node *root){
    if(root==NULL||root->next==NULL)
        return root;

    node *tail=rever_recur(root->next);  //先递归后面的节点
    root->next->next=root;
    root->next=NULL;   //此处没有问题,因为是从尾部向前面处理,root->next节点会在下次调用中用到
    return tail;
}

node* rever_nonrecur(node *root){
    if(root==NULL)
        return root;

    node *pre=NULL;
    node *p=root, *q=NULL;
    while(p->next!=NULL){
        q=p->next;
        p->next=pre;
        pre=p;
        p=q;
    }
    p->next=pre;   //注意这一句不要丢,因为最后那个节点没有连接
    return p;
}
