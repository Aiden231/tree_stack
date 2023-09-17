#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// LInked 구현을 위한 구조체 생성
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

// 스택 생성
#define SIZE 100
int top = -1;
TreeNode* stack[SIZE];

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

// 삽입 함수
void push(TreeNode* p)
{
	if (top < SIZE - 1) {
		stack[++top] = p;
	}
}

// 삭제 함수
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
		if (root != NULL) {
			printf("%d ", root->data);
			push(root->right); // stack에 삽입하기 떄문에 오른쪽 자식 먼저 넣기
			push(root->left);  // 왼쪽 자식 넣기
		}
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
		root = root->right;
	}
}

// 출력 스택
int top_output = -1;
TreeNode* stack_output[SIZE];

// 후위 순회 출력 함수
void postorder_iter(TreeNode* root)
{
	if (root == NULL) // 비어있으면 리턴
		return;

	push(root);

	while (top != -1) {
		TreeNode* current = pop();

		// 루트를 stack_output에 추가
		stack_output[++top_output] = current;

		if (current->left)
			push(current->left);
		if (current->right)
			push(current->right);
	}

	// stack_output을 출력하면 후위 순회 결과가 나옴
	while (top_output != -1) {
		TreeNode* current = stack_output[top_output--];
		printf("%d ", current->data);
	}
}

int main()
{
	printf("Traversal with Stack\n");

	// 전위 순회 출력
	printf("1. 전위 순회\n");
	preorder_iter(root);
	printf("\n\n");

	// 중위 순회 출력
	printf("2. 중위 순회\n");
	inorder_iter(root);
	printf("\n\n");

	// 후위 순회 출력
	printf("3. 후위 순회\n");
	postorder_iter(root);
	printf("\n\n");

	return 0;
}