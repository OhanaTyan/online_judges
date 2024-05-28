def func(ls): 
    if len(ls) == 1:
        return ls[0]
    return ls[0] ** func(ls[1:])

for l in range(2**3, 2**5):
    s = bin(l)[2:]
    ls = [int(ss) for ss in s]
    print("      Assert::That(last_digit({", end="")
    for i in range(len(s)):
        if (i!=0):
            print(",", end="")
        print(ls[i], end="")
    print("}),\tEquals(", end="")
    print(func(ls)%10, end="")
    print("));")
    ls.reverse()
    ls.append(0)
    ls.reverse()
    print("      Assert::That(last_digit({", end="")
    for i in range(len(s)):
        if (i!=0):
            print(",", end="")
        print(ls[i], end="")
    print("}),\tEquals(", end="")
    print(func(ls)%10, end="")
    print("));")    

