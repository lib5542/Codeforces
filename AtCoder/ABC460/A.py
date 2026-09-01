import sys
input = lambda : sys.stdin.readline().rstrip()
ints = lambda : map(int,input().split())

N, M = [*ints()]

counter = 0
while M != 0:
    x = N % M
    M = x
    counter += 1
print(counter)