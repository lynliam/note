# Mathematica Learn

运行的快捷键是  `Shift + Enter`

使用 `?` + `想知道的函数` ，可以获得该函数的使用文档

Mathematica 中的函数  使用 中括号 `[]` ，小括号`()` 代表数学中的优先级运算。

其中以大写字母开头的是 内置函数 或者 常量，例如：

```mathematica
Pi   圆周率
E    自然常数
Sin[Pi/2]
```

> * 化简   `//Simplify`
> * 假设   `Simplify[expr, Assumptions->{}]`
> * 因式分解   `//Factor`

> ## 逻辑运算
>
> * 与  &&
> * 或  ||
> * 非 
> * `If[t>1 && t>2 , 4 , -2]`

> ## 代数运算
>
> * 解方程： `Solve[expr,vars]， Solve[expr,vars,dom]`
> * 求偏导：  
>   * `D[f,x]` 给出偏导数
>   * `D[f,{x,n}]` 给出高阶导数
>   * `D[f,x,y,...] `给出偏导数
>   * `D[f,{x,n},{y,m},...]` 给出高阶偏导数
> * 求积分：
>   * `Integrate[f,x]`  给出不定积分
>   * `Integrate[f,{x,x_min,x_max}]`  定积分
>   * `Integrate[f,{x,x_min,x_max},{y,y_min,y_max},...]`   多重积分
> * 求级数：
>   * Series[f,{x,x_0,n}]
> * 求极限：
>   * `Limit[Sin(x),x->0]`
> * 编写函数：
>   * `f[t_] := t^2-t`

> ## 列表、矩阵运算
>
> * 生成列表： `Table[]`
>
> ```mathematica
> f[a_, b_] := Sin[a/b*Pi]
> 
> B = Table[f[i + 1, j] + 2, {i, 1, 3}, {j, 1, 3}]
> ```
>
> * 列表的矩阵形式:   `//MatrixForm`
> * 矩阵获取：
>   * 矩阵某行某列：   `B[[1,1]]`
>   * 矩阵某列：           `B[[;;,3]]`
>   * 矩阵某行：           `B[[3，;;]]`
>   * 矩阵点乘：            `A.B`
>   * 求本征值：            `Eigenvalues[B]`
>   * 求本征向量：         `Eigenvectors[B]`
>   * 行列式：                 `Det[B]`
>   * 逆矩阵：                  `Inverse[B]//MatrixForm`
>   * 转置矩阵：               `Transpose[B]//MatrixForm`

> ## 替换
>
> - `ReplaceAll[test,c[_p]->p]`    等价于     `test./c[_p]->p`
> - `y[c,c,3,c,51,3]/.y[n__]->{n}`