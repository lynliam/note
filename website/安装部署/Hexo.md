# `Hexo`  使用教程



## [1.0   安装](https://github.com/nvm-sh/nvm#installing-and-updating)

### 1.1  Nvm   管理 Node.js

#### [安装脚本](https://github.com/nvm-sh/nvm#install--update-script)

To **install** or **update** nvm, you should run the [install script](https://github.com/nvm-sh/nvm/blob/v0.39.5/install.sh). To do that, you may either download and run the script manually, or use the following cURL or Wget command:

```
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.5/install.sh | bash
```

```
wget -qO- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.5/install.sh | bash
```

Running either of the above commands downloads a script and runs it. The script clones the nvm repository to `~/.nvm`, and attempts to add the source lines from the snippet below to the correct profile file (`~/.bash_profile`, `~/.zshrc`, `~/.profile`, or `~/.bashrc`).

```
export NVM_DIR="$([ -z "${XDG_CONFIG_HOME-}" ] && printf %s "${HOME}/.nvm" || printf %s "${XDG_CONFIG_HOME}/nvm")"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh" # This loads nvm
```



#### 可使用的 `cli`

```shell
nvm install node # "node" is an alias for the latest version

nvm install 14.7.0 # or 16.3.0, 12.22.1, etc

nvm ls-remote

nvm which 12.22   #You can also get the path to the executable to where it was installed
```



### 1.2  安装 Hexo

```shell
 npm install -g hexo-cli
```



### 1.3   [建站](https://hexo.io/zh-cn/docs/setup)

装 Hexo 完成后，请执行下列命令，Hexo 将会在指定文件夹中新建所需要的文件。

```
$ hexo init <folder>
$ cd <folder>
$ npm install
```

新建完成后，指定文件夹的目录如下：

```
.
├── _config.yml
├── package.json
├── scaffolds
├── source
|   ├── _drafts
|   └── _posts
└── themes
```