import numpy as np
import matplotlib.pyplot as plt

time = float (input("Enter Time period ( in Sec ) : "))
# Setup
x_ = np.linspace(0,time,10000)

T = 8
harmonics = 10
# func to form the square wave
def squareWave(x):
    global T
    lowerBoundLeft = (-T/2)
    lowerBoundRight = 0
    upperBoundLeft = 0
    upperBoundRight = (T/2)
    one = 1
    negativeOne = -1

    while True:
        if (x >= lowerBoundLeft) and (x <= lowerBoundRight):
            return negativeOne
        elif (x >= upperBoundLeft) and (x <= upperBoundRight):
            return one
        else:
            lowerBoundLeft -= T/2
            lowerBoundRight -= T/2
            upperBoundLeft += T/2
            upperBoundRight += T/2
            if one == 1:
                one = -1
                negativeOne = 1
            else:
                one = 1
                negativeOne = -1

# fourier coeff --> bn
def bn(n):
    n = int(n)
    if (n%2 != 0):
        return 4/(np.pi*n)
    else:
        return 0

# fourier coeff --> an
def an (n):
    global T
    an = (2*np.pi*n)/T
    return an

# Fourier Series function
def fourierSeries(n_max,x):
    a0 = 0
    partialSums = a0
    for n in range(1,n_max):
        try:
            partialSums = partialSums + bn(n)*np.sin(an(n)*x)
        except:
            print("pass")
            pass
    return partialSums

y = []
f = []
for i in x_:
    y.append(squareWave(i))
    f.append(fourierSeries(harmonics,i))

plt.grid( True , which='both')
plt.axhline (y=0 , color='k')
plt.plot(x_,y,color="blue", label="Square Wave Signal" ,)
plt.plot(x_,f,color="red" , label="Sin Waves Superposition")
plt.legend(loc = "upper right")
plt.ylim(-1.5,1.5)
plt.xlabel(" TIME ")
plt.ylabel(" AMPLITUDE ")
plt.title(" SQUARE WAVE APPROXIMATION OF MULTIPLE SIN WAVES ")
plt.legend()
plt.show()

