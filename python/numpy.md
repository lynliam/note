# Numpy

## matrix库

```python
#生成矩阵
numpy.asarray([1,2,3,4]).reshape(2,2)
```

## 向量，矩阵和多维数组

向量化计算可以对数据进行批量化处理，避免循环操作，加快计算速度。

`Numpy`数组是：

* 同质的
* 带数据类型的
* 固定长度的

### NumPy Array对象

```python
data = np.array([])
data.shape    #返回一个元组，第一个数表示数量，第二个数表示维度
data.dim      #返回维度大小
data.nbytes   #储存数据的字节数
data.dtype    #数组中元素的数据类型
data.size	  #元素总数
data.strides  #返回一个元组，第一个数代表一组数的字节数，第二个数代表偏移量
```

### 数据类型：

| dtype   | 变体                       |
| ------- | -------------------------- |
| int     | int8,int16,int32,int64     |
| uint    | uint8,uint16,uint32,uint64 |
| bool    | bool                       |
| float   | float 16-32-64-128         |
| complex | complex 64-128-256         |

 ```python
 np.array([1,2,3],dtype = np.int32)
 ```

#### 变换类型：

```python
np.array(data , dtype = np.float)
data.astype(np.int16)
```

默认 -1 的平方根不是**复数**，则直接求平方根的行为不合法

#### 访问虚部和实部：

```python
data.imag
data.real
```



### 内存中数组顺序：

* 按顺序逐行储存（**主序**）
* 逐列储存数据     （**列主序**）

这样可以通过改变strides属性来改变映射策略，形成新的视图，（视图相当于数组中的引用）。

### 创建数组

* 从其他数组对象中创建
  * 列表，元组，其他`ndarray`的实例
* 常数填充
  * `np.zeros`
  * `np.ones`
  * `np.full`
  * `data.fill`
* 增量序列填充
  * `np.arange`
  * `np.linspace`
* 等比数列
  * `np.logspace`
* `meshgrid`数组
  * `np.meshgrid `  来融合创建网格
* 创建未初始化的数组
  * `np.empty`
* 其他属性创建
  * `np.ones_like``np.zeros_like``np.full_like``np.empty_like`
* 矩阵数据
  * `np.identity`
  * `np.eye(dim,k=x)`
  * `np.diag()`

