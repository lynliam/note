# `Setuptools`, one official project for the `Setuptools` build system

## 1. Package Discovery 

### 1.0 Default

如果该文件在与`setup.py`同目录下，则可以使用：

```python
setup(
    # ...
    packages=['mypkg', 'mypkg.subpkg1', 'mypkg.subpkg2']
)
```

如果包位置不在root， 则需要 configure `package_dir`

```python
setup(
    # ...
    package_dir = {"": "src"}
    # directory containing all the packages (e.g.  src/mypkg, src/mypkg/subpkg1, ...)
)

# OR

setup(
    # ...
    package_dir = {
        "mypkg": "lib",  # mypkg.module corresponds to lib/module.py
        "mypkg.subpkg1": "lib1",  # mypkg.subpkg1.module1 corresponds to lib1/module1.py
        "mypkg.subpkg2": "lib2"   # mypkg.subpkg2.module2 corresponds to lib2/module2.py
        # ...
    }
)
```

### 1.1 Custom discovery

使用头文件：

```python
from setuptools import find_packages
# or
from setuptools import find_namespace_packages
```

#### Finding simple packages

```shell
mypkg
├── pyproject.toml  # AND/OR setup.cfg, setup.py
└── src
    ├── pkg1
    │   └── __init__.py
    ├── pkg2
    │   └── __init__.py
    ├── additional
    │   └── __init__.py
    └── pkg
        └── namespace
            └── __init__.py
```

To have setuptools to automatically include packages found in `src` that start with the name `pkg` and not `additional`:

```python
setup(
    # ...
    packages=find_packages(
        where='src',
        include=['pkg*'],  # alternatively: `exclude=['additional*']`
    ),
    package_dir={"": "src"}
    # ...
)
```



#### Find `namespace` packages

`setuptools` provides `find_namespace:` (`find_namespace_packages()`) which behaves similarly to `find:` but works with namespace packages.

```python
setup(
    # ...
    packages=find_namespace_packages(where='src'),
    package_dir={"": "src"}
    # ...
)
```



## 2. Dependencies Management 

### 2.0 Declaring required dependency



```python
setup(
    ...,
    install_requires=[
        "enum34;python_version<'3.4'",
    ],
)
```

```python
setup(
    ...,
    install_requires=[
        "enum34;python_version<'3.4'",
        "pywin32 >= 1.0;platform_system=='Windows'",
    ],
)
```

### 2.1 Optional dependencies

```python
setup(
    name="Package-A",
    ...,
    extras_require={
        "PDF": ["ReportLab>=1.2", "RXP"],
    },
)
```



## 3. Entry Points

Entry points are a type of `metadata` that can be exposed by packages on installation.

1. The package would like to provide commands to be run at the terminal. 
2. A package would like to enable customization of its functionalities via *plugins*.

#### Console Scripts

```python
from setuptools import setup

setup(
    # ...,
    entry_points={
        'console_scripts': [
            'hello-world = timmins:hello_world',
        ]
    }
)
```



## `setup.py` 文件编写

### 文件分发

```python
from setuptools import setup, find_packages


setup(
    name="mytest",
    version="1.0",
    author="wangbm",
    author_email="wongbingming@163.com",
    description="Learn to Pack Python Module",
    url="http://iswbm.com/", 
    packages=find_packages(),

    # 安装过程中，需要安装的静态文件，如配置文件、service文件、图片等
    data_files=[
        ('', ['conf/*.conf']),
        ('/usr/lib/systemd/system/', ['bin/*.service']),
               ],

    # 希望被打包的文件
    package_data={
        '':['*.txt'],
        'bandwidth_reporter':['*.txt']
               },
    # 不打包某些文件
    exclude_package_data={
        'bandwidth_reporter':['*.txt']
               }
)
```



### 二进制文件分发

```python
from setuptools import setup, find_packages


setup(
    name="mytest",
    version="1.0",
    author="wangbm",
    author_email="wongbingming@163.com",
    description="Learn to Pack Python Module",
    url="http://iswbm.com/", 
    packages=find_packages(),

    # 用来支持自动生成脚本，安装后会自动生成 /usr/bin/foo 的可执行文件
    # 该文件入口指向 foo/main.py 的main 函数
    entry_points={
        'console_scripts': [
            'foo = foo.main:main'
        ]
    },

    # 将 bin/foo.sh 和 bar.py 脚本，生成到系统 PATH中
    # 执行 python setup.py install 后
    # 会生成 如 /usr/bin/foo.sh 和 如 /usr/bin/bar.py
    scripts=['bin/foo.sh', 'bar.py']
)
```



### 依赖包下载

```python
from setuptools import setup, find_packages


setup(
    ...

    # 表明当前模块依赖哪些包，若环境中没有，则会从pypi中下载安装
    install_requires=['docutils>=0.3'],

    # setup.py 本身要依赖的包，这通常是为一些setuptools的插件准备的配置
    # 这里列出的包，不会自动安装。
    setup_requires=['pbr'],

    # 仅在测试时需要使用的依赖，在正常发布的代码中是没有用的。
    # 在执行python setup.py test时，可以自动安装这三个库，确保测试的正常运行。
    tests_require=[
        'pytest>=3.3.1',
        'pytest-cov>=2.5.1',
    ],

    # 用于安装setup_requires或tests_require里的软件包
    # 这些信息会写入egg的 metadata 信息中
    dependency_links=[
        "http://example2.com/p/foobar-1.0.tar.gz",
    ],

    # install_requires 在安装模块时会自动安装依赖包
    # 而 extras_require 不会，这里仅表示该模块会依赖这些包
    # 但是这些包通常不会使用到，只有当你深度使用模块时，才会用到，这里需要你手动安装
    extras_require={
        'PDF':  ["ReportLab>=1.2", "RXP"],
        'reST': ["docutils>=0.3"],
    }
)

```

关于 `install_requires`， 有以下五种常用的表示方法：

1. `'argparse'`，只包含包名。 这种形式只检查包的存在性，不检查版本。 方便，但不利于控制风险。
2. `'setuptools==38.2.4'`，指定版本。 这种形式把风险降到了最低，确保了开发、测试与部署的版本一致，不会出现意外。 缺点是不利于更新，每次更新都需要改动代码。
3. `'docutils >= 0.3'`，这是比较常用的形式。 当对某个库比较信任时，这种形式可以自动保持版本为最新。
4. `'Django >= 1.11, != 1.11.1, <= 2'`，这是比较复杂的形式。 如这个例子，保证了Django的大版本在1.11和2之间，也即1.11.x；并且，排除了已知有问题的版本1.11.1（仅举例）。 对于一些大型、复杂的库，这种形式是最合适的。
5. `'requests[security, socks] >= 2.18.4'`，这是包含了额外的可选依赖的形式。 正常安装requests会自动安装它的`install_requires`中指定的依赖，而不会安装`security`和`socks`这两组依赖。 这两组依赖是定义在它的`extras_require`中。 这种形式，用在深度使用某些库时。



### 环境限制

```python
setup(
    ...
    python_requires='>=2.7, <=3',
)
```



























