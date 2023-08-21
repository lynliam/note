```shell
(base) PS F:\Environment\library\eigen-3.4.0\build> cmake ..
-- Building for: NMake Makefiles
CMake Error at CMakeLists.txt:4 (project):
  Running

   'nmake' '-?'

  failed with:

   系统找不到指定的文件。


CMake Error: CMAKE_C_COMPILER not set, after EnableLanguage
CMake Error: CMAKE_CXX_COMPILER not set, after EnableLanguage
-- Configuring incomplete, errors occurred!
```

解决方法：

```shell
cmake .. -G "MinGW Makefiles"
```

