import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider, Button, RadioButtons

fig, ax = plt.subplots()
plt.subplots_adjust(left=0.25, bottom=0.25)
time = float (input("Enter Total Time ( in Seconds ) : "))
f0 = float (input("Enter Frequency ( in Hz ) : "))
plt.title (" SINE WAVE ")
t = np.linspace(0, time , 1000 , endpoint = True)
a0 = 5
# delta_f = 2.0
s = a0 * np.sin(2 * np.pi * f0 * t)
l, = plt.plot(t, s, lw=2)
plt.axhline (y=0 , color= 'k')
plt.grid (which= 'Both')
ax.margins(x=0)

axcolor = 'white'
axfreq = plt.axes([0.25, 0.1, 0.65, 0.03], facecolor=axcolor)
axamp = plt.axes([0.25, 0.15, 0.65, 0.03], facecolor=axcolor)

s_freq = Slider(axfreq, 'Freq', 0.2, 30.0, valinit = f0, valstep = f0)
s_amp = Slider(axamp, 'Amp', 0.2, 10.0, valinit=a0)


def update(val):
    amp = s_amp.val
    freq = s_freq.val
    l.set_ydata(amp*np.sin(2*np.pi*freq*t))
    fig.canvas.draw_idle()


s_freq.on_changed(update)
s_amp.on_changed(update)

resetax = plt.axes([0.8, 0.025, 0.1, 0.04])
button = Button(resetax, 'Reset', color=axcolor, hovercolor='yellow')


def reset(event):
    s_freq.reset()
    s_amp.reset()
button.on_clicked(reset)

color_button = plt.axes([0.025, 0.5, 0.15, 0.15], facecolor=axcolor)
radio = RadioButtons(color_button , ('red', 'blue', 'gold'), active=0)


def colorfunc(label):
    l.set_color(label)
    fig.canvas.draw_idle()
radio.on_clicked(colorfunc)

# Initialize plot with correct initial active value
colorfunc(radio.value_selected)


plt.show()