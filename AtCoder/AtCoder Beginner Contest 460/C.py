import sys
input = lambda : sys.stdin.readline().rstrip()
ints = lambda : map(int,input().split())

N, M = [*ints()]
A = [*ints()]
B = [*ints()]

result = 0

A.sort()
B.sort()

A_p = 0
B_p = 0

while True:
    if A[A_p] * 2 >= B[B_p]:
        result += 1
        A_p += 1
        B_p += 1
    else:
        A_p += 1
    
    if A_p == len(A) or B_p == len(B):
        break
    
print(result)