#include <stdio.h>

int sub_3_c(void) {
	int num;
	num = Fibonacci(7);
	printf("%d", num);
	Hanoi(4, 'A', 'B', 'C');
	return 0;
}

int Fibonacci(int n) {
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);	
}

int Hanoi(int num, char from, char by, char to) {
	if (num == 1)
		printf("원반 1을 %c에서 %c로 이동\n", from, to);
	else {
		Hanoi(num - 1, from, to, by);
		printf("원반 %d를 %c에서 %c로 이동\n", num, from, to);
		Hanoi(num - 1, by, from, to);
	}
}
int memo[100]; //메모이제이션 공간. 전역 변수이므로 0으로 초기화
int dynamic(int n) {
	if (n <= 1) //0번째, 1번째 피보나치 수
		return n;
	if (memo[n] != 0) //메모가 있는지 확인(0으로 초기화되었으므로 0이 아니라면 메모가 쓰인 것임)
		return memo[n]; //메모 리턴
	memo[n] = dynamic(n - 1) + dynamic(n - 2); //작은 문제로 분할
	return memo[n];
}