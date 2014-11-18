#include <iostream>

using namespace std;

/*
Problem:二分查找树转化为双向链表（直接用树节点的left，right指针表示）
Solution：递归，找到当前节点左子树的lhead和ltail，然后将ltail指向它；再找它右子树的rhead和rtail，将它指向head；最后返回head
*/
struct node{
    int val;
    node *left;
    node *right;
    node(int v):val(v), left(NULL),right(NULL){}
};
void printTree(node *root){
    if(root==NULL)
        return;
    cout<<root->val<<endl;
    printTree(root->left);
    printTree(root->right);
}
void printList(node *root){
    if(root==NULL)
        return;
    cout<<root->val<<endl;
    printTree(root->right);
}

void transToList(node *root, node *&head, node *&tail){
    if(root==NULL){
        head=NULL;
        tail=NULL;
        return;
    }
    node *lt, *rh;
    transToList(root->left, head, lt);
    transToList(root->right, rh, tail);
    if(lt){
        lt->right=root;
        root->left=lt;
    }
    else{
        head=root;
    }
    if(rh){
        root->right=rh;
        rh->left=root;
    }
    else{
        tail=root;
    }
}

node* trans(node *root){
    node *head=NULL, *tail=NULL;
    transToList(root, head, tail);
    return head;
}
int main()
{
    node *root=new node(5);
    root->left=new node(3);
    root->left->left=new node(1);
    root->left->right=new node(4);
    root->right=new node(7);
    root->right->left=new node(6);
    root->right->right=new node(8);

    printTree(root);

    node *head=trans(root);
    for(int i=0; i<7; i++){
        cout<<head->val<<endl;
        head=head->right;
    }
    cout << "Hello world!" << endl;
    return 0;
}
