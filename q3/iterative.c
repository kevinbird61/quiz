#include <stdio.h>
#include <stdlib.h>

typedef struct _Binary_Tree {
    int value;
    struct _Binary_Tree *left;
    struct _Binary_Tree *right;
} BT;

BT *concat;
void Init(BT *root,int append);
void Print(BT *root);
void flatten_iter(BT *root);

int main()
{
    BT *root = malloc(sizeof(BT));
    concat = malloc(sizeof(BT));
    root->left = NULL;
    root->right = NULL;
    int i;
    /* Build the Example Tree*/
    for(i=1; i<=6; i++) {
        Init(root,i);
    }
    /* Print Test */
    Print(root);
    /* flatten the Tree */
    flatten_iter(root);
    /* Check it */
    printf("=============================\n");
    Print(root);

    return 0;
}


/* Function Implementation */

void Init(BT *root,int append)
{
    BT *temp = malloc(sizeof(BT));
    BT *stand = malloc(sizeof(BT));
    temp = root;
    if(temp->left!=NULL) {
        if(temp->right!=NULL) {
            temp = temp->left;
            Init(temp,append);
        } else {
            temp->right = stand;
            stand->value = append;
            stand->left = NULL;
            stand->right = NULL;
            return;
        }
    } else {
        temp->left = stand;
        stand->value = append;
        stand->left = NULL;
        stand->right = NULL;
        return;
    }
}

void Print(BT *root)
{
    if(root->left!=NULL) {
        printf("Left Node is %d\n",root->value);
        Print(root->left);
    } else {
        printf("End Leaf Node is %d\n",root->value);
        return;
    }
    if(root->right!=NULL) {
        printf("Right Node is %d\n",root->value);
        Print(root->right);
    } else {
        printf("End Leaf Node is %d\n",root->value);
        return;
    }
}

/* This Function can only use on left-side binary tree */
void flatten_iter(BT *root)
{
    concat = root;
    BT *temp;
    while(concat->left != NULL) {
        if(concat->right!=NULL) {
            temp = concat->right;
            concat->right = NULL;
            temp->left = concat->left;
            concat->left = temp;
            concat = concat->left;
        } else {
            concat = concat->left;
        }
    }
}


