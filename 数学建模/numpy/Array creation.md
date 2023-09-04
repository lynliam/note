# Array creation

1. Conversion from other Python structures (i.e. lists and tuples)
2. Intrinsic NumPy array creation functions (e.g. arange, ones, zeros, etc.)
3. Replicating, joining, or mutating existing arrays
4. Reading arrays from disk, either from standard or custom formats
5. Creating arrays from raw bytes through the use of strings or buffers
6. Use of special library functions (e.g., random)



> **`numpy.arange()`**
>
> **numpy.**arange([***start***,]***stop***, **[step**,]***dtype=None***,*, like=None)

### 2D array creation functions

* ```python
  np.eye(2)
  np.eye(3,5)
  ```

* ```python
  np.diag([1,2,3],1)
  np.diag([1,2,3])
  ```

* ```python
  np.vander()
  ```

### 3 - general ndarray creation functions

* ```python
  np.zeros((2,3))
  ```

* ```python
  np.ones((2,3,2))
  ```

