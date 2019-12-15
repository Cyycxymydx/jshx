/*********************************************************************
*插值
*********************************************************************/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double Lagrange_x(double*x_data, double*y_data, double x, int n);
//一组数据的拉格朗日插值  形参表：x取值（需顺序输入），y取值，插值点x值，数组组数
double Lagrange(double*x, double*y, double a);
//三点拉格朗日插值
double int_line(double*x, double*y, double x0, int n);
//线性插值	形参表：x取值，y取值，插值点x值，数据组数
/*********************************************************************
*一组数据的拉格朗日插值
*********************************************************************/
double Lagrange_x(double*x_data, double*y_data, double x, int n) {
	if (n < 3) {
		printf("拉格朗日插值数据点不足");
		exit(-1);
	}
	if (3 == n) {
		return Lagrange(x_data, y_data, x);
	}
	//for (int j = 0; j < n; j++) {
	//	if (x_data[j] == x) {
	//		return y_data[j];
	//	}
	//}//防智障模块
	if (x <= x_data[2]) {
		return Lagrange(x_data, y_data, x);
	}
	if (x >= x_data[n - 3]) {
		return Lagrange(x_data + n - 3, y_data + n - 3, x);
	}
	int i = 2;
	for (; i < n - 3; i++) {
		if ((x_data[i] - x) * (x_data[i + 1] - x) < 0) {
			break;
		}
	}
	if ((x - x_data[i - 1]) <= (x_data[i + 2] - x)) {
		return Lagrange(x_data + i - 1, y_data + i - 1, x);
	}
	else {
		return Lagrange(x_data + i, y_data + i, x);
	}
	printf("拉格朗日插值出现错误，请检查数据是否按顺序排列\n");
}
double Lagrange(double*x, double*y, double xa) {
	return(double)((xa - x[1])*(xa - x[2]) / (x[0] - x[1]) / (x[0] - x[2])*y[0] + (xa - x[0])*(xa - x[2]) / (x[1] - x[0]) / (x[1] - x[2])*y[1] + (xa - x[0])*(xa - x[1]) / (x[2] - x[0]) / (x[2] - x[1])*y[2]);
}
/*********************************************************************
*线性插值
*********************************************************************/
double int_line(double*x, double*y, double x0, int n) {
	int i = 0;
	//while (i < n) {
	//	if (x[i] == x0) {
	//		return y[i];
	//	}
	//	i++;
	//}//防智障模块
	//i = 0;
	while (i < n - 1) {
		if ((x[i] - x0)*(x[i + 1] - x0) <= 0) {
			break;
		}
		i++;
	}
	return y[i] + (y[i + 1] - y[i]) / (x[i + 1] - x[i])*(x0 - x[i]);
}
/*********************************************************************
*
*********************************************************************/