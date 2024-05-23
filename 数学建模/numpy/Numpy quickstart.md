# Numpy fundamentals

Numpy's array class is called ==ndarray==.

* ndarray.ndim
* ndarray.shape
* ndarray.size
* ndarray.dtype
* ndarray.itemsize      the size in bytes of each element of the array. 
* ndarray.data

## Distinction

```python
np.arange(0,2,0.3)   # the last param is the step
np.linspace(0,2,9)   # the last param is the number of this interval
```

* `np.zeros()`
* `np.ones()`
* `np.empty()`

## Basic Operations

* `+`
* `-`
* `*`           对应位置相乘
* `@`           矩阵乘法
* `.dot()`   矩阵乘法
* `/`
* `*=` and `+=` 



When operating with arrays of different types, the type of the resulting array corresponds to the more general or precise one (a behavior known as upcasting).     **类型提升**

* array.sum(axis=0)
* array.min(axis=1)
* array.max()
* array.cumsum(axis=1)

```python
#
axis=0   是指按照每一列   组成行
axis=1   是指按照每一行   组成列

```



## Universal Functions

> [`all`](https://numpy.org/doc/stable/reference/generated/numpy.all.html#numpy.all), [`any`](https://numpy.org/doc/stable/reference/generated/numpy.any.html#numpy.any), [`apply_along_axis`](https://numpy.org/doc/stable/reference/generated/numpy.apply_along_axis.html#numpy.apply_along_axis), [`argmax`](https://numpy.org/doc/stable/reference/generated/numpy.argmax.html#numpy.argmax), [`argmin`](https://numpy.org/doc/stable/reference/generated/numpy.argmin.html#numpy.argmin), [`argsort`](https://numpy.org/doc/stable/reference/generated/numpy.argsort.html#numpy.argsort), [`average`](https://numpy.org/doc/stable/reference/generated/numpy.average.html#numpy.average), [`bincount`](https://numpy.org/doc/stable/reference/generated/numpy.bincount.html#numpy.bincount), [`ceil`](https://numpy.org/doc/stable/reference/generated/numpy.ceil.html#numpy.ceil), [`clip`](https://numpy.org/doc/stable/reference/generated/numpy.clip.html#numpy.clip), [`conj`](https://numpy.org/doc/stable/reference/generated/numpy.conj.html#numpy.conj), [`corrcoef`](https://numpy.org/doc/stable/reference/generated/numpy.corrcoef.html#numpy.corrcoef), [`cov`](https://numpy.org/doc/stable/reference/generated/numpy.cov.html#numpy.cov), [`cross`](https://numpy.org/doc/stable/reference/generated/numpy.cross.html#numpy.cross), [`cumprod`](https://numpy.org/doc/stable/reference/generated/numpy.cumprod.html#numpy.cumprod), [`cumsum`](https://numpy.org/doc/stable/reference/generated/numpy.cumsum.html#numpy.cumsum), [`diff`](https://numpy.org/doc/stable/reference/generated/numpy.diff.html#numpy.diff), [`dot`](https://numpy.org/doc/stable/reference/generated/numpy.dot.html#numpy.dot), [`floor`](https://numpy.org/doc/stable/reference/generated/numpy.floor.html#numpy.floor), [`inner`](https://numpy.org/doc/stable/reference/generated/numpy.inner.html#numpy.inner), [`invert`](https://numpy.org/doc/stable/reference/generated/numpy.invert.html#numpy.invert), [`lexsort`](https://numpy.org/doc/stable/reference/generated/numpy.lexsort.html#numpy.lexsort), [`max`](https://numpy.org/doc/stable/reference/generated/numpy.max.html#numpy.max), [`maximum`](https://numpy.org/doc/stable/reference/generated/numpy.maximum.html#numpy.maximum), [`mean`](https://numpy.org/doc/stable/reference/generated/numpy.mean.html#numpy.mean), [`median`](https://numpy.org/doc/stable/reference/generated/numpy.median.html#numpy.median), [`min`](https://numpy.org/doc/stable/reference/generated/numpy.min.html#numpy.min), [`minimum`](https://numpy.org/doc/stable/reference/generated/numpy.minimum.html#numpy.minimum), [`nonzero`](https://numpy.org/doc/stable/reference/generated/numpy.nonzero.html#numpy.nonzero), [`outer`](https://numpy.org/doc/stable/reference/generated/numpy.outer.html#numpy.outer), [`prod`](https://numpy.org/doc/stable/reference/generated/numpy.prod.html#numpy.prod), [`re`](https://docs.python.org/3/library/re.html#module-re), [`round`](https://numpy.org/doc/stable/reference/generated/numpy.round.html#numpy.round), [`sort`](https://numpy.org/doc/stable/reference/generated/numpy.sort.html#numpy.sort), [`std`](https://numpy.org/doc/stable/reference/generated/numpy.std.html#numpy.std), [`sum`](https://numpy.org/doc/stable/reference/generated/numpy.sum.html#numpy.sum), [`trace`](https://numpy.org/doc/stable/reference/generated/numpy.trace.html#numpy.trace), [`transpose`](https://numpy.org/doc/stable/reference/generated/numpy.transpose.html#numpy.transpose), [`var`](https://numpy.org/doc/stable/reference/generated/numpy.var.html#numpy.var), [`vdot`](https://numpy.org/doc/stable/reference/generated/numpy.vdot.html#numpy.vdot), [`vectorize`](https://numpy.org/doc/stable/reference/generated/numpy.vectorize.html#numpy.vectorize), [`where`](https://numpy.org/doc/stable/reference/generated/numpy.where.html#numpy.where)

## Adding, removing, and sorting elements

```python
np.sort(arr)
np.concatenate((x,y),axis=0)   
#   np.concatenate() 是 NumPy 库中的一个函数，用于将两个或多个数组沿指定的轴连接在一起
```



## Indexing, Slicing and Iterating

**Multidimensional** arrays can have one index per axis.

```python
b
array([[ 0,  1,  2,  3],
       [10, 11, 12, 13],
       [20, 21, 22, 23],
       [30, 31, 32, 33],
       [40, 41, 42, 43]])
b[2, 3]
23
b[0:5, 1]  # each row in the second column of b
array([ 1, 11, 21, 31, 41])
b[:, 1]    # equivalent to the previous example
array([ 1, 11, 21, 31, 41])
b[1:3, :]  # each column in the second and third row of b
array([[10, 11, 12, 13],
       [20, 21, 22, 23]])
```

```python
b[-1]   # the last row. Equivalent to b[-1, :]
array([40, 41, 42, 43])
```

The **dots** (`...`) represent as many colons as needed to produce a complete indexing tuple. For example, if `x` is an array with 5 axes, then

- `x[1, 2, ...]` is equivalent to `x[1, 2, :, :, :]`,
- `x[..., 3]` to `x[:, :, :, :, 3]` and
- `x[4, ..., 5, :]` to `x[4, :, :, 5, :]`.

one can use the `flat` attribute which is an [iterator](https://docs.python.org/tutorial/classes.html#iterators) over all the elements of the array.

```python
for elements in b.flat:
    ...:     print(elements)
```



## Shape Manipulation

> `np.floor()`用于向下取整。它将输入的数字或数组中的每个元素都取下界，即将每个元素向下舍入到最接近的小于或等于它的整数。

* `arrary.ravel()`
* `array.reshape()`
* `array.resize()`
* `a.T`

The [`reshape`](https://numpy.org/doc/stable/reference/generated/numpy.reshape.html#numpy.reshape) function returns its argument with a modified shape, whereas the [`ndarray.resize`](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.resize.html#numpy.ndarray.resize) method modifies the array itself.

If a dimension is given as `-1` in a reshaping operation, the other dimensions are automatically calculated.



## Stacking together different arrays

* `np.vstack()`
* `np.hstack()`

The function [`column_stack`](https://numpy.org/doc/stable/reference/generated/numpy.column_stack.html#numpy.column_stack) stacks 1D arrays as columns into a 2D array. 

* ```
  np.column_stack((a, b))  # returns a 2D array
  ```



## Splitting one array into several smaller ones

Using [`hsplit`](https://numpy.org/doc/stable/reference/generated/numpy.hsplit.html#numpy.hsplit), you can split an array along its horizontal axis.

* `hsplit(a,3)`
* `vsplit(a,(3,4))`



## Copyies and Views

### No Copy at All

Python 中，**直接赋值**和**函数传参**都不会 进行复制

### View or Shallow Copy   影子复制

* `view()` 函数可以创建一个新的array,  但是这个array 的内容会随着 源数据 变动

```python
d = a.view()
d.base is a
>>> True
```



### Deep Copy

```python
d = a.copy()  # a new array object with new data is created
d is a
False
d.base is a  # d doesn't share anything with a
False
d[0, 0] = 9999
a
array([[   0,   10,   10,    3],
       [1234,   10,   10,    7],
       [   8,   10,   10,   11]])
```



The `copy` method makes a complete copy of the array and its data.

```python
a = np.arange(int(1e8))
b = a[:100].copy()
del a  # the memory of ``a`` can be released.
```



### Functions and Methods Overview

Here is a list of some useful NumPy functions and methods names ordered in categories. See [Routines](https://numpy.org/doc/stable/reference/routines.html#routines) for the full list.

- Array Creation

  [`arange`](https://numpy.org/doc/stable/reference/generated/numpy.arange.html#numpy.arange), [`array`](https://numpy.org/doc/stable/reference/generated/numpy.array.html#numpy.array), [`copy`](https://numpy.org/doc/stable/reference/generated/numpy.copy.html#numpy.copy), [`empty`](https://numpy.org/doc/stable/reference/generated/numpy.empty.html#numpy.empty), [`empty_like`](https://numpy.org/doc/stable/reference/generated/numpy.empty_like.html#numpy.empty_like), [`eye`](https://numpy.org/doc/stable/reference/generated/numpy.eye.html#numpy.eye), [`fromfile`](https://numpy.org/doc/stable/reference/generated/numpy.fromfile.html#numpy.fromfile), [`fromfunction`](https://numpy.org/doc/stable/reference/generated/numpy.fromfunction.html#numpy.fromfunction), [`identity`](https://numpy.org/doc/stable/reference/generated/numpy.identity.html#numpy.identity), [`linspace`](https://numpy.org/doc/stable/reference/generated/numpy.linspace.html#numpy.linspace), [`logspace`](https://numpy.org/doc/stable/reference/generated/numpy.logspace.html#numpy.logspace), [`mgrid`](https://numpy.org/doc/stable/reference/generated/numpy.mgrid.html#numpy.mgrid), [`ogrid`](https://numpy.org/doc/stable/reference/generated/numpy.ogrid.html#numpy.ogrid), [`ones`](https://numpy.org/doc/stable/reference/generated/numpy.ones.html#numpy.ones), [`ones_like`](https://numpy.org/doc/stable/reference/generated/numpy.ones_like.html#numpy.ones_like), [`r_`](https://numpy.org/doc/stable/reference/generated/numpy.r_.html#numpy.r_), [`zeros`](https://numpy.org/doc/stable/reference/generated/numpy.zeros.html#numpy.zeros), [`zeros_like`](https://numpy.org/doc/stable/reference/generated/numpy.zeros_like.html#numpy.zeros_like)

- Conversions

  [`ndarray.astype`](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.astype.html#numpy.ndarray.astype), [`atleast_1d`](https://numpy.org/doc/stable/reference/generated/numpy.atleast_1d.html#numpy.atleast_1d), [`atleast_2d`](https://numpy.org/doc/stable/reference/generated/numpy.atleast_2d.html#numpy.atleast_2d), [`atleast_3d`](https://numpy.org/doc/stable/reference/generated/numpy.atleast_3d.html#numpy.atleast_3d), [`mat`](https://numpy.org/doc/stable/reference/generated/numpy.mat.html#numpy.mat)

- Manipulations

  [`array_split`](https://numpy.org/doc/stable/reference/generated/numpy.array_split.html#numpy.array_split), [`column_stack`](https://numpy.org/doc/stable/reference/generated/numpy.column_stack.html#numpy.column_stack), [`concatenate`](https://numpy.org/doc/stable/reference/generated/numpy.concatenate.html#numpy.concatenate), [`diagonal`](https://numpy.org/doc/stable/reference/generated/numpy.diagonal.html#numpy.diagonal), [`dsplit`](https://numpy.org/doc/stable/reference/generated/numpy.dsplit.html#numpy.dsplit), [`dstack`](https://numpy.org/doc/stable/reference/generated/numpy.dstack.html#numpy.dstack), [`hsplit`](https://numpy.org/doc/stable/reference/generated/numpy.hsplit.html#numpy.hsplit), [`hstack`](https://numpy.org/doc/stable/reference/generated/numpy.hstack.html#numpy.hstack), [`ndarray.item`](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.item.html#numpy.ndarray.item), [`newaxis`](https://numpy.org/doc/stable/reference/constants.html#numpy.newaxis), [`ravel`](https://numpy.org/doc/stable/reference/generated/numpy.ravel.html#numpy.ravel), [`repeat`](https://numpy.org/doc/stable/reference/generated/numpy.repeat.html#numpy.repeat), [`reshape`](https://numpy.org/doc/stable/reference/generated/numpy.reshape.html#numpy.reshape), [`resize`](https://numpy.org/doc/stable/reference/generated/numpy.resize.html#numpy.resize), [`squeeze`](https://numpy.org/doc/stable/reference/generated/numpy.squeeze.html#numpy.squeeze), [`swapaxes`](https://numpy.org/doc/stable/reference/generated/numpy.swapaxes.html#numpy.swapaxes), [`take`](https://numpy.org/doc/stable/reference/generated/numpy.take.html#numpy.take), [`transpose`](https://numpy.org/doc/stable/reference/generated/numpy.transpose.html#numpy.transpose), [`vsplit`](https://numpy.org/doc/stable/reference/generated/numpy.vsplit.html#numpy.vsplit), [`vstack`](https://numpy.org/doc/stable/reference/generated/numpy.vstack.html#numpy.vstack)

- Questions

  [`all`](https://numpy.org/doc/stable/reference/generated/numpy.all.html#numpy.all), [`any`](https://numpy.org/doc/stable/reference/generated/numpy.any.html#numpy.any), [`nonzero`](https://numpy.org/doc/stable/reference/generated/numpy.nonzero.html#numpy.nonzero), [`where`](https://numpy.org/doc/stable/reference/generated/numpy.where.html#numpy.where)

- Ordering

  [`argmax`](https://numpy.org/doc/stable/reference/generated/numpy.argmax.html#numpy.argmax), [`argmin`](https://numpy.org/doc/stable/reference/generated/numpy.argmin.html#numpy.argmin), [`argsort`](https://numpy.org/doc/stable/reference/generated/numpy.argsort.html#numpy.argsort), [`max`](https://numpy.org/doc/stable/reference/generated/numpy.max.html#numpy.max), [`min`](https://numpy.org/doc/stable/reference/generated/numpy.min.html#numpy.min), [`ptp`](https://numpy.org/doc/stable/reference/generated/numpy.ptp.html#numpy.ptp), [`searchsorted`](https://numpy.org/doc/stable/reference/generated/numpy.searchsorted.html#numpy.searchsorted), [`sort`](https://numpy.org/doc/stable/reference/generated/numpy.sort.html#numpy.sort)

- Operations

  [`choose`](https://numpy.org/doc/stable/reference/generated/numpy.choose.html#numpy.choose), [`compress`](https://numpy.org/doc/stable/reference/generated/numpy.compress.html#numpy.compress), [`cumprod`](https://numpy.org/doc/stable/reference/generated/numpy.cumprod.html#numpy.cumprod), [`cumsum`](https://numpy.org/doc/stable/reference/generated/numpy.cumsum.html#numpy.cumsum), [`inner`](https://numpy.org/doc/stable/reference/generated/numpy.inner.html#numpy.inner), [`ndarray.fill`](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.fill.html#numpy.ndarray.fill), [`imag`](https://numpy.org/doc/stable/reference/generated/numpy.imag.html#numpy.imag), [`prod`](https://numpy.org/doc/stable/reference/generated/numpy.prod.html#numpy.prod), [`put`](https://numpy.org/doc/stable/reference/generated/numpy.put.html#numpy.put), [`putmask`](https://numpy.org/doc/stable/reference/generated/numpy.putmask.html#numpy.putmask), [`real`](https://numpy.org/doc/stable/reference/generated/numpy.real.html#numpy.real), [`sum`](https://numpy.org/doc/stable/reference/generated/numpy.sum.html#numpy.sum)

- Basic Statistics

  [`cov`](https://numpy.org/doc/stable/reference/generated/numpy.cov.html#numpy.cov), [`mean`](https://numpy.org/doc/stable/reference/generated/numpy.mean.html#numpy.mean), [`std`](https://numpy.org/doc/stable/reference/generated/numpy.std.html#numpy.std), [`var`](https://numpy.org/doc/stable/reference/generated/numpy.var.html#numpy.var)

- Basic Linear Algebra

  [`cross`](https://numpy.org/doc/stable/reference/generated/numpy.cross.html#numpy.cross), [`dot`](https://numpy.org/doc/stable/reference/generated/numpy.dot.html#numpy.dot), [`outer`](https://numpy.org/doc/stable/reference/generated/numpy.outer.html#numpy.outer), [`linalg.svd`](https://numpy.org/doc/stable/reference/generated/numpy.linalg.svd.html#numpy.linalg.svd), [`vdot`](https://numpy.org/doc/stable/reference/generated/numpy.vdot.html#numpy.vdot)



## Advanced indexing and index tricks

一个array数组可以作为索引，来生成新的`array`

```python
a = np.arange(12)**2  # the first 12 square numbers
i = np.array([1, 1, 3, 8, 5])  # an array of indices
a[i]  # the elements of `a` at the positions `i`
array([ 1,  1,  9, 64, 25])

j = np.array([[3, 4], [9, 7]])  # a bidimensional array of indices
a[j]  # the same shape as `j`
array([[ 9, 16],
       [81, 49]])
```

两个维度相同的数组来索引不同的维度

```python
a = np.arange(12).reshape(3, 4)
a
array([[ 0,  1,  2,  3],
       [ 4,  5,  6,  7],
       [ 8,  9, 10, 11]])
i = np.array([[0, 1],  # indices for the first dim of `a`
              [1, 2]])
j = np.array([[2, 1],  # indices for the second dim
              [3, 3]])

a[i, j]  # i and j must have equal shape
#or
a[(i,j)]
array([[ 2,  5],
       [ 7, 11]])

a[i, 2]
array([[ 2,  6],
       [ 6, 10]])

a[:, j]
array([[[ 2,  1],
        [ 3,  3]],

       [[ 6,  5],
        [ 7,  7]],

       [[10,  9],
        [11, 11]]])
```

 To get the max index:

```python
data.argmax()
```



## Indexing with Boolean Arrays

 With boolean indices the approach is different; we explicitly choose which items in the array we want and which ones we don’t.

可以用比较的方式生成Boolen 数组。



## Tricks and Tips

To change the dimensions of an array, you can omit one of the sizes which will then be deduced automatically:

```python
a = np.arange(30)
b = a.reshape((2, -1, 3))  # -1 means "whatever is needed"
b.shape
(2, 5, 3)
```



Vector Stacking



## Reading the example code

```python
a = np.arange(6)
a2 = a[np.newaxis, :]
a2.shape
(1, 6)
```





























