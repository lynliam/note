# MicroPython 

### list 列表:

list 是一个**可变**的**有序表**，所以可以往 list 中追加元素到末尾：

```python
classmates.append('Adam')
classmates
['Michael', 'Bob', 'Tracy', 'Adam']
```

也可以把元素插入到指定的位置，比如索引号为1的位置：

```python
classmates.insert(1, 'Jack')
classmates
['Michael', 'Jack', 'Bob', 'Tracy', 'Adam']
```

要删除 list 末尾的元素, 用 pop() 方法：

```python
classmates.pop()
'Adam'
classmates
['Michael', 'Jack', 'Bob', 'Tracy']
```

要把某个元素替换成别的元素, 可以直接赋值给对应的索引位置:

```python
classmates[1] = 'Sarah'
classmates
['Michael', 'Sarah', 'Tracy']
```

list 里面的元素的数据类型也可以不同, 比如:

```python
L = ['Apple', 123, True]
```

如果一个 list 中一个元素也没有，就是一个空的 list，它的长度为 0：

```python
L = []
len(L)
0
```