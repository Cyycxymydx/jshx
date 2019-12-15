/*********************************************************************
*ţ����ɽ
*********************************************************************/
#include"��ֵ΢��.h"
#define END_CONDITION_OF_NEWTOWN REL	//��������
#define LIME 1E-2						//����
#define ABS (fabs((f(a)-ans)))<LIME		//���Ծ���
#define REL (fabs((f(a)-ans)/ans))<LIME	//��Ծ���
#define MAX_TIME_OF_NEWTOWN  2000			//���ѭ������
#define STPE_OF_NEWTOWN 1E-2			//����
double newtown(double a, double ans, double(*f)(double), double(*f1)(double));
//ţ����ɽ������ʼֵ����⺯��ֵ������ָ�룬������ָ��
double newtown_num(double a, double ans, double(*f)(double));
//
/*********************************************************************
*��֪������ţ����ɽ��
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
*��ֵ΢�ֵ�ţ����ɽ��
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