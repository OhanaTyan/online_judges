
mp = {}
s = input().split(' ')
n = int(s[0])
m = int(s[1])
fa = {}
file = [0, ]
fa[1] = 0

for i in range(1, n+1):
    mp[i] = []

for i, f in zip(range(2, n+1), input().split(' ')):
    f = int(f)
    fa[i] = f
    mp[f].append(i)


for i, d in zip(range(1, n+1), input().split(' ')):
    file.append(int(d))

for _ in range(m):
    l = input().split(' ')
    op = int(l[0])
    f = int(l[1])
    if op == 1:
        ls = mp[f]
        if len(ls) == 0:
            print(f"0 {file[f]}")
            continue
        mp[f] = []
        for i in ls:
            file[f] += file[i]
            for j in mp[i]:
                mp[f].append(j)
                fa[j] = f
            #mp[f] += mp[i]
            del mp[i]
        print(f"{len(mp[f])} {file[f]}")
    else:
        ans = 0
        while f:
            ans += 1
            f = fa[f]
        print(ans)

        



