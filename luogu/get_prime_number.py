from math import *
def is_prime(x):
    for i in range(2, int(sqrt(x))):
        if x%i == 0:
            return False
    return True
for i in range(2, 10**9):
    if (is_prime(i)):
        print(i, end=',') 