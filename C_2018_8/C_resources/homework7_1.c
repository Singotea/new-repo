#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define STR_LEN 512
#define NUM_LEN 30

int main(void) {
	unsigned char str_ary[STR_LEN];    // �ַ������ܴ洢
	unsigned char num_ary[NUM_LEN];    // �ַ����뵱ǰ�����ַ��洢
	size_t str_len = 0;             // �ַ������볤��
	size_t str_len_t = 0;            //����������
	unsigned int num_len = 0;       // ��Ч�������ֳ���
	unsigned int index = 0;       //  ���ַ����
	double number = 0;         //  ��ǰ����
	double Sum = 0;           //  ��ǰ��
	unsigned int n_num = 0;     //  ���ָ���
	double result = 0;         //  ���

	printf("\n  C����ģ����㣬����ƽ��ֵ,����Ҫ��ǰ֪��Ҫ��������ĸ�������̬��������������������ռ�����ƽ��ֵ \n");
	printf("\n  ��ע�ⲻҪ��������������ַ�,�����������ֺ��ٰ�һ�λس����ɼ���ƽ��ֵ \n");
	printf("\n  ����� %u ������ ���߰� q �˳� \n\n ",n_num + 1);
	while (strcmp(fgets(str_ary, STR_LEN, stdin), "q\n") != 0) {
		str_len = strlen(str_ary);         //��¼��ʼ�����ַ�λ�� �����н�����'\0'
		//printf("\n ������ %u ���ַ� \n",str_len-1);
		for (str_len_t = 0,index = 0; index < str_len; index++) {          //ȥ�ո�
			if (*(str_ary + index) != ' ') {
				*(str_ary + str_len_t++) = *(str_ary + index);
			}
		}
		*(str_ary + str_len_t) = '\0';  // ȷ������ȷ������Ч�ַ�����ĩβ���н�����'\0' ��֪ ������ + 2 = �ַ�λ���� 
		str_len_t = strlen(str_ary);    // ��¼��Ч�����ַ�λ��,�������н�����'\0' ��֪ str_len_t + �ո��� = stl_len
		printf("\n ��ȥ %u ���ո�,���鳤���� %u ��Ϊ %u \n", str_len-str_len_t, str_len, str_len_t);

		//��λ�ж�
		for (index = 0; index <= str_len_t-2; index++) {  //Ϊȷ��ֻ�����Ч����λ (str_len - 2)
			//=========================================================================================================================
			if (
				(
				(*(str_ary + index) != '.') && (*(str_ary + index) != '-') && (!(isdigit(*(str_ary + index))) != 0)    //  ���г���С���㸺��������������ַ���
				)
				|| 
				((*(str_ary + index) == '-') && index != 0)  // ���Ų�����λ
				) {
				//��� ��ǰ���� �Ƿ�����Ч�ַ�
				printf("\n ��������룬������ \n");
				printf("\n �� %u ���ַ� %c �޷����� \n", index, *(str_ary+index));
				number = 0.00;
				goto one;
			}
			else {           //��ǰ����Ϸ�ʱ
				if ((isdigit(*(str_ary + index))) || (*(str_ary + index) == '-')) {
					*(num_ary + index) = *(str_ary + index);
					printf("\n line 48 for �� %u λ���� = %c \n", index, *(num_ary + index));
					
				}
				if (*(str_ary + index) == '.') {
					for (size_t pot = (index + 1); pot <= str_len_t - 2; pot++) {
						if (*(str_ary + pot) == '.') {
							printf("\n ����������С���㣬�������� \n");
							number = 0.00;
							//ֱ���˳�ѭ��
							goto one;
						}
						else {
							*(num_ary + index) = *(str_ary + index);
							printf("\n line 62 for �� %u λ �� С���� \n", index);
						}
					}
				}
				number = atof(num_ary);
				printf("\n index = %u  and num_ary length = %u \n",index,str_len_t-2);
			}
		}
		n_num++;
	one: printf("\n ---------------------------------------- \n");
		/*printf("\n number = %f \n ", number);*/
		if (number > 9999999999.0 || number < -9999999999.0) {
			printf("\n ����λ���10λ��С��λ���6λ������������ ! \n\n");
		}
		
		else {
			Sum += number;
			result = Sum / n_num;
			printf("\n ���� %u = %10.6f     ��ǰƽ���� = %10.6f \n\n ", n_num, number,result);
		}
		for (size_t i = 0; i < str_len; i++) {
			*(str_ary + i) = NULL ;
			*(num_ary + i) = NULL ;
		}
		printf("\n ������� %u ������ ���߰� q �˳� \n\n ", n_num + 1);
	}
	system("pause");
	return 0;


}
