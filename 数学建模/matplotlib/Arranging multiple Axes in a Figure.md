## Overview

### Create grid-shaped combinations of Axes

- [`subplots`](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.subplots.html#matplotlib.pyplot.subplots)

  The primary function used to create figures and a grid of Axes. It creates and places all Axes on the figure at once, and returns an object array with handles for the Axes in the grid. See [`Figure.subplots`](https://matplotlib.org/stable/api/figure_api.html#matplotlib.figure.Figure.subplots).

or

- [`subplot_mosaic`](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.subplot_mosaic.html#matplotlib.pyplot.subplot_mosaic)

  A simple way to create figures and a grid of Axes, with the added flexibility that Axes can also span rows or columns. The Axes are returned in a labelled dictionary instead of an array. See also [`Figure.subplot_mosaic`](https://matplotlib.org/stable/api/figure_api.html#matplotlib.figure.Figure.subplot_mosaic) and [Complex and semantic figure composition (subplot_mosaic)](https://matplotlib.org/stable/gallery/subplots_axes_and_figures/mosaic.html).

Sometimes it is natural to have more than one distinct group of Axes grids, in which case Matplotlib has the concept of [`SubFigure`](https://matplotlib.org/stable/api/figure_api.html#matplotlib.figure.SubFigure):

- [`SubFigure`](https://matplotlib.org/stable/api/figure_api.html#matplotlib.figure.SubFigure)

  A virtual figure within a figure.

### Underlying tools

Underlying these are the concept of a [`GridSpec`](https://matplotlib.org/stable/api/_as_gen/matplotlib.gridspec.GridSpec.html#matplotlib.gridspec.GridSpec) and a [`SubplotSpec`](https://matplotlib.org/stable/api/_as_gen/matplotlib.gridspec.SubplotSpec.html#matplotlib.gridspec.SubplotSpec):

- [`GridSpec`](https://matplotlib.org/stable/api/_as_gen/matplotlib.gridspec.GridSpec.html#matplotlib.gridspec.GridSpec)

  Specifies the geometry of the grid that a subplot will be placed. The number of rows and number of columns of the grid need to be set. Optionally, the subplot layout parameters (e.g., left, right, etc.) can be tuned.

- [`SubplotSpec`](https://matplotlib.org/stable/api/_as_gen/matplotlib.gridspec.SubplotSpec.html#matplotlib.gridspec.SubplotSpec)

  Specifies the location of the subplot in the given [`GridSpec`](https://matplotlib.org/stable/api/_as_gen/matplotlib.gridspec.GridSpec.html#matplotlib.gridspec.GridSpec).

### Adding single Axes at a time

The above functions create all Axes in a single function call. It is also possible to add Axes one at a time, and this was originally how Matplotlib used to work. Doing so is generally less elegant and flexible, though sometimes useful for interactive work or to place an Axes in a custom location:

- [`add_axes`](https://matplotlib.org/stable/api/figure_api.html#matplotlib.figure.Figure.add_axes)

  Adds a single axes at a location specified by `[left, bottom, width, height]` in fractions of figure width or height.

- [`subplot`](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.subplot.html#matplotlib.pyplot.subplot) or [`Figure.add_subplot`](https://matplotlib.org/stable/api/figure_api.html#matplotlib.figure.Figure.add_subplot)

  Adds a single subplot on a figure, with 1-based indexing (inherited from Matlab). Columns and rows can be spanned by specifying a range of grid cells.

- [`subplot2grid`](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.subplot2grid.html#matplotlib.pyplot.subplot2grid)

  Similar to [`pyplot.subplot`](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.subplot.html#matplotlib.pyplot.subplot), but uses 0-based indexing and two-d python slicing to choose cells.