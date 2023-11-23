











```python
fig, ax = plt.subplots()
plt.plot()
plt.bar()
plt.scatter()
ax.hist()  //  plt.hist()
plt.barh

#使用主题
plt.style.use()

# 是用来从 Matplotlib Axes 对象 (ax) 中获取 x 轴刻度标签的操作
labels = ax.get_xticklabels()

# Set one or more properties on an Artist, or list allowed values. 用于一次性批量设置多个属性
matplotlib.pyplot.setp(obj, *args, **kwargs)

#  方法用于设置坐标轴的属性，例如标题、标签、刻度范围等。这个方法允许你在特定的 Axes 对象上设置多个属性
matplotlib.axes.Axes.set(**kwargs) 

#  the form (row, column), the figsize keyword argument follows the form (width, height)
fig, ax = plt.subplots(figsize=(8, 4))

#  For labels, we can specify custom formatting guidelines in the form of functions. 
ax.xaxis.set_major_formatter(@function)
#For this function, the x argument is the original tick label and pos is the tick position. We will only use x here but both arguments are needed.

# Add a vertical line, here we set the style in the function call
ax.axvline(group_mean, ls='--', color='r')

#是用于调整 Matplotlib 图形的子图布局的方法。具体来说，这行代码的作用是调整子图的右边界，以便在图形中留出一定的空白空间。
fig.subplots_adjust(right=.1)
```

We can then use the [`figure.Figure.savefig()`](https://matplotlib.org/stable/api/figure_api.html#matplotlib.figure.Figure.savefig) in order to save the figure to disk. Note that there are several useful flags we show below:

- `transparent=True` makes the background of the saved figure transparent if the format supports it.
- `dpi=80` controls the resolution (dots per square inch) of the output.
- `bbox_inches="tight"` fits the bounds of the figure to our plot.