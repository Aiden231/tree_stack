#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// LInked ������ ���� ����ü ����
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * rigth;
}TreeNode;

// ���� Ʈ�� LInked�� ����
TreeNode n11 = { 11,NULL,NULL };
TreeNode n10 = { 10,NULL,NULL };
TreeNode n9 = { 9, &n10,&n11 };
TreeNode n8 = { 8, NULL,NULL };
TreeNode n7 = { 7, &n8,&n9 };
TreeNode n6 = { 6,NULL,NULL };
TreeNode n5 = { 5, NULL,NULL };
TreeNode n4 = { 4,NULL,NULL };
TreeNode n3 = { 3,&n4,&n5 };
TreeNode n2 = { 2,&n3,&n6 };
TreeNode n1 = { 1,&n2,&n7 };

// ��Ʈ�� n1 �̴�.
TreeNode* root = &n1;

#define SIZE 100
int top = -1;
TreeNode* stack[SIZE];

void push(TreeNode* p)
{
	if (top < SIZE - 1) {
		stack[++top] = p;
	}
}

TreeNode* pop()
{
	TreeNode* p = NULL;
	if (top >= 0) {
		p = stack[top--];
	}
	return p;
}
// ���� ��ȸ ��� �Լ�
void preorder_iter(TreeNode* root)
{
	push(root);
	while (top != -1) {
		root = pop();
		printf("%d ", root->data);
		push(root->left);
		push(root->rigth);
	}
}

// ���� ��ȸ ��� �Լ�
void inorder_iter(TreeNode* root)
{
	while (1) {
		for (; root; root = root->left)
			push(root);
		root = pop();
		if (!root) break;
		printf("%d ", root->data);
		root = root->rigth;
	}
}

int main()
{
	printf("Traversal with Stack\n");

	// ���� ��ȸ ���
	printf("1. ���� ��ȸ\n");
	preorder_iter(root);
	printf("\n");

	// ���� ��ȸ ���
	printf("2. ���� ��ȸ\n");
	inorder_iter(root);
	printf("\n");

	// ���� ��ȸ ���
	printf("3. ���� ��ȸ\n");
	printf("\n");

	return 0;
}