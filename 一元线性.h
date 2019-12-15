/*********************************************************************
*�������
*********************************************************************/
#include <stdio.h>
#include <math.h>
double MU_liner(double *x, double *y, int n);
//һԪ�������	�βα�xָ�룬yָ�룬���ݵ����  ����ֵ�����ϵ��R
double MU_liner(double *x, double *y, int n) {
	double x_av = 0, y_av = 0, L_xx = 0, L_xy = 0, L_yy = 0, pk_a = 0, pk_b = 0, r = 0;
	//xƽ��ֵ��yƽ��ֵ��xx��xy��yy��a��b�����ϵ��R
	register int i = 0;//ѭ����������
	for (i = 0; i < n; i++) {
		x_av += x[i];
	}
	x_av /= n;//����xƽ��ֵ
	for (i = 0; i < n; i++) {
		y_av += y[i];
	}
	y_av /= n;//����yƽ��ֵ
	for (i = 0; i < n; i++) {
		L_xx += x[i] * x[i];
	}
	L_xx -= n * x_av*x_av;//����xx���
	for (i = 0; i < n; i++) {
		L_yy += y[i] * y[i];
	}
	L_yy -= n * y_av*y_av;//����yy���
	for (i = 0; i < n; i++) {
		L_xy += x[i] * y[i];
	}
	L_xy -= n * x_av*y_av;//����xy���
	pk_a = L_xy / L_xx;//����a
	pk_b = y_av - pk_a * x_av;//����b
	r = L_xy / sqrt(L_xx*L_yy);//����r

	///*����ʱȥ��ע��*/
	//printf("xƽ��ֵx_av=%lf\n", x_av);
	//printf("yƽ��ֵy_av=%lf\n", y_av);
	//printf("x���L_xx=%lf\n", L_xx);
	//printf("y���L_yy=%lf\n", L_yy);
	//printf("xy���L_xy=%lf\n", L_xy);
	//printf("a=%lf\n", pk_a);
	//printf("b=%lf\n", pk_b);
	//printf("��Ϸ���Ϊy=%lfx+%lf\n", pk_a, pk_b);
	//printf("���ϵ��R=%lf\n", r);


	return r;
}