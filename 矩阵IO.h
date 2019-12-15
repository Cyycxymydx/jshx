/*********************************************************************
*有关矩阵的I/O
*********************************************************************/
#include<stdio.h>
void M_read(FILE*fp_date, double**p_date, int n_line, int n_row);
//矩阵文件读入	形参表：数据文件指针，矩阵数组指针，行数，列数
void M_write(FILE*fp_result, double**result, int n_line, int n_row);
//矩阵文件输出	形参表：写入文件指针，矩阵数组指针，行数，列数
void M_printf(double**result, int n_line, int n_row);
//矩阵屏幕输出	形参表：矩阵数组指针，行数，列数
void M1_read(FILE*fp_file, double*data, int n);
//数组文件读入	形参表：数据文件指针，数组指针，数组长度
void M1_write(FILE*fp_result, double*result, int n);
//数组文件输出	形参表：写入文件指针，数组指针，数组长度
/*********************************************************************
*矩阵文件读入
*********************************************************************/
void M_read(FILE*fp_date, double**p_date, int n_line, int n_row) {
	int i = 0, j = 0;
	for (i = 0; i < n_line; i++) {
		for (j = 0; j < n_row; j++) {
			fscanf(fp_date, "%lf", (*(p_date + i) + j));
		}
	}
}
/*********************************************************************
*矩阵文件输出
*********************************************************************/
void M_write(FILE*fp_result, double**result, int n_line, int n_row) {
	int i = 0, j = 0;
	for (i = 0; i < n_line; i++) {
		for (j = 0; j < n_row; j++) {
			fprintf(fp_result, "%lf\t", result[i][j]);
		}
		fprintf(fp_result, "\n");
	}
}
/*********************************************************************
*矩阵屏幕输出
*********************************************************************/
void M_printf(double**result, int n_line, int n_row) {
	int i = 0, j = 0;
	for (i = 0; i < n_line; i++) {
		for (j = 0; j < n_row; j++) {
			printf("%lf\t", result[i][j]);
		}
		printf("\n");
	}
}
/*********************************************************************
*一维数组文件读入
*********************************************************************/
void M1_read(FILE*fp_file, double*data, int n) {
	int i = 0;
	while (i < n) {
		data[i] = fscanf(fp_file, "%lf", data + i);
		i++;
	}
}
/*********************************************************************
*一维数组文件输出
*********************************************************************/
void M1_write(FILE*fp_result, double*result, int n) {
	int i = 0;
	while (i < n) {
		fprintf(fp_result, "%lf\t", result[i]);
		i++;
	}
}
/*********************************************************************
*
*********************************************************************/