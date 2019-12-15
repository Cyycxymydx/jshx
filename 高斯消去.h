/*********************************************************************
*高斯消去
*********************************************************************/
#include <math.h>
#ifndef SAVE_FILE_NAME_GAUSS
#define SAVE_FILE_NAME_GAUSS "result of guass.txt"//保存文件名
#endif  
#include "动态数组.h"
#include "矩阵IO.h"
void gauss(double**data, double*result, int n_line, int n_row);
//高斯消去	形参表：矩阵数组指针，答案数组指针（若无需要填NULL），行数，列数，
void exchange(double*a1, double*a2, int n_row);//交换矩阵两行元素
void gauss(double**data, double*result, int n_line, int n_row) {
	double**a = M_build(n_line, n_row);
	for (int i = 0, j = 0; i < n_line; i++) {
		for (j = 0; j < n_row; j++) {
			a[i][j] = data[i][j];
		}
	}//矩阵初始化
	register int i, j;//当前处理矩阵元素的行、列数
	int g;//选择主元中用于检验是否已遍历当前列元素的中间变量
	int singular = 0;//用于判断该矩阵是有唯一解的控制变量
	int main_i, main_j;//当前主元的行、列
	for (main_i = 0, main_j = 0; (main_i < n_line) && (main_j < n_row - 1); main_i++, main_j++) {
		for (g = main_i; g < n_line; g++) {//选定主元
			if (a[main_i][main_j]) //判断当前选中的元素是否为零
				break;
			else if (n_line - 1 != g) //若为零且当前列还未遍历则交换当前行与未判断的最前一行
				exchange(a[main_i], a[g + 1], n_row);
		}
		if ((n_line == g) && (!(a[main_i][main_j]))) {
			//若该列元素均为零，则该矩阵为奇异矩阵，在下一列元素中重新选择主元
			main_i--;
			singular = 1;
			continue;
		}
		for (j = n_row - 1; j >= main_j; j--) {
			a[main_i][j] /= a[main_i][main_j];
		}//将当前主元置1
		for (i = 0; i < n_line; i++) {
			if (i == main_i) {
				continue;
			}
			for (j = n_row - 1; j >= main_j; j--) {
				a[i][j] -= (a[i][main_j] * a[main_i][j]);
			}//消元
		}
	}
	printf("gauss消元结果：\n");
	M_printf(a, n_line, n_row);//输出消去后的矩阵
	FILE*fp_result;
	if (!(fp_result = fopen(SAVE_FILE_NAME_GAUSS, "wt"))) {
		printf("创建结果文件失败");
	}
	else {
		M_write(fp_result, a, n_line, n_row);
		fclose(fp_result);
	}
	if (main_i < n_row - 1) {
		singular = 1;
	}//若解矩阵行数小于列数，则矩阵无唯一解
	for (i = main_i + 1; i < n_line; i++) {
		if (a[i][n_row - 1]) {
			printf("该矩阵无解");
			return;
		}//判断是否无解
	}
	if (singular) {
		printf("该矩阵无有无穷多解");
	}
	else {
		if (NULL != result) {
			for (i = 0; i < n_row - 1; i++) {
				result[i] = a[i][n_row - 1];
			}
		}
		for (int i = 0; i < n_row - 1; i++) {
			printf("x%d=%lf\n", i + 1, a[i][n_row - 1]);
		}
	}
}
/*********************************************************************
交换矩阵两行元素
*********************************************************************/
void exchange(double*a1, double*a2, int n_row) {
	register double temp;
	int i = 0;
	for (i = 0; i < n_row; i++) {
		temp = a1[i];
		a1[i] = a2[i];
		a2[i] = temp;
	}
}
/*********************************************************************

*********************************************************************/
#undef SAVE_FILE_NAME_GAUSS