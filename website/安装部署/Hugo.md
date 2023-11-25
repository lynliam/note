# `Hugo` 使用教程



## 1.0    [安装`Hugo`](https://gohugo.io/installation/linux/)

## Build from source 

To build the extended edition of Hugo from source you must:

1. Install [Git](https://git-scm.com/)
2. Install [Go](https://go.dev/) version 1.19 or later
3. Install a C compiler, either [GCC](https://gcc.gnu.org/) or [Clang](https://clang.llvm.org/)
4. Update your `PATH` environment variable as described in the [Go documentation](https://go.dev/doc/code#Command)

> The install directory is controlled by the `GOPATH` and `GOBIN` environment variables. If `GOBIN` is set, binaries are installed to that directory. If `GOPATH` is set, binaries are installed to the bin subdirectory of the first directory in the `GOPATH` list. Otherwise, binaries are installed to the bin subdirectory of the default `GOPATH` (`$HOME/go` or `%USERPROFILE%\go`).

Then build and test:

```sh
CGO_ENABLED=1 go install -tags extended github.com/gohugoio/hugo@latest
hugo version
```