# Artist tutorial

the `Artist` handles all the high level constructs like representing and laying out the figure, text, and lines.

There are two types of `Artists`: primitives and containers. 

The primitives represent the standard graphical objects we want to paint onto our canvas: [`Line2D`](https://matplotlib.org/stable/api/_as_gen/matplotlib.lines.Line2D.html#matplotlib.lines.Line2D), [`Rectangle`](https://matplotlib.org/stable/api/_as_gen/matplotlib.patches.Rectangle.html#matplotlib.patches.Rectangle), [`Text`](https://matplotlib.org/stable/api/text_api.html#matplotlib.text.Text), [`AxesImage`](https://matplotlib.org/stable/api/image_api.html#matplotlib.image.AxesImage), etc., and the containers are places to put them ([`Axis`](https://matplotlib.org/stable/api/axis_api.html#matplotlib.axis.Axis), [`Axes`](https://matplotlib.org/stable/api/_as_gen/matplotlib.axes.Axes.html#matplotlib.axes.Axes) and [`Figure`](https://matplotlib.org/stable/api/figure_api.html#matplotlib.figure.Figure)). 

As we will discuss below, this is not necessary -- you can work directly with PostScript, PDF Gtk+, or wxPython `FigureCanvas` instances, instantiate your `Figures` directly and connect them yourselves

```python
import matplotlib.pyplot as plt
fig = plt.figure()
ax = fig.add_subplot(2, 1, 1) # two rows, one column, first plot
```

 If you want to create an `Axes` at an arbitrary location, simply use the [`add_axes()`](https://matplotlib.org/stable/api/figure_api.html#matplotlib.figure.Figure.add_axes) method which takes a list of `[left, bottom, width, height]` values in 0-1 relative figure coordinates:

```python
fig2 = plt.figure()
ax2 = fig2.add_axes([0.15, 0.1, 0.7, 0.3])
```



**plt.plot()**

Returns:

- list of[`Line2D`](https://matplotlib.org/stable/api/_as_gen/matplotlib.lines.Line2D.html#matplotlib.lines.Line2D)

  A list of lines representing the plotted data.

```python
import numpy as np
t = np.arange(0.0, 1.0, 0.01)
s = np.sin(2*np.pi*t)
line, = ax.plot(t, s, color='blue', lw=2)
```

You can remove a line later by calling its `remove` method:

```python
line = ax.lines[0]
line.remove()
```

```python
import numpy as np
import matplotlib.pyplot as plt

fig = plt.figure()
fig.subplots_adjust(top=0.8)
ax1 = fig.add_subplot(211)
ax1.set_ylabel('Voltage [V]')
ax1.set_title('A sine wave')

t = np.arange(0.0, 1.0, 0.01)
s = np.sin(2*np.pi*t)
line, = ax1.plot(t, s, color='blue', lw=2)

# Fixing random state for reproducibility
np.random.seed(19680801)

ax2 = fig.add_axes([0.15, 0.1, 0.7, 0.3])
n, bins, patches = ax2.hist(np.random.randn(1000), 50,
                            facecolor='yellow', edgecolor='yellow')
ax2.set_xlabel('Time [s]')

plt.show()
```



### Customizing your objects

###  <img src="Artist tutorial.assets/image-20230903105019272.png" alt="image-20230903105019272" style="zoom:67%;" />

If you want to set a number of properties at once, you can also use the method `set`

```python
o.set(alpha=0.5, zorder=2)
```

1. **`set` 方法**：
   - `set` 方法是针对单个对象的，用于设置特定对象的属性。您需要明确指定要设置的对象以及要设置的属性名称和值。
   - 通常，`set` 方法是在创建对象时使用的，例如在创建图表元素时设置其属性。
2. **`setp` 函数**：
   - `setp` 函数是用于批量设置多个对象的属性的工具函数。它可以接受一个对象列表或一个包含多个对象的容器，然后设置它们的共同属性。
   - `setp` 的主要用途是批量设置多个对象的属性，通常用于修改已经存在的对象的属性。

## Figure container

<img src="Artist tutorial.assets/image-20230903110433759.png" alt="image-20230903110433759" style="zoom:67%;" />

`fig.add_subplot` 和 `fig.add_axes` 都是在 Matplotlib 中用于创建子图或坐标轴的方法，但它们之间有一些重要的区别：

1. **返回对象类型**:
   - `fig.add_subplot` 返回一个 `Axes` 对象，它表示一个子图（一个坐标轴）。
   - `fig.add_axes` 返回一个 `Axes` 对象，但允许您指定子图的位置和大小。
2. **使用方式**:
   - `fig.add_subplot` 通常用于创建规则的子图网格，例如多行多列的子图布局。您可以指定子图的行数、列数以及子图的索引位置，Matplotlib 会自动管理它们的位置和大小。
   - `fig.add_axes` 用于创建自定义位置和大小的子图，您需要手动指定子图的位置和大小。



## Axes container

It contains a **`Patch`** which is a [`Rectangle`](https://matplotlib.org/stable/api/_as_gen/matplotlib.patches.Rectangle.html#matplotlib.patches.Rectangle) for Cartesian coordinates and a [`Circle`](https://matplotlib.org/stable/api/_as_gen/matplotlib.patches.Circle.html#matplotlib.patches.Circle) for polar coordinates; this patch determines the shape, background and border of the plotting region:`Artists``Artists``Artists``patch`

> A patch is a 2D artist with a **face color** and an **edge color**.
>

You can, nonetheless, create objects yourself and add them directly to the using helper methods like [`add_line`](https://matplotlib.org/stable/api/_as_gen/matplotlib.axes.Axes.add_line.html#matplotlib.axes.Axes.add_line) and [`add_patch`](https://matplotlib.org/stable/api/_as_gen/matplotlib.axes.Axes.add_patch.html#matplotlib.axes.Axes.add_patch). Here is an annotated interactive session illustrating what is going on:`Axes`

```python
fig, ax = plt.subplots()

# create a rectangle instance
rect = matplotlib.patches.Rectangle((1, 1), width=5, height=12)

# by default the axes instance is None
print(rect.axes)
None

# and the transformation instance is set to the "identity transform"
print(rect.get_data_transform())
IdentityTransform()

# now we add the Rectangle to the Axes
ax.add_patch(rect)

# and notice that the ax.add_patch method has set the axes
# instance
print(rect.axes)
Axes(0.125,0.1;0.775x0.8)
```



<img src="Artist tutorial.assets/image-20230903111523233.png" alt="image-20230903111523233" style="zoom: 80%;" />

In addition to all of these , the contains two important containers: the [`XAxis`](https://matplotlib.org/stable/api/axis_api.html#matplotlib.axis.XAxis) and [`YAxis`](https://matplotlib.org/stable/api/axis_api.html#matplotlib.axis.YAxis)  which handle the drawing of the ticks and labels:

<img src="Artist tutorial.assets/image-20230903111820437.png" alt="image-20230903111820437" style="zoom:80%;" />





## Axis containers

The [`matplotlib.axis.Axis`](https://matplotlib.org/stable/api/axis_api.html#matplotlib.axis.Axis) instances handle the drawing of the **tick lines, the grid lines, the tick labels and the axis label**.

Here is a summary of some of the useful accessor methods of the `Axis` (these have corresponding setters where useful, such as [`set_major_formatter()`](https://matplotlib.org/stable/api/_as_gen/matplotlib.axis.Axis.set_major_formatter.html#matplotlib.axis.Axis.set_major_formatter).)

<img src="Artist tutorial.assets/image-20230903112857200.png" alt="image-20230903112857200" style="zoom:80%;" />

```python
# plt.figure creates a matplotlib.figure.Figure instance
fig = plt.figure()
rect = fig.patch  # a rectangle instance
rect.set_facecolor('lightgoldenrodyellow')

ax1 = fig.add_axes([0.1, 0.3, 0.4, 0.4])
rect = ax1.patch
rect.set_facecolor('lightslategray')


for label in ax1.xaxis.get_ticklabels():
    # label is a Text instance
    label.set_color('red')
    label.set_rotation(45)
    label.set_fontsize(16)

for line in ax1.yaxis.get_ticklines():
    # line is a Line2D instance
    line.set_color('green')
    line.set_markersize(25)
    line.set_markeredgewidth(3)

plt.show()
```

### Tick containers

The [`matplotlib.axis.Tick`](https://matplotlib.org/stable/api/axis_api.html#matplotlib.axis.Tick) is the final container object in our descent from the [`Figure`](https://matplotlib.org/stable/api/figure_api.html#matplotlib.figure.Figure) to the [`Axes`](https://matplotlib.org/stable/api/_as_gen/matplotlib.axes.Axes.html#matplotlib.axes.Axes) to the [`Axis`](https://matplotlib.org/stable/api/axis_api.html#matplotlib.axis.Axis) to the [`Tick`](https://matplotlib.org/stable/api/axis_api.html#matplotlib.axis.Tick). The `Tick` contains the tick and grid line instances, as well as the label instances for the upper and lower ticks. Each of these is accessible directly as an attribute of the `Tick`.



