//20190941 ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char actor[5][10] = { "����", "�����", "���߱�", "����", "����" };
void pick(int n, char bucket[][10], int bucketSize, int k)
{
	int i, lastIndex, smallest, item;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%s\t", bucket[i]);//%s�� ,�ڿ� �ּҰ��� �����°��� null�� ���ö�����
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
	//char *actor[] = {"����" ��¼��}; ������ �迭��

	printf("�α�� �� ��? ");
	scanf("%d", &n);

	bucket = (char**)malloc(sizeof(char) * n);
	for (i = 0; i < n; i++)
		bucket[i] = (char*)malloc(sizeof(char) * 10);
	pick(5, bucket, n, n);//pick(actor, 5, bucket, n, n);
	//item���� picke���� �̱ⰳ�� ������ �ؾ���

	for (i = 0; i < n; i++)
		free(bucket[i]);
	free(bucket);
}
