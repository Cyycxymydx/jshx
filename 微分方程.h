/*********************************************************************
*微分方程
*********************************************************************/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define END_CONDITION_OF_DE REL	//结束条件
#define LIME 1E-5				//精度
#define ABS fabs(y - yi)<LIME	//绝对精度
#define REL fabs(y - yi)/y<LIME	//相对精度
#define STAR_TIME_OF_DE 10		//起始子区间数量
#define MAX_TIME_OF_DE 2000		//最大子区间数量
double nan(void) {
	unsigned long nan[2] = { 0xffffffff, 0x7fffffff };
	return(*(double*)nan);
}//返回nan
double df(double(*f)(double x, double y), double x0, double y0, double b);
//数值解常微分方程	形参表：函数指针，x初始值（积分下限），y初始值，积分上限
/*********************************************************************
*数值解常微分方程
*********************************************************************/
double df(double(*f)(double x, double y), double x0, double y0, double b) {
	if (x0 == b) {
		return y0;
	}//若区间长度为0，则返回
	double x = x0, y = y0, x1, y1, length = (b - x0), h, yi = nan();
	//子区间左端点x值，y值，右端点x值，y值，积分区间长度，子区间长度，上一次迭代结果
	for (int i = STAR_TIME_OF_DE, j = 0; i < MAX_TIME_OF_DE; i++) {
		h = length / i;//重算子区间长度
		for (j = 0, x = x0, y = y0; j < i; j++) {
			x1 = x + h;
			y1 = y + h * f(x, y);//计算右端点x、y值
			y += (f(x, y) + f(x1, y1)) / 2 * h;//梯形法计算积分
			x += h;
		}
		if (END_CONDITION_OF_DE) {
			/*printf("%d\n", i);*/
			return y;
		}//若两次迭代结果满足精度，则返回
		else {
			yi = y;
		}//不满足则继续计算，直到满足为止
	}
	printf("未能在指定次数内求解微分方程\n");
}
/*********************************************************************
*
*********************************************************************/
#undef END_CONDITION_OF_DE
#undef LIME
#undef ABS
#undef REL
#undef STAR_TIME_OF_DE
#undef MAX_TIME_OF_DE