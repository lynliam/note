# Styling with cycler

Now we'll generate a figure with two axes, one on top of the other. On the first axis, we'll plot with the default cycler. On the second axis, we'll set the `prop_cycle` using [`matplotlib.axes.Axes.set_prop_cycle()`](https://matplotlib.org/stable/api/_as_gen/matplotlib.axes.Axes.set_prop_cycle.html#matplotlib.axes.Axes.set_prop_cycle), which will only set the `prop_cycle` for this [`matplotlib.axes.Axes`](https://matplotlib.org/stable/api/_as_gen/matplotlib.axes.Axes.html#matplotlib.axes.Axes) instance. We'll use a second `cycler` that combines a color cycler and a linewidth cycler.

```python
from cycler import cycler
import numpy as np
import matplotlib.pyplot as plt

custom_cycler = (cycler(color=['c', 'm', 'y', 'k']) +
                 cycler(lw=[1, 2, 3, 4]))

fig, (ax0, ax1) = plt.subplots(nrows=2)
ax0.plot(yy)
ax0.set_title('Set default color cycle to rgby')
ax1.set_prop_cycle(custom_cycler)
ax1.plot(yy)
ax1.set_title('Set axes color cycle to cmyk')

# Add a bit more space between the two plots.
fig.subplots_adjust(hspace=0.3)
plt.show()
```

