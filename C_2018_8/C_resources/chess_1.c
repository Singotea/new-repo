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

//  输入判断函数 q 退出 指令集如下
//  start 开局 show 查看得分 back 退一步 new 重新开始 （yes 同意 no 取消）备用
//  下棋对弈时 输入 nn nn 的5位字符进行
//  AI五子棋算法

//  lev --------------------------------------
//  4 死4
//  3 活3
//  2 活2
//  1 孤立
//  0 其他

//  AI 水平遍历
unsigned line_X(char *xy, unsigned i, unsigned j, char ch) {
	unsigned X = 0;
	unsigned S = 0;
	unsigned lev = 0;
	int tmp1 = 0;  //  起始位置
	int tmp2 = 0;  //  结束位置
	int nx = 0;  //  个数
	//int ny = 0;  
	//int nz = 0;  
	if (xy[i * MAX_L + j] == ' ') {
		//  计算水平方向
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
//  AI 垂直遍历
unsigned line_Y(char *xy, unsigned i, unsigned j, char ch) {
	unsigned X = 0;
	unsigned S = 0;
	unsigned lev = 0;
	int tmp1 = 0;  //  起始位置
	int tmp2 = 0;  //  结束位置
	int ny = 0;  //  个数
	if (xy[i * MAX_L + j] == ' ') {
		//  计算垂直方向
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
//  AI 对角线 1 遍历
unsigned line_L(char *xy, unsigned i, unsigned j, char ch) {
	unsigned X = 0;
	unsigned S = 0;
	unsigned lev = 0;
	int tmp1 = 0;  //  起始位置
	int tmp2 = 0;  //  结束位置
	int nz = 0;  //  个数
	if (xy[i * MAX_L + j] == ' ') {
		//  计算对角线 1 方向
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
//  AI 对角线 2 遍历 
unsigned line_R(char *xy, unsigned i, unsigned j, char ch) {
	unsigned X = 0;
	unsigned S = 0;
	unsigned lev = 0;
	int tmp1 = 0;  //  起始位置
	int tmp2 = 0;  //  结束位置
	int nz = 0;  //  个数
	if (xy[i * MAX_L + j] == ' ') {
		//  计算对角线 2 方向
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

//  AI 整体棋局遍历 -- 死4
unsigned *AI_read_4(char *xy,unsigned *ab, char ch) {
	unsigned Lev[4] = { 0 };
	unsigned time = 0;
	for (size_t i = 0; i < MAX_L; i++) {
		for (size_t j = 0; j < MAX_L; j++) {
			//  4方向全部遍历
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
//  AI 整体棋局遍历 -- 活3
unsigned *AI_read_3(char *xy, unsigned *ab, char ch) {
	unsigned Lev[4] = { 0 };
	unsigned time = 0;
	for (size_t i = 0; i < MAX_L; i++) {
		for (size_t j = 0; j < MAX_L; j++) {
			//  4方向全部遍历
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
//  AI 整体棋局遍历 -- 双 活2
unsigned *AI_read_2(char *xy, unsigned *ab, char ch) {
	unsigned Lev[4] = { 0 };
	unsigned time = 0;
	for (size_t i = 0; i < MAX_L; i++) {
		for (size_t j = 0; j < MAX_L; j++) {
			//  4方向全部遍历
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
//  AI 整体棋局遍历 -- 单 活2
unsigned *AI_read_1(char *xy, unsigned *ab, char ch) {
	unsigned Lev[4] = { 0 };
	unsigned time = 0;
	for (size_t i = 0; i < MAX_L; i++) {
		for (size_t j = 0; j < MAX_L; j++) {
			//  4方向全部遍历
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
//  AI 整体棋局遍历 -- 独 子
unsigned *AI_read_0(char *xy, unsigned *ab, char ch) {
	unsigned Lev[4] = { 0 };
	unsigned time = 0;
	for (size_t i = 0; i < MAX_L; i++) {
		for (size_t j = 0; j < MAX_L; j++) {
			//  4方向全部遍历
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
//  AI 整体棋局遍历 -- 独子 活1 （开局走法）
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
//  AI 攻击 和 防御 
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
		//  查错逻辑1 过量 继续循环
		if (*(A + 6) != '\0' && *(A + 6) != '\n') {
			while (getchar() != '\n');
			printf(" \n Error 1 Too many to take that words \n\n ");
		}
		//  下棋行为 返回下棋坐标
		else if (isdigit(*(A + 0)) && isdigit(*(A + 1)) && isdigit(*(A + 3)) && isdigit(*(A + 4)) && *(A + 2) == ' '&& *(A + 5) == '\n'){
			return A;
		}
		//  操作行为 返回操作命令
		else if (strcmp(A, "yes\n") == 0 || strcmp(A, "no\n") == 0 || strcmp(A, "start\n") == 0 || strcmp(A, "back\n") == 0 || strcmp(A, "new\n") == 0 || strcmp(A, "show\n") == 0) {
			return A;
		}
		//  查错逻辑 2 继续循环
		else{
			printf(" \n Error 2  Can not found the command line code \n\n ");
		}
		//printf(" \n INPUT = %s \n\n ", A);
		//初始化 输入记录数组
		for (size_t i = 0; i < 8; i++) *(A + i) = '\0';
	}
	return "quit";
}
//  参数个数可变的求平均数 函数
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
//  棋盘绘制函数 并生成时间点
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


//  主要
int main(void) {

	//  输入控制字符串
	char char_a[8] = { '\0' };
	char chara = '\0';
	//  下棋的矩阵数据
	/*char Ary[MAX_L][MAX_L] = { ' ' };*/
	char *xy;
	xy = calloc(MAX_L*MAX_L,sizeof(char));
	//  历史下棋矩阵数据
	/*char old_Ary[][MAX_L][MAX_L] = { ' ' };*/
	//  时间节点
	int index_main = -1;
	//  控制指令 字符数组
	char *INPUT = { '\0' };
	//  下棋步数字符
	char X_n[2] = { ' ' };
	char Y_n[2] = { ' ' };
	//  下棋步数 ATOI 数字
	int x_n = 0;
	int y_n = 0;
	//  玩家代号 0 = 玩家  1 = 电脑
	unsigned player = 0;
	//  得分
	unsigned point_you = 0;
	unsigned point_pc = 0;
	//  为AI函数分配内存空间
	unsigned *ab; 
	ab = calloc(2, sizeof(unsigned));
	printf(" \n homework 2018 - 08 -15 五子棋电脑对战小游戏 \n ");
	printf(" \n 可用命令 yes no show start back new \n ");
	printf(" \n 玩家 1 棋子为 ※ -------- 玩家 2 或电脑 棋子为 〇 \n ");
	printf(" \n ------------------------------------------------ \n ");
	printf(" \n 开始游戏 输入 start 回车 退出 输入 q 回车 \n\n "); 
	//  初始化 棋盘格局 全为空
	for (size_t i = 0; i < MAX_L*MAX_L; i++) {
		xy[i] = ' ';
	}
	while (true) {
		//  第一道 输入 进入游戏前控制
		INPUT = ope_INPUT(char_a);
		//  退出
		if (INPUT == "quit") {
			break;
		}
		//  开局
		else if (strcmp(INPUT, "start\n") == 0 && index_main == -1) {
			//  开局前可输入的命令
			outputChess(xy);
			index_main = 0;
			printf(" \n 开局 - - - - - - - - index = %u \n\n ",index_main);
			for (size_t i = 0; i < 8; i++) char_a[i] = '\0';
		}
		else if (strcmp(INPUT, "show\n") == 0 && index_main != 0) {
			//  开局后 命令 1 显示分数
			printf(" \n 已进行%u步 \n\n ", index_main);
			printf(" \n Player 得分 %u ! \n ",point_you);
			printf(" \n AIayer 得分 %u ! \n\n ",point_pc);
		}
		//else if (index_main != 0 && strcmp(INPUT, "back\n") == 0) {
		//	//  开局后 命令 2 悔棋1步
		//	index_main--;
		//	printf(" \n 退一步 - - - - - - - - index = %u \n\n ",index_main);
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
				printf(" \n 已进行%u步 \n\n ", index_main);
				xy[(x_n - 1) * MAX_L + y_n - 1] = 'X';
				//  AI  下棋算法
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
	//退出
	//system("pause");
}