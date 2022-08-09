//20190941 김경민
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int max1(int list[], int low, int high)
{
	int max, i;
	if (low <= high) {
		max = list[low];
		for (i = low; i <= high; i++)
			if (max < list[i])
				max = list[i];
	}
	return max;

}
int max2(int list[], int low, int high)
{
	int num1, num2, mid, rslt;

	mid = (low + high) / 2;
	if (low = mid) // low = high
		return list[low]; //return 자기자신(ex.list[low])

	num1 = max2(list, low, mid);
	num2 = max2(list, mid + 1, high);

	rslt = num1 >= num2 ? num1 : num2;
	return rslt; //rslt 안쓰고 return num1 >= num2 ? num1 : num2; 만 해도 됨
}
int main(void)
{
	int list[] = { 10, 20, 100, 4, 5, 45, 3, 99, 11, 22 };
	printf("가장 큰 수는 %d\n", max1(list, 0, 9)); // 100
	printf("가장 큰 수는 %d\n", max2(list, 0, 9)); // 100
	printf("가장 큰 수는 %d\n", max1(list, 5, 9)); // 99
	printf("가장 큰 수는 %d\n", max2(list, 5, 9)); // 99
	printf("가장 큰 수는 %d\n", max1(list, 3, 6)); // 45
	printf("가장 큰 수는 %d\n", max2(list, 3, 6)); // 45
}