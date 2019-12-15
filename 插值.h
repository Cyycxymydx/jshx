/*********************************************************************
*��ֵ
*********************************************************************/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double Lagrange_x(double*x_data, double*y_data, double x, int n);
//һ�����ݵ��������ղ�ֵ  �βα�xȡֵ����˳�����룩��yȡֵ����ֵ��xֵ����������
double Lagrange(double*x, double*y, double a);
//�����������ղ�ֵ
double int_line(double*x, double*y, double x0, int n);
//���Բ�ֵ	�βα�xȡֵ��yȡֵ����ֵ��xֵ����������
/*********************************************************************
*һ�����ݵ��������ղ�ֵ
*********************************************************************/
double Lagrange_x(double*x_data, double*y_data, double x, int n) {
	if (n < 3) {
		printf("�������ղ�ֵ���ݵ㲻��");
		exit(-1);
	}
	if (3 == n) {
		return Lagrange(x_data, y_data, x);
	}
	//for (int j = 0; j < n; j++) {
	//	if (x_data[j] == x) {
	//		return y_data[j];
	//	}
	//}//������ģ��
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
	printf("�������ղ�ֵ���ִ������������Ƿ�˳������\n");
}
double Lagrange(double*x, double*y, double xa) {
	return(double)((xa - x[1])*(xa - x[2]) / (x[0] - x[1]) / (x[0] - x[2])*y[0] + (xa - x[0])*(xa - x[2]) / (x[1] - x[0]) / (x[1] - x[2])*y[1] + (xa - x[0])*(xa - x[1]) / (x[2] - x[0]) / (x[2] - x[1])*y[2]);
}
/*********************************************************************
*���Բ�ֵ
*********************************************************************/
double int_line(double*x, double*y, double x0, int n) {
	int i = 0;
	//while (i < n) {
	//	if (x[i] == x0) {
	//		return y[i];
	//	}
	//	i++;
	//}//������ģ��
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