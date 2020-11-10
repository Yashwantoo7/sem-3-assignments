import matplotlib.pyplot as plt
import numpy as np
import random as rd
from scipy import signal

def nrz_l (data) :
    data_nrz = []
    for i in data :
        x = None
        if i == 1 :
            x = -1
        else :
            x = +1
        data_nrz.append(x)
    data_nrz.append(1)
    # sets data rate 10 bps
    xs = np.repeat(range(len(data_nrz)) , 10)
    ys = np.repeat(data_nrz , 10)
    xs = xs[1:]
    ys = ys[:-1]
    plt.grid ()
    # plt.xlabel (str(data))
    plt.plot(xs , ys)
    plt.ylabel(" VOLTAGE LEVEL ")
    plt.ylim(-3, 3)
    plt.xlim(0 ,len(data_nrz))
    tick = []
    for i in range (0,len(data_nrz)) :
        tick.append(i)
    plt.xticks(tick)
    plt.axhline(y=0, color='k')
    plt.title (" NRZ - L  With Bit Sequence : "+str(data))
    plt.show()

def nrz_i (data) :
    data_nrz_i = []
    temp = True
    for i in range (len(data)) :
        x = None
        if data[i] == 1 and temp == True :
            x = -1
            temp = False
        elif data[i] == 1 and temp == False :
            x = 1
            temp = True
        elif data[i] == 0 and temp == False :
            x = -1
        elif data[i] == 0 and temp == True :
            x = 1
        data_nrz_i.append(x)
    if data_nrz_i[0] == 0 :
        data_nrz_i[0] = 1
    data_nrz_i.append(1)
    # sets data rate = 10 bps
    xs = np.repeat(range(len(data_nrz_i)), 10)
    ys = np.repeat(data_nrz_i, 10)
    xs = xs[1:]
    ys = ys[:-1]
    plt.grid()
    # plt.xlabel (str(data))
    plt.plot(xs, ys)
    plt.ylabel(" VOLTAGE LEVEL ")
    plt.ylim(-3, 3)
    plt.xlim(0, len(data_nrz_i))
    tick = []
    for i in range(0, len(data_nrz_i)):
        tick.append(i)
    plt.xticks(tick)
    plt.axhline(y=0, color='k')
    plt.title(" NRZ - I With Bit Sequence : " + str(data))
    plt.show()


data = eval(input(" Enter Bit Sequence : "))
print (" Which Plot U Want : ")
print (" 1) NRZ - L ")
print (" 2) NRZ - I ")
op = int (input(" Enter Option : "))
if op == 1 :
    nrz_l(data)
else :
    nrz_i(data)







