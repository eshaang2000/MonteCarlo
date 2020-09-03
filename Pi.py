import math
import random
import matplotlib.pyplot as plt
x=[]
y=[]
inside=0
outside=0
for i in range(10000):
    # print(random.random())
    x.append(random.random())
    y.append(random.random())
    pos=pow(x[i], 2)+pow(y[i], 2)
    if pos < 1:
        # print("yeah")
        inside+=1
    else:
        outside+=1

    # print(pos)
# print(x)
# print(y)
area=inside/(inside+outside)
# print(area)
# print(inside)
# print(outside)
print(area*4)
plt.scatter(x, y)
plt.show()

