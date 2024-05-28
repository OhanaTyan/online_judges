with open("a.txt", "r") as f:
    s = f.read()
    ls = [int(ss) for ss in s.split('\n')[:-1]]
    for i in range(10000):
        if ls[i] == len(str(2**i)):
            continue
        else:
            print(i, ls[i], len(str(2**i)))
    
    print("ok")
