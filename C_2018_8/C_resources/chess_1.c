#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <Windows.h>
#define MAX_L 12 

//  �����жϺ��� q �˳� ָ�����
//  start ���� show �鿴�÷� back ��һ�� new ���¿�ʼ ��yes ͬ�� no ȡ��������
//  �������ʱ ���� nn nn ��5λ�ַ�����
//  AI�������㷨

//  lev --------------------------------------
//  4 ��4
//  3 ��3
//  2 ��2
//  1 ����
//  0 ����

//  AI ˮƽ����
unsigned line_X(char *xy, unsigned i, unsigned j, char ch) {
	unsigned X = 0;
	unsigned S = 0;
	unsigned lev = 0;
	int tmp1 = 0;  //  ��ʼλ��
	int tmp2 = 0;  //  ����λ��
	int nx = 0;  //  ����
	//int ny = 0;  
	//int nz = 0;  
	if (xy[i * MAX_L + j] == ' ') {
		//  ����ˮƽ����
		tmp1 = j - 4;
		tmp2 = j + 4;
		if (j - 4 < 0) {
			tmp1 = 0;
		}
		if (j + 4 > MAX_L - 1) tmp2 = MAX_L - 1;
		nx = tmp2 - tmp1 - 3;
		for (int k = 0; k < nx; k++) {
			S = X = 0;
			for (int l = 0; l < 5; l++) {
				if (xy[i * MAX_L + (tmp1 + l + k)] == ' ') S++;
				if (xy[i * MAX_L + (tmp1 + l + k)] == ch) X++;
			}
			if (S == 1 && X == 4) {
				lev = 4;
				return lev;
			}
			else if (S == 2 && X == 3) {
				lev = 3;
				return lev;
			}
			else if (S == 3 && X == 2) {
				lev = 2;
				return lev;
			}
			else lev = 0;
		}
	}
	return lev;
}
//  AI ��ֱ����
unsigned line_Y(char *xy, unsigned i, unsigned j, char ch) {
	unsigned X = 0;
	unsigned S = 0;
	unsigned lev = 0;
	int tmp1 = 0;  //  ��ʼλ��
	int tmp2 = 0;  //  ����λ��
	int ny = 0;  //  ����
	if (xy[i * MAX_L + j] == ' ') {
		//  ���㴹ֱ����
		tmp1 = i - 4;
		tmp2 = i + 4;
		if (i - 4 < 0) tmp1 = 0;
		if (i + 4 > MAX_L - 1) tmp2 = MAX_L - 1;
		ny = tmp2 - tmp1 - 3;
		for (int k = 0; k < ny; k++) {
			S = X = 0;
			for (int l = 0; l < 5; l++) {
				if (xy[(tmp1 + l + k) * MAX_L + j] == ' ') S++;
				if (xy[(tmp1 + l + k) * MAX_L + j] == ch) X++;
			}
			if (S == 1 && X == 4) {
				lev = 4;
				return lev;
			}
			else if (S == 2 && X == 3) {
				lev = 3;
				return lev;
			}
			else if (S == 3 && X == 2) {
				lev = 2;
				return lev;
			}
			else lev = 0;
		}
	}
	return lev;
}
//  AI �Խ��� 1 ����
unsigned line_L(char *xy, unsigned i, unsigned j, char ch) {
	unsigned X = 0;
	unsigned S = 0;
	unsigned lev = 0;
	int tmp1 = 0;  //  ��ʼλ��
	int tmp2 = 0;  //  ����λ��
	int nz = 0;  //  ����
	if (xy[i * MAX_L + j] == ' ') {
		//  ����Խ��� 1 ����
		tmp1 = j - 4;
		tmp2 = j + 4;
		if (j - 4 < 0) {
			if (i < j) tmp1 = j - i;
			else tmp1 = 0;
		}
		if (j + 4 > MAX_L - 1) {
			if (j < i) tmp2 = MAX_L - 1 - (i - j);
			else tmp2 = MAX_L - 1;
		}
		nz = tmp2 - tmp1 - 3;
		for (int k = 0; k < nz; k++) {
			S = X = 0;
			for (int l = 0; l < 5; l++) {
				if (xy[(i + tmp1 - j + l + k) * MAX_L + (tmp1 + l + k)] == ' ') S++;
				if (xy[(i + tmp1 - j + l + k) * MAX_L + (tmp1 + l + k)] == ch) X++;
			}
			if (S == 1 && X == 4) {
				lev = 4;
				return lev;
			}
			else if (S == 2 && X == 3) {
				lev = 3;
				return lev;
			}
			else if (S == 3 && X == 2) {
				lev = 2;
				return lev;
			}
			else lev = 0;
		}
	}
	return lev;
}
//  AI �Խ��� 2 ���� 
unsigned line_R(char *xy, unsigned i, unsigned j, char ch) {
	unsigned X = 0;
	unsigned S = 0;
	unsigned lev = 0;
	int tmp1 = 0;  //  ��ʼλ��
	int tmp2 = 0;  //  ����λ��
	int nz = 0;  //  ����
	if (xy[i * MAX_L + j] == ' ') {
		//  ����Խ��� 2 ����
		tmp1 = j - 4;
		tmp2 = j + 4;
		if (j - 4 < 0) {
			if (i + j > MAX_L) tmp1 = i + j - (MAX_L - 1);
			else tmp1 = 0;
		}
		if (j + 4 > MAX_L - 1) {
			if (i + j < MAX_L) tmp2 = (MAX_L - 1) - (i + j);
			else tmp2 = MAX_L - 1;
		}
		nz = tmp2 - tmp1 - 3;
		for (int k = 0; k < nz; k++) {
			S = X = 0;
			for (int l = 0; l < 5; l++) {
				if (xy[(i + j - tmp1 - l - k) * MAX_L + (tmp1 + l + k)] == ' ') S++;
				if (xy[(i + j - tmp1 - l - k) * MAX_L + (tmp1 + l + k)] == ch) X++;
			}
			if (S == 1 && X == 4) {
				lev = 4;
				return lev;
			}
			else if (S == 2 && X == 3) {
				lev = 3;
				return lev;
			}
			else if (S == 3 && X == 2) {
				lev = 2;
				return lev;
			}
			else lev = 0;
		}
	}
	return lev;
}

