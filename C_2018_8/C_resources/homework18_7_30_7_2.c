#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STRLEN 254
#define NUMLEN 12
int main(void) {

	unsigned char temperature_str[STRLEN];  // ������
	unsigned char temperature_num[NUMLEN];  // ��Ч��

	size_t len_tem_str = 0;             // �������ַ���
	unsigned len_tem_num = 0;        // ��Ч�¶��ַ���
	unsigned n_tem_num = 0;         // ��Ч�¶ȸ���
	unsigned n_index = 0;           // ÿ����¶�����

	double tem_Num[120][6] = { 0.00 };              // ÿ���¶�ֵ

	double tem_pre_Num[120] = { 0.00 };           // ÿ���¶�ֵ

	unsigned index = 0;                // ���ַ����
	unsigned index_tem = 0;             // �¶��ַ����

	unsigned day = 0;
	char tem_Add;

	printf("\n ==== homework 7-2 2018-07-30 ==== \n\n ");
	printf("��������\n");
	while (strcmp(fgets(temperature_str, STRLEN, stdin), "q\n") != 0) {
		len_tem_str = strlen(temperature_str);
		if ((*(temperature_str) == '\n')) {
			goto ne_xt;
		}
		if ((*(temperature_str) == 'n')) {
			printf("\n ���¿�ʼ��ɾ�����������������   ȷ�� �� a   ȡ�� �� ������� \n\n ");
			if (tem_Add=getchar() == 'a') {
				printf(" \n �����¿�ʼ \n ");
				while ((tem_Add = getchar()) != EOF && tem_Add != '\n');
				for(size_t i = 0; i < day;i++){
					for (size_t j = 0; j < 5; j++) {
						tem_Num[i][j] = 0.00 ;
					}
				}
				day = 0;
				n_tem_num = 0;
				goto ne_xt;

			}
			else {
				printf(" \n ��ȡ�� \n ");
				while ((tem_Add = getchar()) != EOF && tem_Add != '\n');
				goto ne_xt;
			}



		}


		if ((*(temperature_str) == 'o') && (*(temperature_str + 1) == 'k') && (len_tem_str == 3)) {  //  ���� ok
			printf("\n\n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ ");
			for (size_t i = 1,d = 0, x = 1; i <= n_tem_num; i++) {
				if (((x-1) % 6) == 0) {
					x = 1;
					d++;
					printf(" \n\n --- �� %u �� --- \n ", d);
					for (size_t i = 0; i <= 5; i++) {
						tem_pre_Num[d-1] += tem_Num[d - 1][i];
					}

					tem_pre_Num[d - 1] /= 6;  //  ����ÿ���¼��6�ε�ֱ�Ӽ����ֵ

					if (n_tem_num % 6) {    //  �������һ����ֵ�����������������̬�仯
						tem_pre_Num[(n_tem_num / 6)] *= 6;  // �ȸ�ԭ����һ������6��
						tem_pre_Num[(n_tem_num/6)] /= (n_tem_num % 6);  //  �ó�ƽ��ֵ

					}
					printf(" \n ƽ������ %.2f �� \n\n ", tem_pre_Num[d-1]);
				}
				printf(" %10.2f ", tem_Num[d-1][x-1]);
				x++;
			}
			printf("\n\n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n ");
			for (size_t i = 0; i < day; i++) {
				*(tem_pre_Num + i) = 0.00;
			}
			goto ne_xt;
		}
		//==============================================
		//printf("\n ������ %u ���ַ� \n ", len_tem_str-1);
		for (index = 0; index < len_tem_str - 1; index++) {        // ����ok ����
			if (
			(
				(*(temperature_str + index) != '.') &&               //   ����С����
				(*(temperature_str + index) != '-') &&                //  ���Ǹ���
				(!(isdigit(*(temperature_str + index))) != 0)           //  ��������
			) ||
				((*(temperature_str + index) == '-') && index != 0)     //  ������λ����
			)
			{
				printf("\n ��֧�ֿո���ĸ���������� \n ");
				goto ne_xt;
			}
			else {
				if ((isdigit(*(temperature_str + index))) || (*(temperature_str + index) == '-'))    // ���ֻ򸺺�
				{
					*(temperature_num + index) = *(temperature_str + index);
					//printf("\n line 58 for �� %u λ���� = %c \n ", index, *(temperature_num + index));

				}
				else if (*(temperature_str + index) == '.')                        // С����
				{
					for (size_t pot = index + 1; pot < len_tem_str; pot++) {
						if (*(temperature_str + pot) == '.') {
							printf(" \n ����С���� ! \n ");
							goto ne_xt;
						}
					}
					*(temperature_num + index) = *(temperature_str + index);
					//printf("\n line 72 for �� %u λ�ַ� = %c \n ", index, *(temperature_num + index));
				}
				else {
					printf(" \n can not read ! \n ");
					goto ne_xt;
				}
			}
		}
		for (size_t i = 0; i < index; i++) {
			if (!(*(temperature_num + i))) {
				*(temperature_num + i) = '\0';
			}
		}

		if (atof(temperature_num) > 80.00 || atof(temperature_num) < -20) {
			printf(" \n �¶Ȳ���ʵ�� ! \n ");
			goto ne_xt;
		}

		if (n_tem_num % 6 == 0) {
			day++;
			n_index = 0;
		}
		n_tem_num++;
		n_index++;

		tem_Num[day-1][n_index-1] = atof(temperature_num);

		printf("\n ¼��� %u �� �� �� %u �μ�¼�¶ȳɹ� = %6.2f �ȡ���ǰ��¼�� %u ������ \n ", day, n_index, tem_Num[day-1][n_index-1], n_tem_num);

	ne_xt:printf("    ");
		//printf("\n �� %u �� �� �� %u �μ�¼�¶� = %6.4f \n ", day, n_index, tem_Num[day][n_tem_num]);
		printf("\n ==== ¼�� ==== ok = ���� ==== n = ���¿�ʼ ==== q = �˳� ==== \n\n ");
		for (size_t i = 0; i < len_tem_str; i++) {
			*(temperature_str + i) = NULL;
			*(temperature_num + i) = NULL;
		}

	}
	//system("pause");
	return 0;
}
