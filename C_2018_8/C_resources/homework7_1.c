#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define STR_LEN 512
#define NUM_LEN 30

int main(void) {
	unsigned char str_ary[STR_LEN];    // 字符输入总存储
	unsigned char num_ary[NUM_LEN];    // 字符输入当前数字字符存储
	size_t str_len = 0;             // 字符总输入长度
	size_t str_len_t = 0;            //辅助计数器
	unsigned int num_len = 0;       // 有效输入数字长度
	unsigned int index = 0;       //  总字符序号
	double number = 0;         //  当前数字
	double Sum = 0;           //  当前和
	unsigned int n_num = 0;     //  数字个数
	double result = 0;         //  结果

	printf("\n  C语言模拟计算，计算平均值,不需要提前知道要输入的数的个数，动态储存输入的所有数，最终计算其平均值 \n");
	printf("\n  请注意不要输入数字以外的字符,输完所有数字后再按一次回车即可计算平均值 \n");
	printf("\n  输入第 %u 个数字 或者按 q 退出 \n\n ",n_num + 1);
	while (strcmp(fgets(str_ary, STR_LEN, stdin), "q\n") != 0) {
		str_len = strlen(str_ary);         //记录初始输入字符位数 含有行结束符'\0'
		//printf("\n 输入了 %u 个字符 \n",str_len-1);
		for (str_len_t = 0,index = 0; index < str_len; index++) {          //去空格
			if (*(str_ary + index) != ' ') {
				*(str_ary + str_len_t++) = *(str_ary + index);
			}
		}
		*(str_ary + str_len_t) = '\0';  // 确保能正确舍弃无效字符，在末尾补行结束符'\0' 可知 最大序号 + 2 = 字符位长度 
		str_len_t = strlen(str_ary);    // 记录有效数字字符位数,不含有行结束符'\0' 可知 str_len_t + 空格数 = stl_len
		printf("\n 舍去 %u 个空格,数组长度由 %u 变为 %u \n", str_len-str_len_t, str_len, str_len_t);

		//逐位判断
		for (index = 0; index <= str_len_t-2; index++) {  //为确保只检查有效数字位 (str_len - 2)
			//=========================================================================================================================
			if (
				(
				(*(str_ary + index) != '.') && (*(str_ary + index) != '-') && (!(isdigit(*(str_ary + index))) != 0)    //  含有除了小数点负号外的其他非数字符号
				)
				|| 
				((*(str_ary + index) == '-') && index != 0)  // 负号不在首位
				) {
				//检查 当前输入 是否含有无效字符
				printf("\n 错误的输入，请重试 \n");
				printf("\n 第 %u 个字符 %c 无法解析 \n", index, *(str_ary+index));
				number = 0.00;
				goto one;
			}
			else {           //当前输入合法时
				if ((isdigit(*(str_ary + index))) || (*(str_ary + index) == '-')) {
					*(num_ary + index) = *(str_ary + index);
					printf("\n line 48 for 第 %u 位数字 = %c \n", index, *(num_ary + index));
					
				}
				if (*(str_ary + index) == '.') {
					for (size_t pot = (index + 1); pot <= str_len_t - 2; pot++) {
						if (*(str_ary + pot) == '.') {
							printf("\n 不能有两个小数点，重新输入 \n");
							number = 0.00;
							//直接退出循环
							goto one;
						}
						else {
							*(num_ary + index) = *(str_ary + index);
							printf("\n line 62 for 第 %u 位 是 小数点 \n", index);
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
			printf("\n 整数位最多10位，小数位最多6位，请重新输入 ! \n\n");
		}
		
		else {
			Sum += number;
			result = Sum / n_num;
			printf("\n 数据 %u = %10.6f     当前平均数 = %10.6f \n\n ", n_num, number,result);
		}
		for (size_t i = 0; i < str_len; i++) {
			*(str_ary + i) = NULL ;
			*(num_ary + i) = NULL ;
		}
		printf("\n 请输入第 %u 个数据 或者按 q 退出 \n\n ", n_num + 1);
	}
	system("pause");
	return 0;


}
