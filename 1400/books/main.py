import sys

def main():
    n, t = [int(x) for x in input().split()]
    v = (n+1) * [0]
    max_count = 0
    pos = 0
    sum = 0
    count = 0
    i = 1
    while i <= n:
        v[i] = readInt()
        sum += v[i]
        count += 1
        while sum > t:
            pos += 1
            sum -= v[pos]
            count -= 1
        if count > max_count:
            max_count = count
        i += 1
    print(max_count)

def readInt():
    s = str()
    c = sys.stdin.read(1)
    while c != ' ' and c != '\n':
        s += c
        c = sys.stdin.read(1)
    return int(s)

if __name__ == '__main__':
    main()
