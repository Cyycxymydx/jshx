/*********************************************************************
*��˹��ȥ
*********************************************************************/
#include <math.h>
#ifndef SAVE_FILE_NAME_GAUSS
#define SAVE_FILE_NAME_GAUSS "result of guass.txt"//�����ļ���
#endif  
#include "��̬����.h"
#include "����IO.h"
void gauss(double**data, double*result, int n_line, int n_row);
//��˹��ȥ	�βα���������ָ�룬������ָ�루������Ҫ��NULL����������������
void exchange(double*a1, double*a2, int n_row);//������������Ԫ��
void gauss(double**data, double*result, int n_line, int n_row) {
	double**a = M_build(n_line, n_row);
	for (int i = 0, j = 0; i < n_line; i++) {
		for (j = 0; j < n_row; j++) {
			a[i][j] = data[i][j];
		}
	}//�����ʼ��
	register int i, j;//��ǰ�������Ԫ�ص��С�����
	int g;//ѡ����Ԫ�����ڼ����Ƿ��ѱ�����ǰ��Ԫ�ص��м����
	int singular = 0;//�����жϸþ�������Ψһ��Ŀ��Ʊ���
	int main_i, main_j;//��ǰ��Ԫ���С���
	for (main_i = 0, main_j = 0; (main_i < n_line) && (main_j < n_row - 1); main_i++, main_j++) {
		for (g = main_i; g < n_line; g++) {//ѡ����Ԫ
			if (a[main_i][main_j]) //�жϵ�ǰѡ�е�Ԫ���Ƿ�Ϊ��
				break;
			else if (n_line - 1 != g) //��Ϊ���ҵ�ǰ�л�δ�����򽻻���ǰ����δ�жϵ���ǰһ��
				exchange(a[main_i], a[g + 1], n_row);
		}
		if ((n_line == g) && (!(a[main_i][main_j]))) {
			//������Ԫ�ؾ�Ϊ�㣬��þ���Ϊ�����������һ��Ԫ��������ѡ����Ԫ
			main_i--;
			singular = 1;
			continue;
		}
		for (j = n_row - 1; j >= main_j; j--) {
			a[main_i][j] /= a[main_i][main_j];
		}//����ǰ��Ԫ��1
		for (i = 0; i < n_line; i++) {
			if (i == main_i) {
				continue;
			}
			for (j = n_row - 1; j >= main_j; j--) {
				a[i][j] -= (a[i][main_j] * a[main_i][j]);
			}//��Ԫ
		}
	}
	printf("gauss��Ԫ�����\n");
	M_printf(a, n_line, n_row);//�����ȥ��ľ���
	FILE*fp_result;
	if (!(fp_result = fopen(SAVE_FILE_NAME_GAUSS, "wt"))) {
		printf("��������ļ�ʧ��");
	}
	else {
		M_write(fp_result, a, n_line, n_row);
		fclose(fp_result);
	}
	if (main_i < n_row - 1) {
		singular = 1;
	}//�����������С���������������Ψһ��
	for (i = main_i + 1; i < n_line; i++) {
		if (a[i][n_row - 1]) {
			printf("�þ����޽�");
			return;
		}//�ж��Ƿ��޽�
	}
	if (singular) {
		printf("�þ�������������");
	}
	else {
		if (NULL != result) {
			for (i = 0; i < n_row - 1; i++) {
				result[i] = a[i][n_row - 1];
			}
		}
		for (int i = 0; i < n_row - 1; i++) {
			printf("x%d=%lf\n", i + 1, a[i][n_row - 1]);
		}
	}
}
/*********************************************************************
������������Ԫ��
*********************************************************************/
void exchange(double*a1, double*a2, int n_row) {
	register double temp;
	int i = 0;
	for (i = 0; i < n_row; i++) {
		temp = a1[i];
		a1[i] = a2[i];
		a2[i] = temp;
	}
}
/*********************************************************************

*********************************************************************/
#undef SAVE_FILE_NAME_GAUSS