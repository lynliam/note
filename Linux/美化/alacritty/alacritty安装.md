# Alacritty安装与配置

[安装教程点我](https://github.com/alacritty/alacritty/blob/master/INSTALL.md)

### 1.  克隆仓库

Before compiling Alacritty, you'll have to first clone the source code:

```
git clone https://github.com/alacritty/alacritty.git
cd alacritty
```



### 2.  安装rust编译器rustup

1. Install [`rustup.rs`](https://rustup.rs/).

```shell
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

2. To make sure you have the right Rust compiler installed, run(**检测rust安装好了没有**)

```
rustup override set stable
rustup update stable
```



### 3. 依赖安装

#### Ubuntu

```shell
sudo apt install cmake pkg-config libfreetype6-dev libfontconfig1-dev libxcb-xfixes0-dev libxkbcommon-dev python3
```

#### Arch Linux

```shell
sudo pacman -S cmake freetype2 fontconfig pkg-config make libxcb libxkbcommon python
```



### 4.  编译安装

* 检查一下当前系统的窗口系统是 **X11** 或 **Wayland**

```shell
# Force support for only Wayland
cargo build --release --no-default-features --features=wayland

# Force support for only X11
cargo build --release --no-default-features --features=x11
```

* 或者无脑：

```shell
cargo build --release
```



### 5. 桌面快捷图标

```shell
sudo cp target/release/alacritty /usr/local/bin # or anywhere else in $PATH
sudo cp extra/logo/alacritty-term.svg /usr/share/pixmaps/Alacritty.svg
sudo desktop-file-install extra/linux/Alacritty.desktop
sudo update-desktop-database
```

 

### 6. Terminfo

如果运行下面命令，没有 **error** 出现，则已经安装好了

```shell
infocmp alacritty
```

若没有安装好：

```shell
sudo tic -xe alacritty,alacritty-direct extra/alacritty.info
```



### 7.  Shell 补全功能

#### Zsh

```shell
mkdir -p ${ZDOTDIR:-~}/.zsh_functions
echo 'fpath+=${ZDOTDIR:-~}/.zsh_functions' >> ${ZDOTDIR:-~}/.zshrc
```

```shell
cp extra/completions/_alacritty ${ZDOTDIR:-~}/.zsh_functions/_alacritty
```



#### Bash

```shell
echo "source $(pwd)/extra/completions/alacritty.bash" >> ~/.bashrc
```

```shell
mkdir -p ~/.bash_completion
cp extra/completions/alacritty.bash ~/.bash_completion/alacritty
echo "source ~/.bash_completion/alacritty" >> ~/.bashrc
```



## 配置：

下载当前目录下面的 **alacritty.yml** 文件，然后放在

Alacritty doesn't create the config file for you, but it looks for one in the following locations:

1. `$XDG_CONFIG_HOME/alacritty/alacritty.toml`
2. `$XDG_CONFIG_HOME/alacritty.toml`
3. `$HOME/.config/alacritty/alacritty.toml`
4. `$HOME/.alacritty.toml`

### 更改默认启动终端

找到配置文件中的

```yml
shell:
  program: /bin/zsh
  # program: /bin/bash
  # windows
  # program: c:\windows\system32\windowspowershell\v1.0\powershell.exe
  args:
    # login
    - -l
```

配置成上面的样子
