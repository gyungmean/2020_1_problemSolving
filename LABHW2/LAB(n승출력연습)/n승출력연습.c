//20190941 ±è°æ¹Î
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
long long pow(int r, int n)
{
	if (n == 1) return r;
	else if (n % 2 == 0) {
		int m_value = pow(r, n / 2);
		return m_value * m_value;
	}
	else {
		int m_value = pow(r, n / 2);
		return r * m_value * m_value;
	}
}
int main() {
	int r, c;
	scanf("%d %d", &r, &c);
	printf("%d", pow(r, c));
}