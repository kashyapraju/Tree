#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
// finding minimum value
struct node *minValueNode(struct node *node)
{
    struct node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
    {
        printf("Element does not Exist");
        return root;
    }
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
}
// insert a node in a tree
struct node *btinseart(struct node *root, int key)
{
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->left = NULL;
        root->right = NULL;
        root->data = key;
        return root;
    }

    else if (key < root->data)
    {
        root->left = btinseart(root->left, key);
    }
    else
    {
        root->right = btinseart(root->right, key);
    }
}
// search a node in a tree
void binarysearch(struct node *root, int key)
{
    if (root == NULL)
    {
        printf("The number is not found sorry!");
    }
    else if (key == root->data)
    {
        printf("Element is found ");
    }

    else if (key < root->data)
    {
        return binarysearch(root->left, key);
    }
    else
    {
        return binarysearch(root->right, key);
    }
}

struct node preorder(struct node *root) // preorder
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

struct node inorder(struct node *root) // inorder
{
    if (root != NULL)
    {

        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node postorder(struct node *root) // postorder
{
    if (root != NULL)
    {

        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
// creat multiple nodes with the help of this function
struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main()
{
    struct node *p = createNode(4);

    struct node *p1 = createNode(6);

    struct node *p2 = createNode(8);

    struct node *p3 = createNode(9);

    struct node *p4 = createNode(7);

    p1->left = p;
    p1->right = p2;

    p2->left = p4;
    p2->right = p3;

    preorder(p1);
    printf("\n");

    inorder(p1);
    printf("\n");

    postorder(p1);
    printf("\n");

    binarysearch(p1, 890);
    printf("\n");

    btinseart(p1, 50);
    preorder(p1);
    printf("\n");

    inorder(p1);
    printf("\n");

    postorder(p1);
    printf("\n");

   deleteNode(p1,9);

    postorder(p1);
    printf("\n");
    return 0;
}
