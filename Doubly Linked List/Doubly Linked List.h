#ifndef DLL_H
#define DLL_H
#include <stdio.h>
#include <malloc.h>

typedef int NodeData;

typedef struct tagNode {
	NodeData Data;
	struct tagNode* PrevNode;
	struct tagNode* NextNode;
}Node;

//��� �����
Node* DLL_CreateNode(NodeData NewData);
//��� �߰�
void DLL_AppendNode(Node** Head, Node* NewNode);
//��� ����
Node* DLL_GetNodeAt(Node* Head, int Index);
//��� ���� ��
void DLL_InsertAfter(Node* Current, Node* NewNode);
//��� ���� ��
void DLL_InsertBefore(Node** List, Node* Current, Node* NewNode);
//��� ����
void DLL_RemoveNode(Node** Head, Node* Remove);
//��� ����
void DLL_CLipNode(Node** Head, Node* Remove);
//��� ����
int DLL_GetNodeCount(Node* Head);
//��� ��� ����
void DLL_DestroyAllNodes(Node** Head);
//��ũ�� ����Ʈ ���� ���
void DLL_PrintReverse(Node* Head);
//���� ��ũ�� ����Ʈ ���� ����
void DLL_InsertionSort(Node** List);

#endif
