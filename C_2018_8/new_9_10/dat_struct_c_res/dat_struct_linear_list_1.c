#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    printf("\n ======== Fo_linear_list ======== \n");
    // struct famale
    struct list_A_1{
        unsigned char name[20];
        unsigned int age;
        unsigned int ID;
        unsigned *next;
        unsigned *prev;
    };
    struct list_A_1 *curt = NULL;
    struct list_A_1 *first = NULL;
    struct list_A_1 *fward = NULL;
    struct list_A_1 *later = NULL;
    struct list_A_1 *end = NULL;

    for( ; ; ){
        int Age = 0;
        int s_ID = 0;
        printf("\n input name of current dat \n");
        fgets(curt->name, 18, stdin);
        // while(getchar != '\n');
        printf("\n input age of current dat \n");
        do {
            printf("\n age Not less than 6 and Not bigger than 40 \n");
            scanf("%d", &Age);
            }
            while (Age > 40 || Age < 6);
        curt->age = Age;
        // ============= this turn
        if(first == NULL){
            curt->prev = NULL;
            first = curt;
        } 
        curt->prev = fward;
        curt->next = later;
        // ============= next turn  
        curt = later;
        fward = curt;
        s_ID ++;
        curt->ID = s_ID;
    }
    printf("\n ================================================ \n");
    while(curt->next == NULL){
        printf("\n curtID \n",curt->ID);
        curt = curt->next;
    }
}