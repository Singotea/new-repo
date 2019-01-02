#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    int a = 0;
    int s = 1;
    char Str[10][10] = {'\0'};
    while (s != 0){
        // 循环体 不符合条件即跳出 break;
        printf("\n ============= line %d ============= \n",a);
        printf(" name 1 please enter with Enter\n");
        fgets(Str[a],9,stdin);
        a++;
        if(a==10){
            s = 0;
        }
    }
    for(size_t tmp1 = 0; tmp1 <= 10; tmp1++){
        printf(Str[tmp1]);
    }
}