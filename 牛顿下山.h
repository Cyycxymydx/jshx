/*********************************************************************
*牛顿下山
*********************************************************************/
#include"数值微分.h"
#define END_CONDITION_OF_NEWTOWN REL	//结束条件
#define LIME 1E-2						//精度
#define ABS (fabs((f(a)-ans)))<LIME		//绝对精度
#define REL (fabs((f(a)-ans)/ans))<LIME	//相对精度
#define MAX_TIME_OF_NEWTOWN  2000			//最大循环次数
#define STPE_OF_NEWTOWN 1E-2			//步长
double newtown(double a, double ans, double(*f)(double), double(*f1)(double));
//牛顿下山法：初始值，求解函数值，函数指针，导函数指针
double newtown_num(double a, double ans, double(*f)(double));
//
/*********************************************************************
*已知导数的牛顿下山法
*********************************************************************/
double newtown(double a, double ans, double(*f)(double), double(*f1)(double))
{
	register int i = 0;
	while (i <= MAX_TIME_OF_NEWTOWN){
		if (END_CONDITION_OF_NEWTOWN) {
			return a;
		}
		a -= f(a) / f1(a);
		i++;
	}
	return EOF;
}
/*********************************************************************
*数值微分的牛顿下山法
*********************************************************************/
double newtown_num(double a, double ans, double(*f)(double)) {
	register int i = 0;
	while (i <= MAX_TIME_OF_NEWTOWN){
		if (END_CONDITION_OF_NEWTOWN) {
			return a;
		}
		a -= f(a) / num_differ_f(f, a, STPE_OF_NEWTOWN);
		i++;
	}
	return EOF;
}
/*********************************************************************
*
*********************************************************************/
#undef END_CONDITION_OF_NEWTOWN
#undef LIME
#undef MAX_TIME_OF_NEWTOWN
#undef EPS
#undef REL
#undef STPE_OF_NEWTOWN