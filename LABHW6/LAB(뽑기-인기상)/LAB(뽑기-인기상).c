//20190941 김경민
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char actor[5][10] = { "공유", "김수현", "송중기", "지성", "현빈" };
void pick(int n, char bucket[][10], int bucketSize, int k)
{
	int i, lastIndex, smallest, item;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%s\t", bucket[i]);//%s는 ,뒤에 주소값이 나오는거임 null이 나올때까지
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;
	if (bucketSize == k)
		smallest = 0; //actor[0]
	else
		for(i = 0; i < 5; i++)
			if (strcmp(actor[i], bucket[lastIndex]) == 0) {
				smallest = i + 1;
				break;
			}
	for (item = smallest; item < n; item++) {
		strcpy(bucket[lastIndex + 1], actor[item]);
		pick(n, bucket, bucketSize, k - 1);
	}
}
int main()
{
	int n, i;
	char** bucket;
	//char *actor[] = {"공유" 어쩌구}; 포인터 배열임

	printf("인기상 몇 명? ");
	scanf("%d", &n);

	bucket = (char**)malloc(sizeof(char) * n);
	for (i = 0; i < n; i++)
		bucket[i] = (char*)malloc(sizeof(char) * 10);
	pick(5, bucket, n, n);//pick(actor, 5, bucket, n, n);
	//item정보 picke정보 뽑기개수 순으로 해야함

	for (i = 0; i < n; i++)
		free(bucket[i]);
	free(bucket);
}
