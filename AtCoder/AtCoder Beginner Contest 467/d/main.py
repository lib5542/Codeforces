T = int(input())
for i in range(T):


    Px, Py, Qx, Qy, Rx, Ry, Sx, Sy = map(int, input().split())

    if Px == Qx and Rx == Sx:
        if ((Py+Qy) == (Ry+Sy)):
            print("Yes")
        else:
            print("No")
    elif Px == Qx or Rx == Sx:
        print("Yes")
    else:
        if ((Py-Qy)*(Rx-Sx) != (Px-Qx)*(Ry-Sy)):
            print("Yes")
        else:
            PQx = (Px + Qx) / 2
            PQy = (Py + Qy) / 2

            RSx = (Rx + Sx) / 2
            RSy = (Ry + Sy) / 2

            if ((RSy-PQy) * (Py-Qy) == -(RSx-PQx) * (Px-Qx) and (RSy-PQy) * (Ry-Sy) == -(RSx-PQx) * (Rx-Sx)):
                print("Yes")
            else:
                print("No")