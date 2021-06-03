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

//노드 만들기
Node* DLL_CreateNode(NodeData NewData);
//노드 추가
void DLL_AppendNode(Node** Head, Node* NewNode);
//노드 색인
Node* DLL_GetNodeAt(Node* Head, int Index);
//노드 삽입 뒤
void DLL_InsertAfter(Node* Current, Node* NewNode);
//노드 삽입 앞
void DLL_InsertBefore(Node** List, Node* Current, Node* NewNode);
//노드 삭제
void DLL_RemoveNode(Node** Head, Node* Remove);
//노드 빼기
void DLL_CLipNode(Node** Head, Node* Remove);
//노드 개수
int DLL_GetNodeCount(Node* Head);
//모든 노드 삭제
void DLL_DestroyAllNodes(Node** Head);
//링크드 리스트 역순 출력
void DLL_PrintReverse(Node* Head);
//더블리 링크드 리스트 삽입 정렬
void DLL_InsertionSort(Node** List);

#endif
