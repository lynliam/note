# The lifecycle of a Plot

Most of the terms are straightforward but the main thing to remember is that:

- The [`Figure`](https://matplotlib.org/stable/api/figure_api.html#matplotlib.figure.Figure) is the final image, and may contain one or more [`Axes`](https://matplotlib.org/stable/api/_as_gen/matplotlib.axes.Axes.html#matplotlib.axes.Axes).

- The [`Axes`](https://matplotlib.org/stable/api/_as_gen/matplotlib.axes.Axes.html#matplotlib.axes.Axes) represents an individual plot (not to be confused with

  [`Axis`](https://matplotlib.org/stable/api/axis_api.html#matplotlib.axis.Axis), which refers to the x-, y-, or z-axis of a plot).

