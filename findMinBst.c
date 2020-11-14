#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node *insertBST(struct node *root,int x)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
        temp->left = NULL;
        temp->right = NULL;
        temp->data = x;
    if(root == NULL)
        return temp;
    else if(x>root->data)
        root->right = insertBST(root->right,x);
    else
        root->left = insertBST(root->left,x);
    return root;
}
struct node *findMin(struct node *root)
{
    if(root == NULL)
    {
        return NULL;
    }
    while(root->left != NULL)
        root = root->left;
    return root;
}
void inorder(struct node *root)
{
    struct node *temp = root;
    if(temp != NULL)
    {
        inorder(temp->left);
        printf("%d",temp->data);
        inorder(temp->right);
    }
    printf("\n");
}

int main() {
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
    
        struct node *root = (struct node *) malloc(sizeof(struct node));
        root->left = NULL;
        root->right = NULL;

        char arr[10000];
        scanf("%s ",arr);
        //printf("%s",arr);
        i=0;
        while(arr[i]!='\0')
        {
            //printf("%c",arr[i]);
            if(arr[i] == 'N' || arr[i] == '0')
                continue;
            root = insertBST(root,(arr[i]-'0'));
            i++;
        }
        //inorder(root);
        root = findMin(root);
        if(root == NULL)
            printf("-1\n");
        else
            printf("%d\n",root->data);

    }

	return 0;
}