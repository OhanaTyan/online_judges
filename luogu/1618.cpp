
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>


bool isans = false;

int _check(int x) {
	int ret = 0;
	while (x) {
		int a = x % 10;
		ret |= 1 << a;
		x /= 10;
	}
	return ret;
}

int check(int a, int b, int c) {
	int res = _check(a) | _check(b) | _check(c);
	const static int ck_num =
		1 << 1 | 1 << 2 | 1 << 3 | 1 << 4 |
		1 << 5 | 1 << 6 | 1 << 7 | 1 << 8 | 1 << 9;

	if (res == ck_num) {
		printf("%d %d %d\n", a, b, c);
		isans = true;
	}
	return 0;
}

int a, b, c;

int main() {
	scanf("%d%d%d", &a, &b, &c);
	int x, y, z;

    if (a==0){
        printf("No!!!\n");
        return 0;
    }
	for (x = 0; x < 1000; x++) {
		if (x % a)continue;
		y = x / a;
		z = y * c;
		y *= b;
		if (y >= 1000 || z >= 1000)continue;
		check(x, y, z);
	}
	if (!isans) {
		printf("No!!!");
	}

	return 0;

}




