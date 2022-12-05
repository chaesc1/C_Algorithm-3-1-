#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 200
#define MAX_POOM_SIZE 200
#define MAX_MEANING_SIZE 100
#define MAX_FILE_SIZE

typedef struct{
    char word[MAX_WORD_SIZE];
    char poom[MAX_POOM_SIZE];
    char meaning[MAX_MEANING_SIZE];
}element;

//노드 구조
typedef struct treeNode{
    element key;
    struct treeNode* left;
    struct treeNode* right;
}treeNode;

void insertNode(treeNode **root, element x)
{
    treeNode * nNode;//newNode
    treeNode * qNode = NULL;//상입할 자리 찾는 포인터변수
    treeNode * pNode = *root; //삽입할 노드의 부모노드를 저장하기 위한 방법

    while(pNode != NULL)
    {
        if(strcmp(x.word,pNode->key.word)==0)
        {
            printf("\n\t 이미 같은 키가 있습니다\n");
            return;
        }

        qNode = pNode;

        if(strcmp(x.word,pNode->key.word)<0)//s1<s2 (strcmp = -1 )
        {
            pNode = pNode -> left;
        }
        else if(strcmp(x.word,pNode->key.word) > 0) //s1 > s2 (strcmp = 1)
        {
            pNode = pNode -> right;
        }
    }

    //삽입할 자리 찾았고 삽입할 노드 생성
    nNode = (treeNode*)malloc(sizeof(treeNode)); //공간 할당
    nNode -> key = x;//새 노드 key를 x의 값으로 할당(word,meaning,poom)
    nNode -> left = NULL;
    nNode -> right = NULL;

    if(qNode != NULL)
    {
        if(strcmp(x.word,qNode->key.word) < 0)
        {
            qNode -> left = nNode;
        }
        else if (strcmp(x.word,qNode->key.word) > 0)
        {
            qNode -> right = nNode;
        }
    }
    else
    {
        *root = nNode;
    }
}

void deleteNode(treeNode **root,element x)
{
    treeNode *parent = NULL;
    treeNode *pNode = *root;
    treeNode *child;
    treeNode *succ,*succ_parent;//후계자 노드 구하기

    while((pNode != NULL)&&(strcmp(x.word,pNode->key.word)!=0))
    {
        parent = pNode;
        if(strcmp(x.word,pNode -> key.word)<0)  
        {
            pNode=pNode->left;
        }
        else
        {
            pNode=pNode->right;
        }
    }

    if(pNode==NULL)
    {
        return;
    }
    //삭제후 처리 종류3가지 - 단말노드인 경우
    if((pNode->left == NULL)&&(pNode->right==NULL))
    {
        if(parent!=NULL)
        {
            if(parent->left == pNode)
                parent->left = NULL;//부모노드 왼쪽이 삭제할 노드 일 경우
            else
                parent->right = NULL;//부모노드 오른쪽이 삭제할 노드 일 경우
        } 
        else
            root = NULL;
    }
    else if((pNode->left == NULL) || (pNode->right == NULL))//삭제할 노드가 한 개의 자식노드를 가진경우
    {
        if(pNode -> left != NULL)
            child = pNode -> left;//삭제할 노드의 왼쪽을 자식노드로 연결
        else 
            parent->right = child; // 삭제할 노드의 오른쪽 자식노드로 연결
        
        if(parent != NULL)
        {
            if(parent->left == pNode)
                parent->left = child; //부모노드 왼쪽이 삭제 노드면 자식노드를  부모노드의 왼쪽과 연결
            else
                parent->right = child;
        }
        else
        {
            *root = child;
        }
    }
    else
    {
        succ_parent = pNode;
        succ = pNode->left;//욎쪽 서브트리에서 후계자를 찾는다.
        while (succ->right != NULL)//후계자를 찾아서 계속 오른쪽으로 이동
        {
            succ_parent = succ; //값의 비교를 위해 탐색중인 노드의 부모값도 같이 이동
            succ = succ -> right;//왼쪽 서브트리(가장 오른쪽 노드)오른쪽서브트리(가장 왼쪽 노드)
        }
        //왼쪽 서브트리에서 오른쪽 값이 없는 경우 삭제할 노드의 왼쪽 노드가 후계자가 된다.
        if(succ_parent -> left == succ)
            succ = succ_parent -> left;
        else
            succ_parent->right = succ -> left;
        
        pNode -> key = succ -> key;
        pNode = succ;
    }
    free(pNode);
}
int main(void)
{
    element e;
    FILE* fp = fopen("/Users/chaejunghun/Desktop/shuffled_dict.txt","r");
    FILE* dfp = fopen("/Users/chaejunghun/Desktop/search_words.txt","r");

    if(fp == NULL)
    {
        printf("NO FILE");
        return 0;
    }

    int i=0;

    while(!feof(fp))
    {
        fscanf(fp,"%s",&e.word,&e.poom,&e.meaning);
        printf("%s %s %s",e.word,e.poom,e.meaning);
        printf("\n");
    }
    fclose(fp);
    
    
    return 0;
}