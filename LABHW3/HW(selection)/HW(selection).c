//20190941 김경민
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Student
{
	int id; 
	int korean, english, math;
};
void selection_sort(struct Student *s, int n)
{
	int i, j, min, minIdx, temp;

	for (i = 0; i < n - 1; i++) {
		min = s->korean;
		minIdx = 0;
		//max찾기
		for (j = 0; j <= n - i - 1; j++) {
			if (min >= (s + j)->korean) {
				min = (s + j)->korean;
				minIdx = j;
			}
		}
		temp = (s + (n - i - 1))->korean;
		(s + (n - i - 1))->korean = min;
		(s + minIdx)->korean = temp;

		temp = (s + (n - i - 1))->id;
		(s + (n - i - 1))->id = (s + minIdx)->id;
		(s + minIdx)->id = temp;

		temp = (s + (n - i - 1))->english;
		(s + (n - i - 1))->english = (s + minIdx)->english;
		(s + minIdx)->english = temp;

		temp = (s + (n - i - 1))->math;
		(s + (n - i - 1))->math = (s + minIdx)->math;
		(s + minIdx)->math = temp;
	}
}
int main()
{
	struct Student *s; //typedef써서 해보기
	int n, i;
	srand(time(NULL));

	//n 입력 받음
	printf("학생 수 입력:");
	scanf("%d", &n);
	//Student 구조체 배열을 동적으로 할당
	s = (int*)malloc(sizeof(int) * n);
	// 학번 부여
	for (i = 0; i < n; i++)
		s[i].id = i + 1;
	// random으로 성적 저장
	for (i = 0; i < n; i++) {
		s[i].korean = rand() % 100;
		s[i].english = rand() % 100;
		s[i].math = rand() % 100;
	}
	// 학생 정보(학번, 성적들) 출력
	printf("학번\t국어\t영어\t수학\n");
	printf("------------------------------\n");
	for (i = 0; i < n; i++) {
		printf("%d\t%d\t%d\t%d\n", s[i].id, s[i].korean, s[i].english, s[i].math);
	}
	//국어 성적 기준으로 내림 차순 정렬 selection sort 함수 호출
	selection_sort(s, n);

	// (정렬된) 학생 정보(학번, 성적들) 출력
	printf("\n국어 성적순 출력\n");
	printf("학번\t국어\t영어\t수학\n");
	printf("------------------------------\n");
	for (i = 0; i < n; i++) {
		printf("%d\t%d\t%d\t%d\n", s[i].id, s[i].korean, s[i].english, s[i].math);
	}
	//동적으로 할당 받은 구조체 배열 반환
	free(s);
}