#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// LInked 구현을 위한 구조체 생성
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * rigth;
}TreeNode;

// 이진 트리 LInked로 구현
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

// 루트는 n1 이다.
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
// 전위 순회 출력 함수
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

// 중위 순회 출력 함수
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

	// 전위 순회 출력
	printf("1. 전위 순회\n");
	preorder_iter(root);
	printf("\n");

	// 중위 순회 출력
	printf("2. 중위 순회\n");
	inorder_iter(root);
	printf("\n");

	// 후위 순회 출력
	printf("3. 후위 순회\n");
	printf("\n");

	return 0;
}