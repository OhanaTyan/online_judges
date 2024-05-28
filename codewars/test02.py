mp1 = {}
mp2 = {}
mp3 = {}
def f1(a, b):
    if (a, b) not in mp1:
        mp1[(a, b)] = a**b
    return mp1[(a, b)]


def f2(a, b, c):
    b = f1(b, c)
    if (a, b) not in mp2:
        mp2[(a, b)] = a**b
    return mp2[(a, b)]
    


with open("a.txt", "r") as f:
    s = f.read()
    l = s.split('\n')
    ll = [int(s) for s in l[:-1]]
    index = 0
    for i in range(3, 8, 4):
        for j in range(4):
            for k in range(4):
                for l in range(4):
                    index = (i//4)*64+j*16+k*4+l
                    
                    val = (i**f2(j, k, l))%10
                    if (ll[index]) != val:
                        print(index,i,j,k,l,ll[index],val)

print("OK")