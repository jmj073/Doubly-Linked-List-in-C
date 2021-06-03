#include "Doubly Linked List.h"

//��� �����
Node* DLL_CreateNode(NodeData NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

//��� �߰�
void DLL_AppendNode(Node** Head, Node* NewNode) {
	if (*Head == NULL)
		*Head = NewNode;
	else {
		Node* Tail = *Head;
		while (Tail->NextNode != NULL)
			Tail = Tail->NextNode;
		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail;
	}
}

//��� ����
Node* DLL_GetNodeAt(Node* Head, int Index) {
	while (Head != NULL && (--Index) >= 0)
		Head = Head->NextNode;
	return Head;
}

//��� ���� ��
void DLL_InsertAfter(Node* Current, Node* NewNode) {
	NewNode->PrevNode = Current;
	NewNode->NextNode = Current->NextNode;
	if (Current->NextNode != NULL) 
		Current->NextNode->PrevNode = NewNode;
	Current->NextNode = NewNode;
}

//��� ���� ��
void DLL_InsertBefore(Node** List, Node* Current, Node* NewNode) {
	NewNode->NextNode = Current;
	if ((*List) == Current) {
		NewNode->PrevNode = NULL;
		*List = NewNode;
	}
	else {
		Current->PrevNode->NextNode = NewNode;
		NewNode->PrevNode = Current->PrevNode;
	}
	Current->PrevNode = NewNode;
}

//��� ����
void DLL_RemoveNode(Node** Head, Node* Remove) {
	if (*Head == Remove) {
		*Head = Remove->NextNode;
		if ((*Head) != NULL)
			(*Head)->PrevNode = NULL;
	}
	else {
		Remove->PrevNode->NextNode = Remove->NextNode;
		if (Remove->NextNode != NULL)
			Remove->NextNode->PrevNode = Remove->PrevNode;
	}
	free(Remove);
}

//��� ����
void DLL_CLipNode(Node** Head, Node* Remove) {
	if (*Head == Remove) {
		*Head = Remove->NextNode;
		if ((*Head) != NULL)
			(*Head)->PrevNode = NULL;
	}
	else {
		Remove->PrevNode->NextNode = Remove->NextNode;
		if (Remove->NextNode != NULL)
			Remove->NextNode->PrevNode = Remove->PrevNode;
	}
}

//��� ����
int DLL_GetNodeCount(Node* Head) {
	int i;
	for ( i = 0; Head->NextNode != NULL; i++)
		Head->NextNode;
	return i;
}

//��� ��� ����
void DLL_DestroyAllNodes(Node** Head) {
	Node* Current = *Head;
	while (Current->NextNode != NULL) {
		Current = Current->NextNode;
		free(Current->PrevNode);
	}
	free(Current);
	*Head = NULL;
}

//��ũ�� ����Ʈ ���� ���
void DLL_PrintReverse(Node* Head) {
	for (int i = 0; Head != NULL; i++) {
		printf("%d: %d\n", i, Head->Data);
		Head = Head->NextNode;
	}
}

//���� ��ũ�� ����Ʈ ���� ����
void DLL_InsertionSort(Node** List) {
	Node* Current, * Prev, * Keep;
	NodeData Value;
	if ((*List)->NextNode == NULL)
		return;
	else
		Keep = (*List)->NextNode;
	while (Keep != NULL) {
		Current = Keep;
		if (Current->PrevNode->Data <= Current->Data) {
			Keep = Keep->NextNode;
			continue;
		}
		Value = Current->Data, Prev = (*List);
		while (Value != Current) {
			if (Prev->Data > Value) 
				break;
			Prev = Prev->NextNode;
		}
		Keep = Keep->NextNode;
		DLL_CLipNode(List, Current);
		DLL_InsertBefore(List, Prev, Current);
	}
}