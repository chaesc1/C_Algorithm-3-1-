#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_SIZE 300000
#define MAX_POOM_SIZE 200000
#define MAX_MEANING_SIZE 200000

typedef struct Word
{
    char word[MAX_WORD_SIZE];
    char poom[MAX_POOM_SIZE];
    char meaning[MAX_MEANING_SIZE];
}Word;

Word words[200000];

int main(void)
{
    Word w;
    char* token;
    char* delete_token;
    char line[300000];
    int n=0,a=0,l=0;
    clock_t start=0,end=0;
    float result = 0;
    
    FILE* fp = fopen("/Users/chaejunghun/Desktop/무제.txt","r");
    FILE* dfp = fopen("/Users/chaejunghun/Desktop/search_words.txt","r");//삭제할 데이터 파일.
    while(!feof(fp)){    //n = 메모리 줄 수 세기
            fgets(line, 256, fp);
            n++;
        }
        rewind(fp);
    int i=0;
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
                if(a==0)
                {
                    strcpy(w.word,token);    
                }
                a=0;
                while((token = strtok(NULL, "()") )!= NULL)
                {
                    
                    if(a==1)
                    {
                        strcpy(w.poom,token);
                    }
                    if(a==2)
                    {
                        strcpy(w.meaning,token);
                        words[i++] = w;
                    }
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
    //display(root);
    int b=0;
    start = clock();
    if(dfp != NULL)
    {
        char strTemp_d[255];
        char *pStr_d;
        
        while (!feof(dfp)) {
            pStr_d = fgets(strTemp_d, sizeof(strTemp_d), dfp);
            
            delete_token = strtok(pStr_d, "\n");
            //printf("%s\n",delete_token);
            while (delete_token != NULL) {
                
                delete_token = strtok(NULL, "\n");
            }
        }
        fclose(dfp);
    }
    else
    {
        //
    }
    end = clock();
    result = (float)(end-start);
    printf("삭제 걸린 시간 = %.3lf",result/CLOCKS_PER_SEC);
   //display(root);
    return 0;
}
