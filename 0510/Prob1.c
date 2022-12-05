#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 600000
#define MAX_POOM_SIZE 600000
#define MAX_MEANING_SIZE 600000

typedef struct
{
    /* data */
    char word[MAX_WORD_SIZE];
    char poom[MAX_POOM_SIZE];
    char meaning[MAX_MEANING_SIZE];
}element;

typedef struct TreeNode {
    element key;
    struct TreeNode* left, * right;
}TreeNode;

int compare(element e1, element e2) {
    return strcmp(e1.word, e2.word);
}

void display(TreeNode* p) {
    if (p != NULL) {
        printf("(");
        display(p->left);
        printf("%s %s %s", p->key.word,p->key.poom,p->key.meaning);
        display(p->right);
        printf(")");
    }
}

TreeNode* search(TreeNode* root, element key) {
    TreeNode* p = root;
    while (p != NULL) {
        switch (compare(key, p->key)) {
        case -1:
            p = p->left; break;
        case 0:
            return p;
        case 1:
            p = p->right; break;
        }
    }
    return p;
}



void insert_node(TreeNode** root, element key) {
    TreeNode* p, *t;
    TreeNode* n;
    t = *root;
    p = NULL;
    while (t != NULL) {
        if (compare(key, t->key) == 0) return;
        p = t;
        if (compare(key, t->key) < 0)
            t = t->left;
        else
            t = t->right;
    }
    n = (TreeNode*)malloc(sizeof(TreeNode));

    n->key = key;
    n->left = NULL;
    n->right = NULL;
    
    if (p != NULL)
        if (strcmp(key.word, p->key.word) < 0)
            p->left = n;
        else p->right = n;
    else *root = n;
}

void delete_node(TreeNode** root, element key) {
    TreeNode* p, * child, * succ, * succ_p, * t;
    // key 를 갖는 노드 t 를 탐색하며, p 는 t 의 부모 노드입니다!
    p = NULL;
    t = *root;
    //key 를 가지고 있는 노드 t 를 탐색합니다.
    while (t != NULL && compare(t->key, key) != 0) {
        p = t;
        t = (compare(t->key, key) < 0) ? t->left : t->right;
    }
    //key 가 없을 경우
    if (t == NULL) {
        printf("키값이 없습니다...");
        return;
    }
    //key 는 찾았는데 터미널 노드인 경우
    if ((t->left == NULL) && (t->right == NULL)) {
        if (p != NULL) {
            if (p->left == t)
                p->left = NULL;
            else p->right = NULL;
        }
        else
            *root = NULL;
    }
    //key 는 찾았는데 한쪽만 서브트리가 있는 경우
    else if ((t->left == NULL) || (t->right == NULL)) {
        child = (t->left != NULL) ? t->left : t->right;
        if (p != NULL) {
            if (p->left == t)
                p->left = child;
            else p->right = child;
        }
        else
            *root = child;
    }
    //key 는 찾았는데 양쪽에 서브트리가 있는 경우
    else {
        succ_p = t;
        succ = t->right;
        // 우측 서브트리로 쭉쭉 내려갑시다.
        while (succ->left != NULL) {
            succ_p = succ;
            succ = succ->left;
        }
        if (succ_p->left == succ)
            succ_p->left = succ->right;
        else
            succ_p->right = succ->right;
        t->key = succ->key;
        t = succ;
    }
    free(t);
}
int main(void)
{
    element e;
    char* token;
    char line[600000];
    int n=0,a=0,l=0;
    TreeNode* root = NULL;
    
    FILE* fp = fopen("/Users/chaejunghun/Desktop/무제.txt","rt");
    FILE* dfp = fopen("/Users/chaejunghun/Desktop/search_words.txt","r");//삭제할 데이터 파일.
    while(!feof(fp)){    //n = 메모리 줄 수 세기
            fgets(line, 256, fp);
            n++;
        }
        rewind(fp);
   
    if( fp != NULL )
        {
            char strTemp[255];
            char *pStr;
            //element *e = malloc(sizeof(element)*n);
            while(!feof( fp))
            {
                pStr = fgets( strTemp, sizeof(strTemp), fp );
                
                //printf( "%s", strTemp );
                token = strtok(pStr, "()");
                 
                        strcpy(e.word, token);
                        insert_node(&root, e);
                a=1;
                    //printf("%d",a);
                while((token = strtok(NULL, "()")) != NULL)
                {
                    if(a==1)
                    {
                        
                    }
                    strcpy(e.poom, token);
                    strcpy(e.meaning, token);
                    //printf("%d",a);
                    a++;
                }
            }
            l++;
            fclose( fp );
        }
        else
        {
            //에러 처리
        }
    display(root);
    /*if(dfp != NULL)
    {
        char strTemp[255];
        char *pStr;
        
        while (!feof(dfp)) {
            pStr = fgets(strTemp, sizeof(strTemp), dfp);
            
            token = strtok(pStr, "\n");
            while (token != NULL) {
                printf("%s",token);
                printf("\n");
                token = strtok(NULL, "()");
            }
        }
        fclose(dfp);
    }
    else
    {
        //
    }*/
    return 0;
}
