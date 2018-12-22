// main_subtraction.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <stdio.h>
#include <string.h>
int main()
{
	char a[2][32] = { {0} }, minus_sign = 0, i = 0, j, *p_max = *a, *p_min, complement[32] = { 0 };
	memset(a[0], '0', 31), memset(a[1], '0', 31), memset(complement, '9', 31);
	scanf_s("%s%s", a[0]+1, 30, a[1]+1, 30);
	minus_sign = strlen(a[0]) < strlen(a[1]);
	if (strlen(a[0]) == strlen(a[1]))
	{
		while (a[0][i] == a[1][i] && a[0][i] != '\0') i++;
		if (a[0][i] == '\0') { printf("0"); return 0; }
		else if (a[0][i] < a[1][i]) minus_sign = 1;
	}
	if (minus_sign) { p_max = a[1]+1, p_min = a[0]+1; printf("-"); }
	else p_max = a[0]+1, p_min = a[1]+1;
	p_max[strlen(p_max) - 1]++;
	for (i = strlen(p_min) - 1, j = strlen(p_max) - 1; i >= 0; i--, j--)
		complement[j] -= p_min[i] - '0';
	for (i = strlen(p_max) - 1; i >= 0; i--)
	{
		p_max[i] += complement[i] - '0';
		if (p_max[i] > '9')p_max[i] -= 10, p_max[i - 1]++;
	}
	while (*p_max == '0') p_max++;
	printf("%s", p_max);
	return 0;
}

