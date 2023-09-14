# Customizing Matplotlib with style sheets and rcParams

There are three ways to customize Matplotlib:

1. [Setting rcParams at runtime](https://matplotlib.org/stable/tutorials/introductory/customizing.html#customizing-with-dynamic-rc-settings).
2. [Using style sheets](https://matplotlib.org/stable/tutorials/introductory/customizing.html#customizing-with-style-sheets).
3. [Changing your matplotlibrc file](https://matplotlib.org/stable/tutorials/introductory/customizing.html#customizing-with-matplotlibrc-files).

## Runtime rc settings

We can change the rc(runtime configuration) settings dynamically. All rc settings are stored in a dictionary-like variable.

```python
import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl
from cycler import cycler
mpl.rcParams['lines.linewidth'] = 2
mpl.rcParams['lines.linestyle'] = '--'
data = np.random.randn(50)
plt.plot(data)
```

## Temporary rc settings

The [`matplotlib.rcParams`](https://matplotlib.org/stable/api/matplotlib_configuration_api.html#matplotlib.rcParams) object can also be changed temporarily using the [`matplotlib.rc_context`](https://matplotlib.org/stable/api/matplotlib_configuration_api.html#matplotlib.rc_context) context manager:

```python
with mpl.rc_context({'lines.linewidth': 2, 'lines.linestyle': ':'}):
    plt.plot(data)
```

## Using style sheets

Another way to change the visual appearance of plots is to set the rcParams in a so-called style sheet and import that style sheet with [`matplotlib.style.use`](https://matplotlib.org/stable/api/style_api.html#matplotlib.style.use).

```python
plt.style.use('ggplot')
```

## Defining your own style

You can create custom styles and use them by calling [`style.use`](https://matplotlib.org/stable/api/style_api.html#matplotlib.style.use) with the path or URL to the style sheet.

For example, you might want to create `./images/presentation.mplstyle` with the following:

```
axes.titlesize : 24
axes.labelsize : 20
lines.linewidth : 3
lines.markersize : 10
xtick.labelsize : 16
ytick.labelsize : 16
```

Then, when you want to adapt a plot designed for a paper to one that looks good in a presentation, you can just add:

```
>>> import matplotlib.pyplot as plt
>>> plt.style.use('./images/presentation.mplstyle')
```

















