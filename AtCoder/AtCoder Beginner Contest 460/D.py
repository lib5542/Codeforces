import sys
import copy
input = lambda : sys.stdin.readline().rstrip()
ints = lambda : map(int,input().split())

H, W = [*ints()]
m = [[] for _ in range(H+2)]
m[0] = [0 for _ in range(W+2)]
m[-1] = [0 for _ in range(W+2)]

for i in range(1, H+1):
    m[i].append(0)
    s = input()
    for j in s:
        m[i].append(j)
    m[i].append(0)

def oper(m):
    m_copy = copy.deepcopy(m)
    for i in range(1, W+1):
        for j in range(1, H+1):
            if m[j][i] == '#':
                m_copy[j][i] = '.'
            else:
                for k in range(i-1, i+2):
                    for l in range(j-1, j+2):
                        if m[l][k] == '#':
                            m_copy[j][i] = '#'
                            break
    return m_copy

before = copy.deepcopy(m)
while True:
    m = oper(oper(m))
    if m == before:
        break
    before = copy.deepcopy(m)

for i in m:
    for j in i:
        if j != 0:
            print(j, end=" ")
    print()