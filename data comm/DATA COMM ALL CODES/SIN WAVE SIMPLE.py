
import matplotlib.pyplot as plot
import numpy as np
time = float (input("Enter Total Time ( in Seconds ) : "))
freq = float (input("Enter Frequency ( in Hz ) : "))

# Sampling rate 1000 hz / second
t = np.linspace(0, time , 1000 , endpoint=True)

# Plot the sin wave signal
plot.plot(t, np.sin(2 * np.pi * freq * t))

# Give a title for the sin wave plot
plot.title(' SIN WAVE ')

# Give x axis label for the sin wave plot
plot.xlabel(' TIME ')

# Give y axis label for the sin wave plot
plot.ylabel(' AMPLITUDE ')

plot.grid(True, which='both')

# Provide x axis and line color
plot.axhline(y=0, color='k')

# Set the max and min values for y axis
plot.ylim(-1.5, 1.5)
plot.xlim( 0, time )

# Display the square wave drawn
plot.show()