//  AI ������ֱ��� -- ��4
unsigned *AI_read_4(char *xy,unsigned *ab, char ch) {
	unsigned Lev[4] = { 0 };
	unsigned time = 0;
	for (size_t i = 0; i < MAX_L; i++) {
		for (size_t j = 0; j < MAX_L; j++) {
			//  4����ȫ������
			Lev[0] = line_X(xy, i, j, ch);
			Lev[1] = line_Y(xy, i, j, ch);
			Lev[2] = line_L(xy, i, j, ch);
			Lev[3] = line_R(xy, i, j, ch);
			for (size_t n = 0; n < 4; n++) {
				if (Lev[n] == 4) time ++;
			}
			if (time > 0) {
				ab[0] = i;
				ab[1] = j;
				printf(" \n 4-1 chess plan has found  time = %u \n\n ",time);
				return ab;
			}
			else {
				ab[0] = MAX_L+2;
				ab[1] = MAX_L+2;
			}
		}
	}
	printf(" \n nothing AI can do \n\n ");
	return ab;
}
//  AI ������ֱ��� -- ��3
unsigned *AI_read_3(char *xy, unsigned *ab, char ch) {
	unsigned Lev[4] = { 0 };
	unsigned time = 0;
	for (size_t i = 0; i < MAX_L; i++) {
		for (size_t j = 0; j < MAX_L; j++) {
			//  4����ȫ������
			Lev[0] = line_X(xy, i, j, ch);
			Lev[1] = line_Y(xy, i, j, ch);
			Lev[2] = line_L(xy, i, j, ch);
			Lev[3] = line_R(xy, i, j, ch);
			for (size_t n = 0; n < 4; n++) {
				if (Lev[n] == 3) {
					time++;
					printf(" \n n = %u \n\n ", n);
				}
			}
			if (time > 0) {
				ab[0] = i;
				ab[1] = j;
				printf(" \n 3-2 chess plan has found  time = %u \n\n ", time);
				return ab;
			}
			else {
				ab[0] = MAX_L + 2;
				ab[1] = MAX_L + 2;
			}
		}
	}
	printf(" \n nothing AI can do \n\n ");
	return ab;
}
//  AI ������ֱ��� -- ˫ ��2
unsigned *AI_read_2(char *xy, unsigned *ab, char ch) {
	unsigned Lev[4] = { 0 };
	unsigned time = 0;
	for (size_t i = 0; i < MAX_L; i++) {
		for (size_t j = 0; j < MAX_L; j++) {
			//  4����ȫ������
			Lev[0] = line_X(xy, i, j, ch);
			Lev[1] = line_Y(xy, i, j, ch);
			Lev[2] = line_L(xy, i, j, ch);
			Lev[3] = line_R(xy, i, j, ch);
			for (size_t n = 0; n < 4; n++) {
				if (Lev[n] == 2) time++;
			}
			if (time > 1) {
				ab[0] = i;
				ab[1] = j;
				printf(" \n 2-2 chess plan has found  time = %u \n\n ", time);
				return ab;
			}
			else {
				ab[0] = MAX_L + 2;
				ab[1] = MAX_L + 2;
			}
		}
	}
	printf(" \n nothing AI can do \n\n ");
	return ab;
}
//  AI ������ֱ��� -- �� ��2
unsigned *AI_read_1(char *xy, unsigned *ab, char ch) {
	unsigned Lev[4] = { 0 };
	unsigned time = 0;
	for (size_t i = 0; i < MAX_L; i++) {
		for (size_t j = 0; j < MAX_L; j++) {
			//  4����ȫ������
			Lev[0] = line_X(xy, i, j, ch);
			Lev[1] = line_Y(xy, i, j, ch);
			Lev[2] = line_L(xy, i, j, ch);
			Lev[3] = line_R(xy, i, j, ch);
			for (size_t n = 0; n < 4; n++) {
				if (Lev[n] == 2) time++;
			}
			if (time > 0) {
				ab[0] = i;
				ab[1] = j;
				printf(" \n 2-1 chess plan has found  time = %u \n\n ", time);
				return ab;
			}
			else {
				ab[0] = MAX_L + 2;
				ab[1] = MAX_L + 2;
			}
		}
	}
	printf(" \n nothing AI can do \n\n ");
	return ab;
}
//  AI ������ֱ��� -- �� ��
unsigned *AI_read_0(char *xy, unsigned *ab, char ch) {
	unsigned Lev[4] = { 0 };
	unsigned time = 0;
	for (size_t i = 0; i < MAX_L; i++) {
		for (size_t j = 0; j < MAX_L; j++) {
			//  4����ȫ������
			Lev[0] = line_X(xy, i, j, ch);
			Lev[1] = line_Y(xy, i, j, ch);
			Lev[2] = line_L(xy, i, j, ch);
			Lev[3] = line_R(xy, i, j, ch);
			for (size_t n = 0; n < 4; n++) {
				if (Lev[n] == 2) time++;
			}
			if (time == 0) {
				ab[0] = i;
				ab[1] = j;
				printf(" \n 1-1 chess plan has found  time = %u \n\n ", time);
				return ab;
			}
			else {
				ab[0] = MAX_L + 2;
				ab[1] = MAX_L + 2;
			}
		}
	}
	printf(" \n nothing AI can do \n\n ");
	return ab;
}
//  AI ������ֱ��� -- ���� ��1 �������߷���
unsigned *AI_start(char *xy, unsigned *ab) {
	for (size_t a = 0; a < MAX_L; a++) {
		for (size_t b = 0; b < MAX_L; b++) {
			if (xy[a * MAX_L + b] == 'X') {
				if (a >= MAX_L / 2) ab[0] = a - 1;
				else ab[0] = a + 1;
				if (b >= MAX_L / 2) ab[1] = b - 1;
				else ab[1] = b + 1;
				printf(" \n AI first step has done \n\n ");
				return ab;
			}
		}
	}
	ab[0] = MAX_L + 2;
	ab[1] = MAX_L + 2;
	printf(" \n nothing AI can do \n\n ");
	return ab;
}
//  AI ���� �� ���� 
unsigned *AI_end(char *xy, unsigned *ab) {
	ab = AI_read_4(xy, ab, 'Q');
	if (ab[0] > MAX_L) ab = AI_read_4(xy, ab, 'X');
	if (ab[0] > MAX_L) ab = AI_read_3(xy, ab, 'Q');
	if (ab[0] > MAX_L) ab = AI_read_3(xy, ab, 'X');
	if (ab[0] > MAX_L) ab = AI_read_2(xy, ab, 'Q');
	if (ab[0] > MAX_L) ab = AI_read_2(xy, ab, 'X');
	if (ab[0] > MAX_L) ab = AI_read_1(xy, ab, 'Q');
	if (ab[0] > MAX_L) ab = AI_read_1(xy, ab, 'X');
	if (ab[0] > MAX_L) ab = AI_read_0(xy, ab, 'Q');
	if (ab[0] > MAX_L) ab = AI_read_0(xy, ab, 'X');
	if (ab[0] > MAX_L) {
		printf(" \n nothing AI can do this is a new problem \n\n ");
	}
	return ab;
}

