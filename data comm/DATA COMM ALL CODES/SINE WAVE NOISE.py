import matplotlib.pyplot as plt
import numpy as np

time = float (input("Enter Total Time ( in Seconds ) : "))
freq = float (input("Enter Frequency ( in Hz ) : "))

# Sampling rate 1000 hz / second
t = np.linspace(0, time , 1000 , endpoint = True)
y = np.sin(2 * np.pi * freq * t)
noise = np.random.rand(len(y))
corrupt = y + noise


plt.subplot (3,1,1)
plt.title (" SINE WAVE ")
plt.plot (t,y)
plt.grid (which= "Both")
plt.axhline(y=0, color='k')

plt.subplot (3,1,2)
plt.title (" NOISE ")
plt.plot(t,noise)
plt.grid (which= "Both")
plt.axhline(y=0, color='k')

plt.subplot (3,1,3)
plt.title (" NOISY SIGNAL ")
plt.plot (t,corrupt)
plt.grid (which= "Both")
plt.axhline(y=0, color='k')

plt.tight_layout()
plt.show()