#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define BUF_LEN 254
int main(void) {
	unsigned char input[BUF_LEN];  //��ʼ�����ַ��� buf
	char number_str[30];  //����� �������Ч�� buf
	unsigned char op = '0';        //���ʽ buf
	unsigned int index = 0;  //��ǰ����� ���ֻ��ַ������
	unsigned int to = 0;  //��ǰ�������ֵĸ��ƣ��ų��ո�
	size_t input_len = 0;  //�������ַ�����
	unsigned int number_len = 0;  //�����������
	double result = 0.00;  //���
	double number = 0.00;   //����ʹ��ֵ

	printf("\n Enter what you want comput \n\n");

	while (strcmp(fgets(input, BUF_LEN, stdin), "q\n") != 0) {
		//�������
		input_len = strlen(input);
		input[--input_len] = '\0';  //��������س�ȡ������
		for (to = 0, index = 0; index <= input_len; index++) {
			if (*(input + index) != ' ') {  //����ո�
				*(input + to++) = *(input + index);
			}
		}  
		//��ո�
		input_len = strlen(input);  //�����޿ո���ʽ
		index = 0;  //�������


		if (input[index] == '=') {  //������=����
			index++;
		}
		//===========================================================================
		if(input_len>0) {
			
			number_len = 0;
			if (isdigit(*(input + index))) {        //��������־͸���===========
				for (; isdigit(*(input + index)); index++) {  
					*(number_str + number_len++) = *(input + index);  //��һ��λ
				}
				if (*(input + index) == '.') {  //�����С���� ����������
					*(number_str + number_len++) = *(input + index++);// ���� ��һ��λ
					for (; isdigit(*(input + index)); index++) {     // ���� ���� 
						*(number_str + number_len++) = *(input + index);// ��һ��λ
					}
				}
				*(number_str + number_len) = '\0';  //  ����Ч���ַ�����ĩβ��־
				result = atof(number_str);  //�ظ�ȡ����Ч������
				//printf("\n  line55  %u  Number = %f\n", index, number);
			}
			

			for (; index < input_len; index++) {  //ֻҪ����δȫ����ȡ�����ظ���ѯ
				//printf("\n index = %u\n", index);
				if ((isdigit(*(input + index-1)) == 0) && (index != 0)) {
					op = input[index-1];
					//printf("\n op %u = %c \n", index-1, op);//������� ����һλ
				}
				number_len = 0;
				for (; isdigit(*(input + index)); index++) {  //��������־͸���
					*(number_str + number_len++) = *(input + index);  //��һ��λ
				}
				if (*(input + index) == '.') {  //�����С���� ����������
					*(number_str + number_len++) = *(input + index++);// ���� ��һ��λ
					for (; isdigit(*(input + index)); index++) {     // ���� ���� 
						*(number_str + number_len++) = *(input + index);// ��һ��λ
					}
				}
				*(number_str + number_len) = '\0';  //  ����Ч���ַ�����ĩβ��־
				number = atof(number_str);          //�ظ�ȡ����Ч������
				//printf("\n   line75  %u  Number = %f\n", index,number);
				switch (op) {
				case '+': result += number; break;
				case '-': result -= number; break;
				case '*': result *= number; break;
				case '/':
					if (number != 0.0000) {
						result /= number;
					}
					else {
						printf("\n ---- \n");
					}
					break;
				case '%':
					if (number != 0.0000) {
						printf("\n ---- \n");
						result = (long)result % (long)number;
					}
					else {
						printf("\n ---- \n"); 
					}
					break;
				case '^': result = pow(result, number); break;
				default: printf("\n ---- \n");
					//printf("\n op last index%u = %c \n", op,index);
					break;
				}
			}
		}
		
		printf("\n = %.4f \n\n",result);
	}
	return 0;
}