# colcon

* 编译工具

  ```shell
  #只编译一个包
  colcon build --packages-select YOUR_PKG_NAME 
  #不编译测试单元
  colcon build --packages-select YOUR_PKG_NAME  --cmake-args -DBUILD_TESTING=0
  #运行编译的包的测试
  colcon test
  #允许通过更改src部分文件来改变install
  colcon build --symlink-install
  ```

  