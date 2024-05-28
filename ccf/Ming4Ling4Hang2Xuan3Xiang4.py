def check_string(s):
    for c in s:
        if c in "1234567890qwertyuiopasdfghjklzxcvbnm-":
            continue
        else:
            return False
    return True

if __name__ == "__main__":
    s = input()
    n = len(s)
    option_with_arg = []
    option_with_no_arg = []
    for i in range(n-1):
        if s[i+1]==':':
            option_with_arg.append(s[i])
        elif s[i] == ':':
            continue
        else:
            option_with_no_arg.append(s[i])
    if s[-1] == ':':
        pass
    else:
        option_with_no_arg.append(s[-1])
    
    n = int(input())
    for i in range(1, n+1):
        s = input()
        ls = s.split(' ')[1:]
        print(f"Case {i}: ", end="")
        # remove blank in ls
        lls=[]
        for ss in ls:
            if ss != " ":
                lls.append(ss)
        ls = lls
        j = 0
        options = []
        args = {}
 
        try:
           while j < len(ls):
                ss = ls[j]
                if ss[0]=='-':
                    # option
                    if len(ss) != 2:
                        # raise Exception
                        break
                    c = ss[1]
                    if c in option_with_no_arg:
                        j += 1
                        if c not in options:
                            options.append(c)
                        continue
                    elif c in option_with_arg:
                        if j+1 >= len(ls):
                            #raise Exception
                            break
                        if check_string(ls[j+1]) is False:
                            # raise Exception
                            break 
                        if c not in options:
                            options.append(c)
                        args[c] = ls[j+1]
                        j += 2
                        continue
                    else:
                        # raise Exception
                        break
                else:
                    # raise Exception
                    break
        except Exception as e:
            pass
        finally:
            sorted(options)
            for a in options:
                if a in option_with_no_arg:
                    print(f"-{a} ", end="")
                else:
                    print(f"-{a} {args[c]} ", end="")
        print()



