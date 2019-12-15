/*********************************************************************
*线性拟合
*********************************************************************/
#include <stdio.h>
#include <math.h>
double MU_liner(double *x, double *y, int n);
//一元线性拟合	形参表：x指针，y指针，数据点个数  返回值：相关系数R
double MU_liner(double *x, double *y, int n) {
	double x_av = 0, y_av = 0, L_xx = 0, L_xy = 0, L_yy = 0, pk_a = 0, pk_b = 0, r = 0;
	//x平均值，y平均值，xx离差，xy离差，yy离差，a，b，相关系数R
	register int i = 0;//循环计数变量
	for (i = 0; i < n; i++) {
		x_av += x[i];
	}
	x_av /= n;//计算x平均值
	for (i = 0; i < n; i++) {
		y_av += y[i];
	}
	y_av /= n;//计算y平均值
	for (i = 0; i < n; i++) {
		L_xx += x[i] * x[i];
	}
	L_xx -= n * x_av*x_av;//计算xx离差
	for (i = 0; i < n; i++) {
		L_yy += y[i] * y[i];
	}
	L_yy -= n * y_av*y_av;//计算yy离差
	for (i = 0; i < n; i++) {
		L_xy += x[i] * y[i];
	}
	L_xy -= n * x_av*y_av;//计算xy离差
	pk_a = L_xy / L_xx;//计算a
	pk_b = y_av - pk_a * x_av;//计算b
	r = L_xy / sqrt(L_xx*L_yy);//计算r

	///*调试时去除注释*/
	//printf("x平均值x_av=%lf\n", x_av);
	//printf("y平均值y_av=%lf\n", y_av);
	//printf("x离差L_xx=%lf\n", L_xx);
	//printf("y离差L_yy=%lf\n", L_yy);
	//printf("xy离差L_xy=%lf\n", L_xy);
	//printf("a=%lf\n", pk_a);
	//printf("b=%lf\n", pk_b);
	//printf("拟合方程为y=%lfx+%lf\n", pk_a, pk_b);
	//printf("相关系数R=%lf\n", r);


	return r;
}