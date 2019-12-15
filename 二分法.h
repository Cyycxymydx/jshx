/*********************************************************************
*二分法
*********************************************************************/
#include <stdio.h>
#include <math.h>
#define END_CONDITION_OF_DOUBLE ABS			//结束条件
#define LIME_OF_DOUBLE 1E-5					//精度
#define REL ((max-min)/min)<LIME_OF_DOUBLE	//相对精度
#define ABS (max-min)<LIME_OF_DOUBLE		//绝对精度
#define MAX_TIME_OF_DOUBLE  2000				//最大循环次数
double half(double min, double max, double sol, double(*f)(double));
//二分法  形参表：下界，上界，函数值，函数指针
double half(double min, double max, double sol, double(*f)(double)) {
	if (min > max) {
		double t = min;
		min = max;
		max = t;
	}
	if (0 == f(min) - sol)//若输入初值满足条件，则返回初值
		return min;
	if (0 == f(max) - sol)
		return max;
	double a = (min + max) / 2.0;//中点值
	double f_half = f(a);//中点函数值
	register int i = 0;
	while (i < MAX_TIME_OF_DOUBLE) {
		if (END_CONDITION_OF_DOUBLE)
			return a;//若满足循环结束条件，则返回中点值
		if ((f(min) - sol)*(f_half - sol) < 0)
			max = a;
		else
			min = a;
		a = (max + min) / 2.0;
		f_half = f(a);
		i++;
	}
	printf("调用二分法时出错，未求得相应的解");
	return EOF;//若未能在规定次数内得到所需精度的解，则结束函数并报错
}
/*********************************************************************
*
*********************************************************************/
#undef END_CONDITION_OF_DOUBLE
#undef LIME_OF_DOUBLE
#undef REL
#undef ABS
#undef MAX_TIME_OF_DOUBLE
