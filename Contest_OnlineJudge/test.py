import numpy as np
import matplotlib.pyplot as plt

def sine_wave(amplitude, phase):
  phase_radian = (phase * np.pi/180)
  x = np.linspace(start = -100, stop = 100, num = 100)
  y = amplitude * np.sin(2 * np.pi * x + phase_radian) 
  plt.title(f'Sine Wave: A({amplitude}), P({phase} Degree)')
  plt.grid(True, which='both')
  plt.axhline(color='r')
  plt.axvline(color='r')
  plt.plot(x,y)
  plt.show()

sine_wave(amplitude=2, phase=90)