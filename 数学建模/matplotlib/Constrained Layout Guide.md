# Constrained Layout Guide

How to use constrained-layout to fit plots within your figure cleanly.

*constrained_layout* automatically adjusts subplots and decorations like legends and colorbars so that they fit in the figure window while still preserving, as best they can, the logical layout requested by the user.

*constrained_layout* is similar to [tight_layout](https://matplotlib.org/stable/tutorials/intermediate/tight_layout_guide.html), but uses a constraint solver to determine the size of axes that allows them to fit.

- sing the respective argument to [`subplots()`](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.subplots.html#matplotlib.pyplot.subplots) or [`figure()`](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.figure.html#matplotlib.pyplot.figure), e.g.:

  ```
  plt.subplots(layout="constrained")
  ```

  

- activate it via [rcParams](https://matplotlib.org/stable/tutorials/introductory/customizing.html#customizing-with-dynamic-rc-settings), like:

  ```
  plt.rcParams['figure.constrained_layout.use'] = True
  ```

------

# Tight Layout guide

How to use tight-layout to fit plots within your figure cleanly.

*tight_layout* automatically adjusts subplot params so that the subplot(s) fits in to the figure area. This is an experimental feature and may not work for some cases. It only checks the extents of ticklabels, axis labels, and titles.







在 Matplotlib 中，`tight_layout` 和 `constrained_layout` 都是用于自动调整子图布局的方法，但它们的行为和应用场景有一些区别：

1. **`tight_layout`**

   ：

   - `tight_layout` 是 Matplotlib 中的一个函数，通常在创建图形时调用。
   - 它的主要目的是调整子图的位置和大小，以确保它们适合在图形中紧密排列，以最大程度地减少重叠和裁切。
   - `tight_layout` 通常用于简单的图形，例如单个图或较少数量的子图，并且不涉及复杂的布局需求。
   - 使用 `plt.tight_layout()` 来调用。

2. **`constrained_layout`**：

- `constrained_layout` 是 Matplotlib 中的一个布局管理器，通常在创建图形时启用。
- 它的主要目的是自动调整子图的位置和大小，以确保它们适合在图形中，同时考虑坐标轴标签、标题等元素的位置，以确保它们不重叠。
- `constrained_layout` 更适合复杂的图形，特别是当子图之间有多个共享坐标轴或复杂的布局需求时。
- 使用 `fig.set_constrained_layout(True)` 或在创建 Figure 时传入 `constrained_layout=True` 来启用它