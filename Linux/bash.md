# BASH

* Shell：壳程序

  * 只要能够操作应用程序的接口都能够称之为壳程序

* Bash：Bourne Again Shell  是Shell其中一种版本

  * 命令编修功能

    * 曾经敲过的命令保存在```.bash_history```文件中

  * 命令与文件补全功能

    * [Tab]接在一串命令的第一个字后面，则为**命令补全**
    * [Tab]接在xxx的第二个字后面，为**文件补全**
    * bash-completion

  * 命令别名设置功能

    * 为命令设置别名

    * ```shell
      alias lm='ls -al'
      ```

  * shell scripts

  * 万用字符

* type：

  * ```shell
    type [-tpa] name
    选项与参数：
    ：不加任何选项与参数时，type 会显示出 name 是外部指令还是 bash 内置指令
    -t ：当加入 -t 参数时，type 会将 name 以下面这些字眼显示出他的意义：
    file ：表示为外部指令；
    alias ：表示该指令为命令别名所设置的名称；
    builtin ：表示该指令为 bash 内置的指令功能；
    -p ：如果后面接的 name 为外部指令时，才会显示完整文件名；
    -a ：会由 PATH 变量定义的路径中，将所有含 name 的指令都列出来，包含 alias
    ```

  * 

* 通过  **\ **来转义[Enter]键





* Shell的变量
  * 变量的取用和设置：```echo```
    * ```shell
      #读取变量abc的内容
      echo $abc
      echo ${abc}
      #用等号来设置和修改变量的值  等号两边不能够有空白字符
      abc=123
      #变量内容有空白字符可以用引号
      #用单引号的时候内容全部识别为一般字符
      #用双引号的时候特殊字符可以保留原本特性
      var='lang id $lang'
      var="lang id $lang"    
      #跳脱字符  \  将特殊字符变为一般字符
      #一串指令中还与需要额外指令
      `指令`
      #或
      $ (指令)
      
      #扩增变量内容
      $变量名
      ${变量名}
      PATH=${PATH}:/home/bin
      
      #如果变量需要在其他子程序执行，则使用export
      
      #取消变量设置使用   unset
      unset 变量名
      ```
  
  * env指令
  
    * 