char *ope_INPUT(char *A) { 
	while (strcmp(fgets(A, 8, stdin), "q\n") != 0) {
		//  ����߼�1 ���� ����ѭ��
		if (*(A + 6) != '\0' && *(A + 6) != '\n') {
			while (getchar() != '\n');
			printf(" \n Error 1 Too many to take that words \n\n ");
		}
		//  ������Ϊ ������������
		else if (isdigit(*(A + 0)) && isdigit(*(A + 1)) && isdigit(*(A + 3)) && isdigit(*(A + 4)) && *(A + 2) == ' '&& *(A + 5) == '\n'){
			return A;
		}
		//  ������Ϊ ���ز�������
		else if (strcmp(A, "yes\n") == 0 || strcmp(A, "no\n") == 0 || strcmp(A, "start\n") == 0 || strcmp(A, "back\n") == 0 || strcmp(A, "new\n") == 0 || strcmp(A, "show\n") == 0) {
			return A;
		}
		//  ����߼� 2 ����ѭ��
		else{
			printf(" \n Error 2  Can not found the command line code \n\n ");
		}
		//printf(" \n INPUT = %s \n\n ", A);
		//��ʼ�� �����¼����
		for (size_t i = 0; i < 8; i++) *(A + i) = '\0';
	}
	return "quit";
}
//  ���������ɱ����ƽ���� ����
double per_Num(double x,double y, ...) {

	va_list n;
	double sum = x + y;
	double z = 0.0;
	int count = 2;
	
	va_start(n, y); 
		
		
	while ((z = va_arg(n, double)) != 0.0) {
		sum += z;
		count++;
	}
	va_end(n);
	return sum / count;

}
//  ���̻��ƺ��� ������ʱ���
void outputChess(char *A) {
	printf(" \n    +---+---+");
	for (size_t i = 0; i < MAX_L; i++) printf("---+---+");
	printf(" \n ");
	printf("   |  Y-X  ");
	for (size_t i = 0; i < MAX_L;i++) {
		if (i + 1 < 10) printf("|   %u   ", i + 1);
		else printf("|  0%u  ", i + 1);
	}
	printf("| ");
	for (size_t i = 0; i < MAX_L; i++) {
		printf(" \n    +---+---+");
		for (size_t i = 0; i < MAX_L; i++) printf("---+---+");
		printf(" \n    |       |");
		for (size_t i = 0; i < MAX_L; i++) printf("       |");
		printf(" \n ");
		if(i+1 < 10) printf("   |   %u   ", i + 1);
		else printf("   |  0%u  ", i + 1);
		for (size_t j = 0; j < MAX_L; j++) printf("|   %c   ", *(A + MAX_L * i + j));
		printf("| \n    |       |");
		for (size_t i = 0; i < MAX_L; i++) printf("       |");
	}
	printf(" \n    +---+---+");
	for (size_t i = 0; i < MAX_L; i++) printf("---+---+");
	printf(" \n\n ");
	return;
}


