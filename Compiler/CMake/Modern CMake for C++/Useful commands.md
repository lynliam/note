# Useful commands

## The message() commads:

* FATAL_ERROR
* SEND_ERROR
* WARNING
* AUTHOR_WARNING
* DEPRECATION
* NOTICE
* STATUS
* VERBOSE
* DEBUG
* TRACE



## The include() command

We can partition our CMake code into separate files to keep things ordered and , well, separate.

```cmake
include(<file|module> [OPTIONAL] [RESULT_VARIABLE] <var>)
```

CMake will try to open and execute it.

 find in `CMAKE_MODULE_PATH`  with the name of `<module>.cmake`



## The include_fuard() command



## file() command

```cmake
file(READ <filename> <out-var>  [...])
```



