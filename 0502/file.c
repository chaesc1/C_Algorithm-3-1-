#include <stdio.h>

int main(void)
{
    FILE* p_file = fopen("/Users/chaejunghun/Desktop/shuffled_dict.txt", "r");
if (NULL != p_file) {
	//파일 열기에 성공한 경우
    printf("suc");
    fclose(p_file);
}
else {
	//파일 열기에 실패한 경우
    printf("fail");
}

    return 0;
}