//  ��Ҫ
int main(void) {

	//  ��������ַ���
	char char_a[8] = { '\0' };
	char chara = '\0';
	//  ����ľ�������
	/*char Ary[MAX_L][MAX_L] = { ' ' };*/
	char *xy;
	xy = calloc(MAX_L*MAX_L,sizeof(char));
	//  ��ʷ�����������
	/*char old_Ary[][MAX_L][MAX_L] = { ' ' };*/
	//  ʱ��ڵ�
	int index_main = -1;
	//  ����ָ�� �ַ�����
	char *INPUT = { '\0' };
	//  ���岽���ַ�
	char X_n[2] = { ' ' };
	char Y_n[2] = { ' ' };
	//  ���岽�� ATOI ����
	int x_n = 0;
	int y_n = 0;
	//  ��Ҵ��� 0 = ���  1 = ����
	unsigned player = 0;
	//  �÷�
	unsigned point_you = 0;
	unsigned point_pc = 0;
	//  ΪAI���������ڴ�ռ�
	unsigned *ab; 
	ab = calloc(2, sizeof(unsigned));
	printf(" \n homework 2018 - 08 -15 ��������Զ�սС��Ϸ \n ");
	printf(" \n �������� yes no show start back new \n ");
	printf(" \n ��� 1 ����Ϊ �� -------- ��� 2 ����� ����Ϊ �� \n ");
	printf(" \n ------------------------------------------------ \n ");
	printf(" \n ��ʼ��Ϸ ���� start �س� �˳� ���� q �س� \n\n "); 
	//  ��ʼ�� ���̸�� ȫΪ��
	for (size_t i = 0; i < MAX_L*MAX_L; i++) {
		xy[i] = ' ';
	}
	while (true) {
		//  ��һ�� ���� ������Ϸǰ����
		INPUT = ope_INPUT(char_a);
		//  �˳�
		if (INPUT == "quit") {
			break;
		}
		//  ����
		else if (strcmp(INPUT, "start\n") == 0 && index_main == -1) {
			//  ����ǰ�����������
			outputChess(xy);
			index_main = 0;
			printf(" \n ���� - - - - - - - - index = %u \n\n ",index_main);
			for (size_t i = 0; i < 8; i++) char_a[i] = '\0';
		}
		else if (strcmp(INPUT, "show\n") == 0 && index_main != 0) {
			//  ���ֺ� ���� 1 ��ʾ����
			printf(" \n �ѽ���%u�� \n\n ", index_main);
			printf(" \n Player �÷� %u ! \n ",point_you);
			printf(" \n AIayer �÷� %u ! \n\n ",point_pc);
		}
		//else if (index_main != 0 && strcmp(INPUT, "back\n") == 0) {
		//	//  ���ֺ� ���� 2 ����1��
		//	index_main--;
		//	printf(" \n ��һ�� - - - - - - - - index = %u \n\n ",index_main);
		//}
		else if (index_main != -1 && (isdigit(*(INPUT + 0)) && isdigit(*(INPUT + 1)) && isdigit(*(INPUT + 3)) && isdigit(*(INPUT + 4)) && *(INPUT + 2) == ' '&& *(INPUT + 5) == '\n')) {
			*(X_n + 0) = *(INPUT + 0);
			*(X_n + 1) = *(INPUT + 1);
			*(Y_n + 0) = *(INPUT + 3);
			*(Y_n + 1) = *(INPUT + 4);
			printf(" \n INPUT = %s \n\n ",INPUT);
			x_n = atoi(X_n);
			y_n = atoi(Y_n);
			printf(" \n the command line for %u and %u \n\n ",x_n,y_n);
			if (x_n <= MAX_L && y_n <= MAX_L) {
				index_main ++;
				printf(" \n �ѽ���%u�� \n\n ", index_main);
				xy[(x_n - 1) * MAX_L + y_n - 1] = 'X';
				//  AI  �����㷨
				if (index_main == 1) ab = AI_start(xy, ab);
				else  ab = AI_end(xy, ab);
				
				printf(" \n the AI action for %u and %u \n\n ", ab[0], ab[1]);
				if (ab[0] >= MAX_L || ab[1] >= MAX_L) {
					printf(" \n AI do nothing \n\n ");
					outputChess(xy);
				}
				else{
					xy[(ab[0]) * MAX_L + ab[1]] = 'Q';
					outputChess(xy);
				}
			}
			else printf("\n Nothing happen the number is too big \n\n ");
		}
		else printf(" \n This command has not used \n\n ");
	}
	

	printf(" \n ");
	free(xy);
	free(ab);
	//�˳�
	//system("pause");
}