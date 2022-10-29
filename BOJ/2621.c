#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char colors[5];
int nums[5];
bool check[9];

int compare(const void *a, const void *b)
{
	int n1 = *(int *)a;
	int n2 = *(int *)b;

	if (n1 < n2)
		return -1;
	if (n1 > n2)
		return 1;
	return 0;
}

int solution(void)
{
	int answer = 0;
	bool check[9] = {false, };

	// 정렬
	qsort(nums, 5, sizeof(int), compare);

	// 1번 조건
	check[0] = true;
	char c = colors[0];
	for (int i = 1; i < 5; ++i) {
		if (c != colors[i])
			check[0] = false;
	}

	int tmp = nums[0];
	for (int i = 1; i < 5; ++i) {
		if (++tmp != nums[i])
			check[0] = false;
	}

	if (check[0]) {
		answer = 900 + nums[4];
		return answer;
	}

	// 2번 조건
	tmp = 0;
	check[1] = false;
	if (nums[1] == nums[4] || nums[0] == nums[3])
		check[1] = true;

	if (check[1]) {
		answer = 800 + nums[2];
		return answer;
	}

	// 3번 조건
	check[2] = false;
	int max_v = nums[4], min_v = nums[0];
	int cnt1 = 0, cnt2 = 0;

	for (int i = 0; i < 5; ++i) {
		if (max_v == nums[i])
			cnt1++;
		if (min_v == nums[i])
			cnt2++;
	}

	if (cnt1 == 3 && cnt2 == 2) {
		check[2] = true;
		tmp = max_v * 10 + min_v;
	}
	if (cnt1 == 2 && cnt2 == 3) {
		check[2] = true;
		tmp = min_v * 10 + max_v;
	}

	if (check[2]) {
		answer = tmp + 700;
		return answer;
	}

	// 4번 조건
	check[3] = true;
	for (int i = 0; i < 5; ++i) {
		if (colors[0] != colors[i])
			check[3] = false;
	}
	
	if (check[3]) {
		answer = 600 + nums[4];
		return answer;
	}

	// 5번 조건
	check[4] = true;
	tmp = nums[0];
	for (int i = 1; i < 5; ++i) {
		if (++tmp != nums[i]) {
			check[4] = false;
		}
	}

	if (check[4]) {
		answer = 500 + nums[4];
		return answer;
	}

	// 6번 조건
	int cnt = 0;
	tmp = nums[2];
	check[5] = true;

	for (int i = 0; i < 5; ++i) {
		if (nums[i] == tmp)
			cnt++;
	}

	if (cnt != 3) {
		check[5] = false;
	}

	if (check[5]) {
		answer = 400 + nums[2];
		return answer;
	}

	// 7번 조건
	check[6] = false;
	tmp = 0;
	if (nums[0] == nums[1] && nums[2] == nums[3])
		check[6] = true;
	else if (nums[1] == nums[2] && nums[3] == nums[4])
		check[6] = true;
	else if (nums[0] == nums[1] && nums[3] == nums[4])
		check[6] = true;
	
	if (check[6]) {
		answer = 300 + nums[3] * 10 + nums[1];
		return answer;
	}

	// 8번 조건
	check[7] = false;
	int eq;
	for (int i = 0; i < 4; ++i) {
		if (nums[i] == nums[i + 1]) {
			check[7] = true;
			eq = nums[i];
		}
	}

	if (check[7]) {
		answer = 200 + eq;
		return answer;
	}

	// 9번 조건
	answer = 100 + nums[4];
	return answer;
}

int main(void) {
	for (int i = 0; i < 5; ++i)
		scanf(" %c %d", &colors[i], &nums[i]);

	int ret = solution();
	printf("%d", ret);
	return 0;
}