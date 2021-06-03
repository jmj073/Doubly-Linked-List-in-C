#define _CRT_SECURE_NO_WARNINGS
#include "Doubly Linked List.h"

void main(void) {
	int i;
	NodeData n;
	Node* List = NULL;
	Node* Current = NULL;

	while (1) {
		scanf("%d", &n);
		if (n == 99) break;
		DLL_AppendNode(&List, DLL_CreateNode(n));
	}

	Current = List;
	for (i = 0; Current != NULL; i++) {
		printf("%d: %d\n", i, Current->Data);
		Current = Current->NextNode;
	}
	printf("\n\n\n");

	DLL_InsertionSort(&List);
	printf("---------------------------------\n");
	Current = List;
	for (i = 0; Current != NULL; i++) {
		printf("%d: %d\n", i, Current->Data);
		Current = Current->NextNode;
	}

}