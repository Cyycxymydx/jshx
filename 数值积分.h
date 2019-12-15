/*********************************************************************
*��ֵ����
*********************************************************************/
#include "��ֵ.h"
#define END_CONDITION_OF_INTEGAL REL		//��������
#define LIME_OF_INTEGAL 1E-5				//����
#define ABS fabs(s0-s)<LIME_OF_INTEGAL		//���Ծ���
#define REL (fabs(s0-s)/s)<LIME_OF_INTEGAL	//��Ծ���
#define STAR_TIME_OF_INTEGAL 50				//��ʼ�����������
#define MAX_TIME_OF_INTEGAL 2000			//�������������
double num_integal(double*x, double*y, int n, double a, double b);
//��ɢ������η���ֵ����	�βα��Ա���xָ�룬yָ�룬���ݵ�������������ޣ���������
double num_integal_y(double(*f)(double), double a, double b);
//��֪���������η���ֵ����	�βα�����ָ�룬�������ޣ���������
double num_Simpson(double*x, double*y, int n, double a, double b);
//��ɢ�������ɭ����ֵ����	�βα��Ա���xָ�룬yָ�룬���ݵ�������������ޣ���������
double num_Simpson_y(double(*f)(double), double a, double b);
//��֪����������ɭ����ֵ����	�βα�����ָ�룬�������ޣ���������
/*********************************************************************
*��ɢ������η���ֵ����
*********************************************************************/
double num_integal(double*x, double*y, int n, double a, double b) {
	double length = b - a, h = length / STAR_TIME_OF_INTEGAL, s = 0, s0 = 0, t = (Lagrange_x(x, y, a, n) + Lagrange_x(x, y, b, n)) / 2;
	register int i = 0, j = 0;
	for (j = 1; j < STAR_TIME_OF_INTEGAL; j++) {
		s0 += Lagrange_x(x, y, a + j * h, n);
	}
	s0 += t;
	s0 *= h;
	for (i = STAR_TIME_OF_INTEGAL + 1; i < MAX_TIME_OF_INTEGAL; i++) {
		h = length / i;
		for (j = 1; j < i; j++) {
			s += Lagrange_x(x, y, a + j * h, n);
		}
		s += t;
		s *= h;
		if (END_CONDITION_OF_INTEGAL) {
			/*printf("%d\n", i);*/
			return s;
		}
		else {
			s0 = s;
			s = 0;
		}
	}
	printf("δ���ڹ涨�������޷���û���");
}
/*********************************************************************
*��֪���������η���ֵ����
*********************************************************************/
double num_integal_y(double(*f)(double), double a, double b) {
	double length = b - a, h = length / STAR_TIME_OF_INTEGAL, s = 0, s0 = 0, t = (f(a) + f(b)) / 2;
	register int i = 0, j = 0;
	for (j = 1; j < STAR_TIME_OF_INTEGAL; j++) {
		s0 += f(a + j * h);
	}
	s0 += t;
	s0 *= h;
	for (i = STAR_TIME_OF_INTEGAL + 1; i < MAX_TIME_OF_INTEGAL; i++) {
		h = length / i;
		for (j = 1; j < i; j++) {
			s += f(a + j * h);
		}
		s += t;
		s *= h;
		if (END_CONDITION_OF_INTEGAL) {
			/*printf("%d\n", i);*/
			return s;
		}
		else {
			s0 = s;
			s = 0;
		}
	}
	printf("δ���ڹ涨�������޷���û���");
}
/*********************************************************************
*��ɢ�������ɭ����ֵ����
*********************************************************************/
double num_Simpson(double*x, double*y, int n, double a, double b) {
	double length = b - a, h = length / (2 * STAR_TIME_OF_INTEGAL), s0 = 0, s = 0, t = (Lagrange_x(x, y, a, n) - Lagrange_x(x, y, b, n)) / 2;
	register int i = 0, j = 0, k = 0;
	for (j = 1, k = 2; j < STAR_TIME_OF_INTEGAL * 2; j += 2, k += 2) {
		s0 += 2 * Lagrange_x(x, y, a + j * h, n);
		s0 += Lagrange_x(x, y, a + k * h, n);
	}
	s0 += t;
	s0 *= 2 * h / 3;
	for (i = STAR_TIME_OF_INTEGAL + 1; i < MAX_TIME_OF_INTEGAL; i++) {
		h = length / (2 * i);
		for (j = 1, k = 2; j < i * 2; j += 2, k += 2) {
			s += 2 * Lagrange_x(x, y, a + j * h, n);
			s += Lagrange_x(x, y, a + k * h, n);
		}
		s += t;
		s *= 2 * h / 3;
		if (END_CONDITION_OF_INTEGAL) {
			/*printf("%d\n", i);*/
			return s;
		}
		else {
			s0 = s;
			s = 0;
		}
	}
	printf("δ���ڹ涨�������޷���û���");
}
/*********************************************************************
*��֪����������ɭ����ֵ����
*********************************************************************/
double num_Simpson_y(double(*f)(double), double a, double b) {
	double length = b - a, h = (b - a) / (2 * STAR_TIME_OF_INTEGAL), s0 = 0, s = 0, t = (f(a) - f(b)) / 2;
	register int i = 0, j = 0, k = 0;
	for (j = 1, k = 2; j < STAR_TIME_OF_INTEGAL * 2; j += 2, k += 2) {
		s0 += f(a + j * h) * 2;
		s0 += f(a + j * h);
	}
	s0 += t;
	s0 *= 2 * h / 3;
	for (i = STAR_TIME_OF_INTEGAL + 1; i < MAX_TIME_OF_INTEGAL; i++) {
		h = length / (2 * i);
		for (j = 1, k = 2; j < (2 * i); j += 2, k += 2) {
			s += f(a + j * h) * 2;
			s += f(a + k * h);
		}
		s += t;
		s *= 2 * h / 3;
		if (END_CONDITION_OF_INTEGAL) {
			/*printf("%d\n", i);*/
			return s;
		}
		else {
			s0 = s;
			s = 0;
		}
	}
	printf("δ���ڹ涨�������޷���û���");
}
/*********************************************************************
*
*********************************************************************/
#undef END_CONDITION_OF_INTEGAL
#undef LIME_OF_INTEGAL
#undef ABS
#undef REL
#undef STAR_TIME_OF_INTEGAL
#undef MAX_TIME_OF_INTEGAL