/*********************************************************************
*多元线性拟合
*********************************************************************/
#include <stdio.h>
#include <math.h>
#include "高斯消去.h"
#ifndef RESULT_OF_VLF
#define RESULT_OF_VLF "result vlf.txt"	//输出文件名
#endif
double var_liner_fitting(double**a, const int num_vae, const int num_line);
//多元线性拟合  形参表：矩阵数组指针，自变量数量，数据组数
double var_liner_fitting(double**a, const int num_vae, const int num_line) {
	int n_row = num_vae + 2;
	double**data = M_build(num_line, n_row);
	for (int i = 0, j = 0; i < num_line; i++) {
		data[i][0] = 1;
		for (j = 1; j < n_row; j++) {
			data[i][j] = a[i][j - 1];
		}
	}
	double**cou_data = M_build(num_vae + 1, num_vae + 2);
	double *result = M1_build(num_vae + 1);
	for (int i = 0, j = 0, t = 0; i < num_vae + 1; i++) {
		for (j = 0; j < num_vae + 1 + 1; j++) {
			for (t = 0; t < num_line; t++) {
				cou_data[i][j] += data[t][i] * data[t][j];
			}
		}
	}
	printf("计算矩阵：\n");
	M_printf(cou_data, num_vae + 1, num_vae + 2);
	gauss(cou_data, result, num_vae + 1, n_row);
	double*y = M1_build(num_line);
	for (int i = 0, j = 0; i < num_line; i++) {
		for (j = 0; j < num_vae + 1; j++) {
			y[i] += (data[i][j] * result[j]);
		}
	}
	double T_a = 0, T_b = 0, y_v = 0;
	for (int i = 0; i < num_line; i++) {
		y_v += data[i][n_row - 1];
	}
	y_v /= num_line;
	for (int i = 0; i < num_line; i++) {
		T_a += (y[i] - y_v)*(y[i] - y_v);
		T_b += (data[i][n_row - 1] - y_v)*(data[i][n_row - 1] - y_v);
	}
	double R = sqrt(T_a / T_b);
	FILE*fp_result;
	if (!(fp_result = fopen(RESULT_OF_VLF, "wt")))
		printf("写入结果失败");
	else {
		for (int i = 0; i < num_vae + 1; i++) {
			fprintf(fp_result, "x%d=%lf\n", i, result[i]);
		}
		fprintf(fp_result, "R=%lf\n", R);
		fclose(fp_result);
	}
	return R;
}
/*********************************************************************
*
*********************************************************************/
#undef RESULT_OF_VLF