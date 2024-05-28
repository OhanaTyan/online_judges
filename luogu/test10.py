ls = [1, 0, 4, 3, 5, 6, 2, 8, 7]
ls2 = [3, 6, 1, 3, 5, 2, 4, 7, 8, 6, 3]
n = len(ls)
print(ls)
for k in ls2:
    for i in range(k, n):
        ls[i], ls[i-k] = ls[i-k], ls[i]
    print(ls, k)
