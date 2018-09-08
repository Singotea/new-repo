#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
// 定义常数
#define LEN_STR 9999       // 篇最大容量
#define NUM_WD 999         // 单词容量
#define LEN_WD 32          // 单个单词长度最大值
#define LEN_LINE 256        // 行最大容量

int main(void) {

	unsigned xl[NUM_WD] = { 0 };              // 记录单词首字母 序号
	unsigned index = 0;                        // 单词 序号
	unsigned indx = 0;                        // 字符 总序号
	unsigned char str_ary[LEN_LINE];                 // 每行可输入长度
	unsigned char str_Ary[LEN_STR];              // 篇总字符

	unsigned char words[NUM_WD][LEN_WD];          // 字符整理集合

	printf("\n homework 8-12 2018-8-10 \n\n ");
	printf("\n 输入任意长度字符串文本（上限1023） 不包含单引号 可回车 可空格 每行最多 120 字符 \n ");
	printf("\n 输入 start 回车 显示输入结果 \n\n 输入 q 回车 退出 \n\n 输入 new 回车 清除数据重新输入 \n\n ------------------------------------------------------------ \n\n ");
	while (strcmp(fgets(str_ary, 256, stdin), "q\n") != 0) {
		printf("\n ");
		if (strcmp(str_ary, "new\n") == 0) {
			for (size_t i = 0; i < LEN_STR; i++) str_Ary[i] = '\0';
			for (size_t i = 0; i < LEN_LINE; i++) str_ary[i] = '\0';
			for (size_t i = 0; i < NUM_WD; i++) xl[i] = 0;
			index = 0;
			indx = 0;
			printf(" \n 已重置记录器 \n\n 输入 start 回车 显示输入结果 \n\n 输入 q 回车 退出 \n\n ------------------------------------------------------------ \n\n ");
		}
		else if (strcmp(str_ary, "start\n") == 0) {
			*(str_Ary + indx) = '\n';
			index = 0;
			if (isalnum(*(str_Ary + 0)) != 0) {
				// 当首位为字母 必定组成单词
				xl[index] = 0;
				//printf(" \n %u word start with %u \n\n ", index + 1, xl[index] + 1);
				index++;
			}
			for (size_t i = 0; i < indx; i++) {
				if (isalnum(*(str_Ary + i)) == 0 && isalnum(*(str_Ary + i + 1)) != 0)
				{
					//  第 index+1 个单词开头   第1个开头为 0 
					xl[index] = i + 1;
					//printf(" \n %u word start with %u \n ", index + 1, xl[index] + 1);
					index++;
				}
			}
			if (index == 0) {
				printf(" \n 一个单词也找不到，请输入有效文字或短语 \n\n ");
			}
			else {
				printf(" \n 按字母顺序排列 并统计单词出现次数 \n ");
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
				// 按首字母 排序 首字母相同 依次寻找第二个第三个
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

				// 找重复单词 并统计次数
				unsigned num_index[NUM_WD] = { 0 };
				num_index[0] = 1;
				for (size_t i = 0; i < index - 1;) { // 重复遍历 
					if (strcmp(words[i], words[i + 1]) == 0) {
						// 比较相邻的两个单词 相同时执行操作
						num_index[i]++;
						for (size_t j = i; j < index - 2; j++) { // 将位于重复单词覆盖，向前覆盖一位
							for (size_t s = 0; s < LEN_WD; s++) {
								words[j + 1][s] = words[j + 2][s];
							}
						}
						index--; // 单词数少一位
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
					printf("   %u 次 \n ", num_index[i]);
				}
				printf(" \n ------------------------------------------------------------ \n\n 你可以 继续输入文段   或者 \n\n 输入 start 回车 显示输入结果 \n\n 输入 q 回车 退出 \n\n 输入 new 回车 清除数据 重新输入 \n\n ");
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
