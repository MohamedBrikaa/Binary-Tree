#include <stdio.h>
#include <stdlib.h>
typedef struct treeNode treeNode;
treeNode* root;

struct treeNode
{
    int data;
    treeNode *right,*left;
};

treeNode* createNode(int data)
{
    treeNode* newNode=(treeNode*) malloc(1*sizeof(treeNode));

    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void add(treeNode* newNode)
{
    treeNode *parent,*pSearch=root;
    if(root==NULL)
    {
        root=newNode;
    }
    else
    {
        while(pSearch !=NULL)
        {
            parent=pSearch;
            if( (newNode->data) > (pSearch->data) )
            {
                pSearch=pSearch->right;
            }
            else
            {
                pSearch=pSearch->left;
            }
        }
        if( (newNode->data) > (parent->data) )
        {
            parent->right=newNode;
        }
        else
        {
            parent->left=newNode;
        }
    }
}

treeNode* searchNode(int data)
{
    treeNode *psearch=root;
    while(psearch!=NULL)
    {
        if(psearch->data == data)
            return psearch;
        else if(data> psearch->data)
        {
            psearch=psearch->right;
        }
        else
        {
            psearch=psearch->left;
        }
    }
    return NULL;
}

treeNode* getParent(treeNode* child)
{

    treeNode *parent=root;
    if(child==root)
        return NULL;

    while(parent!=NULL)
    {
        if( parent->left == child || parent->right == child )
            return parent;
        else if(child->data > parent->data)
            parent=parent->right;
        else
            parent=parent->left;
    }
    return NULL;

}
void display(treeNode *node)
{
//if(node==NULL)
//    return;
//display(node->left);
//printf(" %d ", node->data);
//display(node->right);

    if(node->left!=NULL)
        display(node->left);
    printf(" %d ", node->data);
    if(node->right!=NULL)
        display(node->right);
}

treeNode* getMaxRight(treeNode* node)
{
    while(node->right != NULL)
    {
        node=node->right;
    }
    return node;
}

void deleteNode(treeNode* pDelete)
{
    treeNode *ptemp,*parent,*maxRight;
    if(pDelete==root)
    {
        if(pDelete->left==NULL && pDelete->right==NULL)
        {
            root=NULL;
        }
        else if(pDelete->left==NULL)
        {
            root=pDelete->right;
        }
        else if(pDelete->right==NULL)
        {
            root=pDelete->left;
        }
        else
        {
            maxRight=getMaxRight(root->left);
            maxRight->right =root->right;
            root=root->left;
        }
    }
    else   // delete non root node
    {
    parent=getParent(pDelete);
    if(pDelete->left==NULL && pDelete->right==NULL)
        {
            ptemp=NULL;
        }
        else if(pDelete->left==NULL)
        {
            ptemp=pDelete->right;
        }
        else if(pDelete->right==NULL)
        {
            ptemp=pDelete->left;
        }else{
            getMaxRight(pDelete->left)->right =pDelete->right;
            ptemp=pDelete->left;
        }
        if(parent->left==pDelete)
            parent->left=ptemp;
        else
            parent->right=ptemp;
    }
    pDelete->left=NULL;
    pDelete->right=NULL;
    free(pDelete);
}

int main()
{

    root=NULL;
    treeNode* node1;

    add(createNode(40));
    add(createNode(70));
    add(createNode(45));
    add(createNode(35));
    add(createNode(65));
    add(createNode(60));
    add(createNode(55));
    add(createNode(75));
    add(createNode(37));
    add(createNode(30));

    display(root);

    deleteNode(searchNode(65));
    printf("\n========= after delete a node ========\n");
    display(root);

    return 0;
}
