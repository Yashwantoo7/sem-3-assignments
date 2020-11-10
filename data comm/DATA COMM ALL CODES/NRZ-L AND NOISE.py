import matplotlib.pyplot as plt
import numpy as np

# bit sequence Enter The User
data = eval(input("Enter Bit Sequence : "))


# Generate NRZ - L signal
data_nrz = []
data_noise = []
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
plt.subplot (2,1,1)
plt.plot(xs , ys)
plt.ylabel (" VOLTAGE LEVEL ")
plt.grid(which='Both')
plt.ylim(-3, 3)
plt.xlim(0 ,len(data_nrz))
tick = []
for i in range (0,len(data_nrz)) :
    tick.append(i)
plt.xticks(tick)
plt.axhline(y=0, color='k')
plt.title (" NRZ - L  With Bit Sequence  :  "+str(data))


# Generate Noise And Add to the Signal
for a in data_nrz:
    noise = np.random.randn(len(ys))
    data_noise = ys + noise
xs1 = np.repeat(range(len(data_noise)), 10)
ys1 = np.repeat(data_noise, 10)
xs1 = xs1[1:]
ys1 = ys1[:-1]
plt.subplot(2, 1, 2)
plt.plot(xs1 , ys1)
plt.ylabel (" VOLTAGE LEVEL ")
plt.grid (which = 'Both')
plt.ylim(-3, 3)
plt.axhline(y=0, color='k')
plt.title(" NOISY SIGNAL FOR  :  " + str(data))

# Show the plot
plt.tight_layout()
plt.show()

