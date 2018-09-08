#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STRLEN 254
#define NUMLEN 12
int main(void) {

	unsigned char temperature_str[STRLEN];  // 总输入
	unsigned char temperature_num[NUMLEN];  // 有效数

	size_t len_tem_str = 0;             // 总输入字符长
	unsigned len_tem_num = 0;        // 有效温度字符长
	unsigned n_tem_num = 0;         // 有效温度个数
	unsigned n_index = 0;           // 每天的温度序数

	double tem_Num[120][6] = { 0.00 };              // 每个温度值

	double tem_pre_Num[120] = { 0.00 };           // 每天温度值

	unsigned index = 0;                // 总字符序号
	unsigned index_tem = 0;             // 温度字符序号

	unsigned day = 0;
	char tem_Add;

	printf("\n ==== homework 7-2 2018-07-30 ==== \n\n ");

	while (strcmp(fgets(temperature_str, STRLEN, stdin), "q\n") != 0) {
		len_tem_str = strlen(temperature_str);
		if ((*(temperature_str) == '\n')) {
			goto ne_xt;
		}
		if ((*(temperature_str) == 'n')) {
			printf("\n 重新开始将删除已输入的所有数据   确定 按 a   取消 按 任意键， \n\n ");
			if (tem_Add=getchar() == 'a') {
				printf(" \n 已重新开始 \n ");
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
				printf(" \n 已取消 \n ");
				while ((tem_Add = getchar()) != EOF && tem_Add != '\n');
				goto ne_xt;
			}



		}


		if ((*(temperature_str) == 'o') && (*(temperature_str + 1) == 'k') && (len_tem_str == 3)) {  //  输入 ok
			printf("\n\n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ ");
			for (size_t i = 1,d = 0, x = 1; i <= n_tem_num; i++) {
				if (((x-1) % 6) == 0) {
					x = 1;
					d++;
					printf(" \n\n --- 第 %u 天 --- \n ", d);
					for (size_t i = 0; i <= 5; i++) {
						tem_pre_Num[d-1] += tem_Num[d - 1][i];
					}

					tem_pre_Num[d - 1] /= 6;  //  对于每天记录满6次的直接计算均值

					if (n_tem_num % 6) {    //  对于最后一天数值不够的情况，除数动态变化
						tem_pre_Num[(n_tem_num / 6)] *= 6;  // 先复原被上一步除的6次
						tem_pre_Num[(n_tem_num/6)] /= (n_tem_num % 6);  //  得出平均值

					}
					printf(" \n 平均气温 %.2f 度 \n\n ", tem_pre_Num[d-1]);
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
		//printf("\n 输入了 %u 个字符 \n ", len_tem_str-1);
		for (index = 0; index < len_tem_str - 1; index++) {        // 不是ok 则检查
			if (
			(
				(*(temperature_str + index) != '.') &&               //   不是小数点
				(*(temperature_str + index) != '-') &&                //  不是负号
				(!(isdigit(*(temperature_str + index))) != 0)           //  不是数字
			) ||
				((*(temperature_str + index) == '-') && index != 0)     //  不是首位负号
			)
			{
				printf("\n 不支持空格，字母及其他符号 \n ");
				goto ne_xt;
			}
			else {
				if ((isdigit(*(temperature_str + index))) || (*(temperature_str + index) == '-'))    // 数字或负号
				{
					*(temperature_num + index) = *(temperature_str + index);
					//printf("\n line 58 for 第 %u 位数字 = %c \n ", index, *(temperature_num + index));

				}
				else if (*(temperature_str + index) == '.')                        // 小数点
				{
					for (size_t pot = index + 1; pot < len_tem_str; pot++) {
						if (*(temperature_str + pot) == '.') {
							printf(" \n 两个小数点 ! \n ");
							goto ne_xt;
						}
					}
					*(temperature_num + index) = *(temperature_str + index);
					//printf("\n line 72 for 第 %u 位字符 = %c \n ", index, *(temperature_num + index));
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
			printf(" \n 温度不切实际 ! \n ");
			goto ne_xt;
		}

		if (n_tem_num % 6 == 0) {
			day++;
			n_index = 0;
		}
		n_tem_num++;
		n_index++;

		tem_Num[day-1][n_index-1] = atof(temperature_num);

		printf("\n 录入第 %u 天 的 第 %u 次记录温度成功 = %6.2f 度。当前已录入 %u 个数据 \n ", day, n_index, tem_Num[day-1][n_index-1], n_tem_num);

	ne_xt:printf("    ");
		//printf("\n 第 %u 天 的 第 %u 次记录温度 = %6.4f \n ", day, n_index, tem_Num[day][n_tem_num]);
		printf("\n ==== 录入 ==== ok = 计算 ==== n = 重新开始 ==== q = 退出 ==== \n\n ");
		for (size_t i = 0; i < len_tem_str; i++) {
			*(temperature_str + i) = NULL;
			*(temperature_num + i) = NULL;
		}

	}
	//system("pause");
	return 0;
}
