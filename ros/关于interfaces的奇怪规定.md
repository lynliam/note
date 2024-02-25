# 关于Interface接口的奇怪规定

接口文件的命名规则;

```shell
# 接口文件名字不能使用 下划线 来命名
# 例如：
# action_client.msg
# 因为编译完之后，貌似在C++环境中  代码中的名字中大写字母会自动变为 _字母
# 例如：
# ActionClient.action   ->>>>    action_client

# 接口不能只有一个大写字母,应使用>=2 的大写字母。
# 例如：
# Ball.msg 编译可以通过，甚至可以在interface show 中显示， 但是无法引用
# 应使用：
# BallInfo.msg

```

