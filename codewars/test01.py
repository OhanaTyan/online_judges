for i in range(100):
    for j in range(1,100):
        if i%4==1:
            assert (i**j)%4 == 1
        elif i%4==2:
            if j==0:
                assert (i**j)%4 == 1
            elif j==1:
                assert (i**j)%4 == 2
            else:
                assert (i**j)%4 == 0
        elif i%4==3:
            assert (i**j)%4 == (i**(j%4))%4
        else:
            assert (i**j)%4 == 0

            