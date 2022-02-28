
import random
inside=0
outside=0
x=[]
y=[]
for i in range(10000): # We do 10,000 trials
    x.append(random.random())
    y.append(random.random())
    pos=pow(x[i], 2)+pow(y[i], 2) # distance from origin
    if pos < 1:
        inside+=1
    else:
        outside+=1

probability=inside/(inside+outside)
print("The Estimated value of pi is: " + str(probability*4))

