//20190941 ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int money, int bills[], int n, int bucket[], int bucketIndex)
{
	int i;
	if (money == 0) {//����� �ݾ��� �� ä����
		for (i = 0; i < bucketIndex; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		return;
	}
	else if (n < 0 || money < 0)//��� �Ұ����� ���
		return;

	pick(money, bills, n - 1, bucket, bucketIndex); //�Ѵܰ� ���� ���� ����� ä��� ��� ã�� ����

	if (money - bills[n] >= 0) {
		bucket[bucketIndex] = bills[n];
		money -= bills[n];
		pick(money, bills, n, bucket, bucketIndex + 1);//���� ������ ���� ���� �ݾ��� ä��� ��� ã�� ����
	}
}
int main()
{
	int money;
	int bills[3] = { 1000, 5000, 10000 };
	int* bucket;
	int n;

	printf("���起 �ݾ� �Է�(1000�� ����): ");
	scanf("%d", &money);
	n = money / 1000; //���� ���� ��������θ� ä��� ������ ����� ��
	bucket = (int*)malloc(sizeof(int) * n);

	pick(money, bills, 3 - 1, bucket, 0);
}