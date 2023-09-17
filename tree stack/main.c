#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// LInked ������ ���� ����ü ����
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

// ���� ����
#define SIZE 100
int top = -1;
TreeNode* stack[SIZE];

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

// ���� �Լ�
void push(TreeNode* p)
{
	if (top < SIZE - 1) {
		stack[++top] = p;
	}
}

// ���� �Լ�
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
		if (root != NULL) {
			printf("%d ", root->data);
			push(root->right); // stack�� �����ϱ� ������ ������ �ڽ� ���� �ֱ�
			push(root->left);  // ���� �ڽ� �ֱ�
		}
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
		root = root->right;
	}
}

// ��� ����
int top_output = -1;
TreeNode* stack_output[SIZE];

// ���� ��ȸ ��� �Լ�
void postorder_iter(TreeNode* root)
{
	if (root == NULL) // ��������� ����
		return;

	push(root);

	while (top != -1) {
		TreeNode* current = pop();

		// ��Ʈ�� stack_output�� �߰�
		stack_output[++top_output] = current;

		if (current->left)
			push(current->left);
		if (current->right)
			push(current->right);
	}

	// stack_output�� ����ϸ� ���� ��ȸ ����� ����
	while (top_output != -1) {
		TreeNode* current = stack_output[top_output--];
		printf("%d ", current->data);
	}
}

int main()
{
	printf("Traversal with Stack\n");

	// ���� ��ȸ ���
	printf("1. ���� ��ȸ\n");
	preorder_iter(root);
	printf("\n\n");

	// ���� ��ȸ ���
	printf("2. ���� ��ȸ\n");
	inorder_iter(root);
	printf("\n\n");

	// ���� ��ȸ ���
	printf("3. ���� ��ȸ\n");
	postorder_iter(root);
	printf("\n\n");

	return 0;
}