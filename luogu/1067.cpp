#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define EPS 1e-6;

int a[120], n, i;

int main() {
	scanf("%d", &n);
	for (i = n; i >= 0; i--) {
		scanf("%d", a + i);
	}

	//printf("%dx^%d", a[n], n);
    if (n==0){
        printf("%d\n", a[0]);
        return 0;
    }
	
	if (a[n] > 1)printf("%dx^%d", a[n], n);
	else if (a[n] == 1)printf("x^%d", n);
	else if (a[n] == -1)printf("-x^%d", n);
	else printf("%dx^%d", a[n], n);

	for (i = n - 1; i >= 2; i--) {
		if (a[i] > 1)printf("+%dx^%d", a[i], i);
		else if (a[i] == 1)printf("+x^%d", i);
		else if (a[i] == 0)continue;
		else if (a[i] == -1)printf("-x^%d", i);
		else printf("%dx^%d", a[i], i);
	}
	if (a[1] > 1)printf("+%dx", a[1]);
	else if (a[1] == 1)printf("+x");
	//else if (a[i] == 0)continue;
	else if (a[i] == -1)printf("-x");
	else if (a[1] < 0)printf("%dx", a[1]);


	if (a[0] > 0)printf("+%d", a[0]);
	else if (a[0] < 0)printf("%d", a[0]);
	return 0;
}


