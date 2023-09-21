# Integration

## 1.0  General integration(`quad`)

```python
import scipy as sp
import numpy as np

integrate.quad(func,a,b,args=(),full_output=0,complex_func=False)
```

Parameters:

- **func**:   {function, scipy.LowLevelCallable}

  A Python function or method to integrate. If *func* takes many arguments, it is integrated along the axis corresponding to the first argument.If the user desires improved integration performance, then *f* may be a [`scipy.LowLevelCallable`](https://scipy.github.io/devdocs/reference/generated/scipy.LowLevelCallable.html#scipy.LowLevelCallable) with one of the signatures:

  ```python
  double func(double x) 
  double func(double x, void *user_data) 
  double func(int n, double *xx) 
  double func(int n, double *xx, void *user_data)
  ```

  The `user_data` is the data contained in the [`scipy.LowLevelCallable`](https://scipy.github.io/devdocs/reference/generated/scipy.LowLevelCallable.html#scipy.LowLevelCallable). In the call forms with `xx`, `n` is the length of the `xx` array which contains `xx[0] == x` and the rest of the items are numbers contained in the `args` argument of quad.In addition, certain ctypes call signatures are supported for backward compatibility, but those should not be used in new code.

- **a**:  float

  Lower limit of integration (use -numpy.inf for -infinity).

- **b**:  float

  Upper limit of integration (use numpy.inf for +infinity).

- **args**:   tuple, optional

  Extra arguments to pass to *func*.

- **full_output**:   int, optional

  Non-zero to return a dictionary of integration information. If non-zero, warning messages are also suppressed and the message is appended to the output tuple.

- **complex_func**:   bool, optional

  Indicate if the function’s (*func*) return type is real (`complex_func=False`: default) or complex (`complex_func=True`). In both cases, the function’s argument is real. If full_output is also non-zero, the *infodict*, *message*, and *explain* for the real and complex components are returned in a dictionary with keys “real output” and “imag output”.

 **`quad()`** function can accept a "callable" Python object(i.e. a function, method, or class instance)

### Example 

```python
import scipy as sp
import numpy as np 
def integrand(t,n,x):
    return np.exp(-x*t)/t**n
def expint(n,x):
    return sp.integrate.quad(integrand,1,np.inf,args=(n,x))[0]
vect_expint = np.vectorize(expint)
vect_expint(3,np.arange(1.0,4.0,0.5))
```

 Also,  `quad()` can handle the multiple integration.

```python
result = sp.integrate.quad(lambda x: expint(3,x),0,np.inf)
```

> ==-----Warning-----==
>
> 因为`quad()`函数是通过取样点来完成积分估计的
>
> Numerical integration algorithms sample the integrand at a finite number of points. Consequently, they cannot guarantee accurate results (or accuracy estimates) for arbitrary integrands and limits of integration. Consider the Gaussian integral, for example:

## General multiple integration ([`dblquad`](https://scipy.github.io/devdocs/reference/generated/scipy.integrate.dblquad.html#scipy.integrate.dblquad), [`tplquad`](https://scipy.github.io/devdocs/reference/generated/scipy.integrate.tplquad.html#scipy.integrate.tplquad), [`nquad`](https://scipy.github.io/devdocs/reference/generated/scipy.integrate.nquad.html#scipy.integrate.nquad))

The mechanics for double and triple integration have been wrapped up into the functions [`dblquad`](https://scipy.github.io/devdocs/reference/generated/scipy.integrate.dblquad.html#scipy.integrate.dblquad) and [`tplquad`](https://scipy.github.io/devdocs/reference/generated/scipy.integrate.tplquad.html#scipy.integrate.tplquad).The limits of all inner integrals need to be defined as functions.

* `dblquad()`
* `nquad()`
* `tplquad()`

```python
scipy.integrate.dblquad(func,a,b,gfun,hfun,args=())
```

Parameters:

- **`func`**:   callable

  A Python function or method of at least two variables: y must be the first argument and x the second argument.

- **`a, b`**:    float

  The limits of integration in x: *a* < *b*

- **`gfun`**:    callable or float

  The lower boundary curve in y which is a function taking a single floating point argument (x) and returning a floating point result or a float indicating a constant boundary curve.

- **`hfun`**:    callable or float

  The upper boundary curve in y (same requirements as *`gfun`*).

- **`args`**:    sequence, optional

  Extra arguments to pass to *`func`*.



```python
scipy.integrate.nquad(func,ranges,args=None,opts=None, full_output=False)
```

Wraps [`quad`](https://scipy.github.io/devdocs/reference/generated/scipy.integrate.quad.html#scipy.integrate.quad) to enable integration over multiple variables. The **order of integration** (and therefore the bounds) is from the innermost integral to the outermost one.



主要区别在于 `dblquad()` 用于处理二重积分，而 `nquad()` 更通用，可用于处理多重积分，包括高维积分。根据你的具体问题和积分区域的性质，你可以选择使用其中一个函数来计算数值积分。如果你需要处理高维积分问题，那么 `nquad()` 可能更适合你的需求。



## Gaussian quadrature(高斯求积)

高斯求积（Gaussian quadrature）是一种用于数值积分的数值方法，旨在通过选择合适的积分节点和权重系数，以高效地近似积分结果。这种方法的主要思想是选择一个合适的权重函数，以便将原始积分问题转化为一个更容易求解的问题。
$$
\int^{b}_{a}f(x)dx \approx \sum^{n}_{k=1}A_kf(x_k)
$$

* `fixed_quad(func,a,b,args=(),n=5)`   n 是指 选择的节点数量
* `quadrature(func,a,b,args=())`

`fixed_quad()` 主要用于处理简单的定积分问题，需要手动选择节点数目。而 `quadrature()` 是一个更通用的函数，可以用于处理更复杂的积分问题，无需手动指定节点数目，并且具有自适应性，能够提供更高精度的数值积分结果。选择使用哪个函数取决于你的具体需求和问题的复杂程度。



## Romberg Integration

Romberg integration of a callable function or method.  Returns the integral of *function* (a function of one variable) over the interval (*a*, *b*).

If the samples are **equally-spaced** and the number of samples available is for some integer , then Romberg [`romb`](https://scipy.github.io/devdocs/reference/generated/scipy.integrate.romb.html#scipy.integrate.romb) integration can be used to obtain high-precision estimates of the integral using the available samples.

```python
romberg(function, a, b, args=(), tol=1.48e-08, rtol=1.48e-08, show=False, divmax=10, vec_func=False)
```

Romberg 积分是一种用于数值积分的高精度方法，旨在逼近定积分的数值值。它基于 Richardson 外推方法，通过多次迭代和对不同步长的梯形规则积分的组合来逼近积分值，从而提高了积分的精度。Romberg 积分的主要思想是通过递推过程不断提高积分的精度，同时减小误差。

## Integrating using Samples

In case of arbitrary spaced samples, the two functions [`trapezoid`](https://scipy.github.io/devdocs/reference/generated/scipy.integrate.trapezoid.html#scipy.integrate.trapezoid) and [`simpson`](https://scipy.github.io/devdocs/reference/generated/scipy.integrate.simpson.html#scipy.integrate.simpson) are available.

For an odd number of samples that are equally spaced Simpson’s rule is exact if the function is a polynomial of order 3 or less. If the samples are not equally spaced, then the result is exact only if the function is a polynomial of order 2 or less.

```python
simpson(y, *, x=None, dx=1.0, axis=-1, even=<object object>)
```

If there are an even number of samples, N, then there are an odd number of intervals (N-1), but Simpson’s rule requires an even number of intervals. The parameter ‘even’ controls how this is handled.



## Ordinary differential equations ([`solve_ivp`](https://scipy.github.io/devdocs/reference/generated/scipy.integrate.solve_ivp.html#scipy.integrate.solve_ivp))























