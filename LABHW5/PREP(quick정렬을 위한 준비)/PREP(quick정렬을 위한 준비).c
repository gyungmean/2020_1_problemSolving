//20190941 김경민
#include <stdio.h>
int partition(int A[], int p, int r)
{
	int pivot = A[r];
	int i = p - 1;
	int j = p;
	int temp;

	while (j <= r) {
		if (A[p] > pivot)
			j++;
		else {
			temp = A[p];
			A[p] = A[i + 1];
			A[i + 1] = temp;//swap함수 써서하기
			i++;
			j++;
		}
		p++;
	}

	return i;//균일하게 i+1말고 i++으로 하기
}
void printList(int A[], int s, int e)
{
	int i;
	for (i = s; i <= e; i++)
		printf("%d ", A[i]);
	printf("\n");
}
int main(void)
{
	int list[] = { 0, 20, 55, 66, 10, 40, 88, 77, 30, 49 };
	int list2[] = { 0, 20, 10, 40, 30, 49, 88, 77, 55, 66 };
	int loc;

	// test 1
	printList(list, 0, 9);
	loc = partition(list, 0, 9); // list
	printList(list, 0, 9); // 결과는 list2의 값과 같게 된다.
	printf("%d의 위치는 %d\n", 49, loc); // 49의 위치는 5
	
	// test 2
	printList(list2, 6, 9); // 88, 77, 55, 66
	loc = partition(list2, 6, 9);
	printList(list2, 6, 9); // 55, 66, 88, 77
	printf("%d의 위치는 %d\n", 66, loc); // 66의 위치는 7
	
	// test 3
	printList(list2, 0, 4); // 0, 20, 10, 40, 30
	loc = partition(list2, 0, 4);
	printList(list2, 0, 4); // 0, 20, 10, 30, 40
	printf("%d의 위치는 %d\n", 30, loc); // 30의 위치는 3
}