c = input()
c = [int(x) for x in c[-2:]] if len(c) > 1 else [0,int(c[-1])]
c[1] -= 2 if c[0] & 1 else 0
c[1] &= 3
print(4 if not c[1] else 0)