
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ΰ� ��ũ�帮��Ʈ�� �⺻���� �Լ��� �ٷ�� �ڼ��� ������ ���� ����.
// ����� Ʋ�� �����س��� ����. 

typedef struct node {
	char* data;
	struct node* next;
	struct node* prev;
} Node;

Node* head;
Node* tail;
int size = 0;

Node* createNode(char* data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = strdup(data);
	node->next = NULL;
	node->prev = NULL;
	
	size++;
	
	return node;
}

Node* unshiftNode(char* data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = strdup(data);
	node->next = head;
	node->prev = NULL;
	head->prev = node;
	head = node;
	
	size++;
	
	return node;
}

Node* appendNode(char* data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = strdup(data);
	node->next = NULL;
	node->prev = tail;
	tail = node;
	
	size++;
	
	return node;
}

Node* insertNode(char* data, Node* after_node) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = strdup(data);
	node->next = after_node;
	node->prev = after_node->prev;
	after_node->prev->next = node;
	after_node->prev = node;
	
	size++;
	
	return node; 
}

void removeNode(Node* target_node) {
	target_node->prev->next = target_node->next;
	target_node->next->prev = target_node->prev;
	
	size--;
	
	free(target_node->data);
	free(target_node);
}

void printAll() {
	Node* temp = head;
	
	while(temp != NULL){
		printf("%s\n", temp->data);
		
		temp = temp->next;
	}
}

void freeAll() {
	Node* temp = head;
	
	while(temp != NULL) {
		free(temp->data);
		free(temp);
		
		temp = temp->next;
	}
}

int main() {
	head = createNode("head");
	unshiftNode("node1");
	
	printAll();
	freeAll();
	
	return 0;
}




















