#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
// ���峣��
#define LEN_STR 9999       // ƪ�������
#define NUM_WD 999         // ��������
#define LEN_WD 32          // �������ʳ������ֵ
#define LEN_LINE 256        // ���������

int main(void) {

	unsigned xl[NUM_WD] = { 0 };              // ��¼��������ĸ ���
	unsigned index = 0;                        // ���� ���
	unsigned indx = 0;                        // �ַ� �����
	unsigned char str_ary[LEN_LINE];                 // ÿ�п����볤��
	unsigned char str_Ary[LEN_STR];              // ƪ���ַ�

	unsigned char words[NUM_WD][LEN_WD];          // �ַ�������

	printf("\n homework 8-12 2018-8-10 \n\n ");
	printf("\n �������ⳤ���ַ����ı�������1023�� ������������ �ɻس� �ɿո� ÿ����� 120 �ַ� \n ");
	printf("\n ���� start �س� ��ʾ������ \n\n ���� q �س� �˳� \n\n ���� new �س� ��������������� \n\n ------------------------------------------------------------ \n\n ");
	while (strcmp(fgets(str_ary, 256, stdin), "q\n") != 0) {
		printf("\n ");
		if (strcmp(str_ary, "new\n") == 0) {
			for (size_t i = 0; i < LEN_STR; i++) str_Ary[i] = '\0';
			for (size_t i = 0; i < LEN_LINE; i++) str_ary[i] = '\0';
			for (size_t i = 0; i < NUM_WD; i++) xl[i] = 0;
			index = 0;
			indx = 0;
			printf(" \n �����ü�¼�� \n\n ���� start �س� ��ʾ������ \n\n ���� q �س� �˳� \n\n ------------------------------------------------------------ \n\n ");
		}
		else if (strcmp(str_ary, "start\n") == 0) {
			*(str_Ary + indx) = '\n';
			index = 0;
			if (isalnum(*(str_Ary + 0)) != 0) {
				// ����λΪ��ĸ �ض���ɵ���
				xl[index] = 0;
				//printf(" \n %u word start with %u \n\n ", index + 1, xl[index] + 1);
				index++;
			}
			for (size_t i = 0; i < indx; i++) {
				if (isalnum(*(str_Ary + i)) == 0 && isalnum(*(str_Ary + i + 1)) != 0)
				{
					//  �� index+1 �����ʿ�ͷ   ��1����ͷΪ 0 
					xl[index] = i + 1;
					//printf(" \n %u word start with %u \n ", index + 1, xl[index] + 1);
					index++;
				}
			}
			if (index == 0) {
				printf(" \n һ������Ҳ�Ҳ�������������Ч���ֻ���� \n\n ");
			}
			else {
				printf(" \n ����ĸ˳������ ��ͳ�Ƶ��ʳ��ִ��� \n ");
				printf(" \n All %u words in this passage \n\n ------------------------------------------------------------ \n ", index);

				for (size_t i = 0, ndx = 0; i < indx; i++) {
					unsigned j = 0;
					if (isalnum(*(str_Ary + i))) {
						while (isalnum(*(str_Ary + i))) {
							words[ndx][j] = *(str_Ary + i);
							i++;
							j++;
						}
						words[ndx][j++] = '\0';
						ndx++;
					}
				}
				// ������ĸ ���� ����ĸ��ͬ ����Ѱ�ҵڶ���������
				unsigned char tmp[1][LEN_WD] = { '\0' };
				for (size_t i = 1; i < index; i++) {
					for (size_t m = 0; m < index - 1; m++) {
						if (strcmp(words[i], words[m]) < 0) {
							for (size_t s = 0; s < LEN_WD; s++) {
								tmp[0][s] = words[i][s];
								words[i][s] = words[m][s];
								words[m][s] = tmp[0][s];
							}
						}
					}
				}

				// ���ظ����� ��ͳ�ƴ���
				unsigned num_index[NUM_WD] = { 0 };
				num_index[0] = 1;
				for (size_t i = 0; i < index - 1;) { // �ظ����� 
					if (strcmp(words[i], words[i + 1]) == 0) {
						// �Ƚ����ڵ��������� ��ͬʱִ�в���
						num_index[i]++;
						for (size_t j = i; j < index - 2; j++) { // ��λ���ظ����ʸ��ǣ���ǰ����һλ
							for (size_t s = 0; s < LEN_WD; s++) {
								words[j + 1][s] = words[j + 2][s];
							}
						}
						index--; // ��������һλ
					}
					else {
						i++;
						num_index[i] = 1;
					}


				}


				for (size_t i = 0; i < index; i++) {
					printf(" \n ");
					unsigned j = 0;
					while (words[i][j] != '\0') {
						printf("%c", words[i][j]);
						j++;
					}
					printf("   %u �� \n ", num_index[i]);
				}
				printf(" \n ------------------------------------------------------------ \n\n ����� ���������Ķ�   ���� \n\n ���� start �س� ��ʾ������ \n\n ���� q �س� �˳� \n\n ���� new �س� ������� �������� \n\n ");
			}
		}
		else {
			for (size_t t = 0; t < (strlen(str_ary)) - 1; t++) {
				*(str_Ary +indx) = *(str_ary + t);
				indx++;
			}
			*(str_Ary + indx) = ' ';
			indx++;
		}
	}
}
