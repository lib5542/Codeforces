s = input()

A = s.split("?")[0]
BC = s.split("?")[1]

B = BC.split(":")[0]
C = BC.split(":")[1]

if A != "0":
    print(B+"paca")
else:
    print(C+"paca")