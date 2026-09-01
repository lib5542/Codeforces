import sys
input = lambda : sys.stdin.readline().rstrip()
ints = lambda : map(int,input().split())

import decimal

for case in range(int(input())):
    X1, Y1, R1, X2, Y2, R2 = [*ints()]
    d = (X2-X1)**2 + (Y2-Y1)**2
    answer = "No"

    if (R1 + R2)**2 >= d:
        if (R1 >= R2 and d >= (R1 - R2)**2):
            answer = "Yes"
        if (R2 >= R1 and d >= (R2 - R1)**2):
            answer = "Yes"

    print(answer)