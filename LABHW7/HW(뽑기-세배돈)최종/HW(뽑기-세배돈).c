//20190941 김경민
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int money, int bills[], int n, int bucket[], int bucketIndex)
{
	int i;
	if (money == 0) {//지폐로 금액을 다 채운경우
		for (i = 0; i < bucketIndex; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		return;
	}
	else if (n < 0 || money < 0)//계산 불가능한 경우
		return;

	pick(money, bills, n - 1, bucket, bucketIndex); //한단계 낮은 단위 지폐로 채우는 방법 찾기 위임

	if (money - bills[n] >= 0) {
		bucket[bucketIndex] = bills[n];
		money -= bills[n];
		pick(money, bills, n, bucket, bucketIndex + 1);//지폐 한장을 내고 남은 금액을 채우는 방법 찾기 위임
	}
}
int main()
{
	int money;
	int bills[3] = { 1000, 5000, 10000 };
	int* bucket;
	int n;

	printf("세배돈 금액 입력(1000원 단위): ");
	scanf("%d", &money);
	n = money / 1000; //가장 작은 단위지폐로만 채우기 가능한 경우의 수
	bucket = (int*)malloc(sizeof(int) * n);

	pick(money, bills, 3 - 1, bucket, 0);
}