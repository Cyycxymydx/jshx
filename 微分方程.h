/*********************************************************************
*΢�ַ���
*********************************************************************/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define END_CONDITION_OF_DE REL	//��������
#define LIME 1E-5				//����
#define ABS fabs(y - yi)<LIME	//���Ծ���
#define REL fabs(y - yi)/y<LIME	//��Ծ���
#define STAR_TIME_OF_DE 10		//��ʼ����������
#define MAX_TIME_OF_DE 2000		//�������������
double nan(void) {
	unsigned long nan[2] = { 0xffffffff, 0x7fffffff };
	return(*(double*)nan);
}//����nan
double df(double(*f)(double x, double y), double x0, double y0, double b);
//��ֵ�ⳣ΢�ַ���	�βα�����ָ�룬x��ʼֵ���������ޣ���y��ʼֵ����������
/*********************************************************************
*��ֵ�ⳣ΢�ַ���
*********************************************************************/
double df(double(*f)(double x, double y), double x0, double y0, double b) {
	if (x0 == b) {
		return y0;
	}//�����䳤��Ϊ0���򷵻�
	double x = x0, y = y0, x1, y1, length = (b - x0), h, yi = nan();
	//��������˵�xֵ��yֵ���Ҷ˵�xֵ��yֵ���������䳤�ȣ������䳤�ȣ���һ�ε������
	for (int i = STAR_TIME_OF_DE, j = 0; i < MAX_TIME_OF_DE; i++) {
		h = length / i;//���������䳤��
		for (j = 0, x = x0, y = y0; j < i; j++) {
			x1 = x + h;
			y1 = y + h * f(x, y);//�����Ҷ˵�x��yֵ
			y += (f(x, y) + f(x1, y1)) / 2 * h;//���η��������
			x += h;
		}
		if (END_CONDITION_OF_DE) {
			/*printf("%d\n", i);*/
			return y;
		}//�����ε���������㾫�ȣ��򷵻�
		else {
			yi = y;
		}//��������������㣬ֱ������Ϊֹ
	}
	printf("δ����ָ�����������΢�ַ���\n");
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