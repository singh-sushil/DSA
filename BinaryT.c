//c program to find sum of the left leaf node of binary tree
#include<stdio.h>
#include<stdlib.h>
struct BinaryT{
    int data;
    struct BinaryT *right;
    struct BinaryT *left;
};
int item,sum;
struct BinaryT *node = NULL,*newnode;

void createBT(struct BinaryT **node){
    printf("enter the element \n 'enter -1 if u like to terminate current node' ");
    scanf("%d",&item);
    if (item == -1) //-1 input just terminates the further expansion of respective node.
        return;
    *node = (struct BinaryT *)malloc(sizeof(struct BinaryT));
    (*node)->left = NULL;
    (*node)->right = NULL;
    (*node)->data = item;
    
    createBT(&(*node)->left);
    createBT(&(*node)->right);
}
void inorder(struct BinaryT **node)
{
    if (*node == NULL)
    {
        return;
    }
    inorder(&(*node)->left);
    printf("%d\n", (*node)->data);
    inorder(&(*node)->right);
}
void inorderSum(struct BinaryT **node,char flag){
    if(*node == NULL){
        return;
    }
    if((*node)->left == NULL && (*node)->right == NULL && flag == 'l')
        sum = sum + (*node)->data;
    inorderSum(&(*node)->left,'l');
    inorderSum(&(*node)->right,'r');
}

int main(){
    int choice;
    while(1){
       
        
        printf("1:create binary tree\n");
        printf("2:view the tree created so far\n");
        printf("3:calculate the sum of left terminal node of tree created so far\n");
        printf("4:terminate the program\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                createBT(&node);
                break;
            case 2:
                printf("the inorder traversal of tree is \n");
                inorder(&node);
                break;
            case 3:
                inorderSum(&node,'n');
                printf("the sum is %d\n", sum);
                break;
            default:
                printf("invalid input");
                exit(EXIT_FAILURE);
        }
    }
    return 0;
}
