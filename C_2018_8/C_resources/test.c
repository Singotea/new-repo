#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define BUF_LEN 254
int main(void) {
	unsigned char input[BUF_LEN];  //初始输入字符串 buf
	char number_str[30];  //输入的 处理后有效数 buf
	unsigned char op = '0';        //表达式 buf
	unsigned int index = 0;  //当前输入的 数字或字符的序号
	unsigned int to = 0;  //当前输入数字的复制（排除空格）
	size_t input_len = 0;  //总输入字符串长
	unsigned int number_len = 0;  //其中数字序号
	double result = 0.00;  //结果
	double number = 0.00;   //数字使用值

	printf("\n Enter what you want comput \n\n");

	while (strcmp(fgets(input, BUF_LEN, stdin), "q\n") != 0) {
		//输入控制
		input_len = strlen(input);
		input[--input_len] = '\0';  //结束输入回车取消换行
		for (to = 0, index = 0; index <= input_len; index++) {
			if (*(input + index) != ' ') {  //清掉空格
				*(input + to++) = *(input + index);
			}
		}  
		//清空格
		input_len = strlen(input);  //保存无空格表达式
		index = 0;  //重置序号


		if (input[index] == '=') {  //跳过‘=’号
			index++;
		}
		//===========================================================================
		if(input_len>0) {
			
			number_len = 0;
			if (isdigit(*(input + index))) {        //如果是数字就复制===========
				for (; isdigit(*(input + index)); index++) {  
					*(number_str + number_len++) = *(input + index);  //下一数位
				}
				if (*(input + index) == '.') {  //如果是小数点 其后必有数字
					*(number_str + number_len++) = *(input + index++);// 复制 下一数位
					for (; isdigit(*(input + index)); index++) {     // 复制 数字 
						*(number_str + number_len++) = *(input + index);// 下一数位
					}
				}
				*(number_str + number_len) = '\0';  //  给有效数字符串加末尾标志
				result = atof(number_str);  //重复取得有效计算数
				//printf("\n  line55  %u  Number = %f\n", index, number);
			}
			

			for (; index < input_len; index++) {  //只要数据未全部读取，就重复查询
				//printf("\n index = %u\n", index);
				if ((isdigit(*(input + index-1)) == 0) && (index != 0)) {
					op = input[index-1];
					//printf("\n op %u = %c \n", index-1, op);//储存符号 并下一位
				}
				number_len = 0;
				for (; isdigit(*(input + index)); index++) {  //如果是数字就复制
					*(number_str + number_len++) = *(input + index);  //下一数位
				}
				if (*(input + index) == '.') {  //如果是小数点 其后必有数字
					*(number_str + number_len++) = *(input + index++);// 复制 下一数位
					for (; isdigit(*(input + index)); index++) {     // 复制 数字 
						*(number_str + number_len++) = *(input + index);// 下一数位
					}
				}
				*(number_str + number_len) = '\0';  //  给有效数字符串加末尾标志
				number = atof(number_str);          //重复取得有效计算数
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