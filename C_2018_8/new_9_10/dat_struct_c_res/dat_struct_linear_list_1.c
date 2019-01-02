#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    printf("\n ======== Fo_linear_list ======== \n");
    unsigned int Num_ctrl_0 = 0;
    // struct famale
    struct list_A_1{
        unsigned char Name[20];
        unsigned int Age;
        unsigned int ID;

        unsigned *next;
        unsigned *prev;
    };
    struct list_A_1 *curt = NULL;
    struct list_A_1 *first = NULL;
    struct list_A_1 *fward = NULL;
    struct list_A_1 *later = NULL;
    struct list_A_1 *end = NULL;

    unsigned int age = 0;
    unsigned int s_ID = 0;
    unsigned char name[20] = {'\0'};
    while(Num_ctrl_0 == 0){
        age = 0;
        s_ID = 0;
        for(size_t i = 0;i < 20; i++){
            name[i] = '\0';
        }
        printf("\n input Name of current dat \n");
        fgets(name, 18, stdin);
        // while(getchar != '\n');
        for(size_t i = 0;i < 20; i++){
            curt->Name[i] = name[i];
        }
        printf("\n input Age of current dat \n");
        do {
            printf("\n age Not less than 6 and Not bigger than 40 \n");
            scanf("%d", &age);
        }
        while (age > 40 || age < 6);
        curt->Age = age;
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
        // printf("\n curt_ID = %d \n",curt->ID);
        curt = curt->next;
    }
}