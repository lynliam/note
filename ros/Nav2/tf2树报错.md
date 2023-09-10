# 错误Could not find a connection between ‘/base_footprint‘ and‘/base_link‘



arto文档中的参数说明
```shell
map_frame：The ROS frame ID to use for publishing submaps, the parent frame of poses, usually “map”

published_frame：The ROS frame ID to use as the child frame for publishing poses. For example “odom” if an “odom” frame is supplied by a different part of the system. In this case the pose of “odom” in the map_frame will be published. Otherwise, setting it to “base_link” is likely appropriate
```

坐标系变换通常可以为：
```latex
map_frame→ \to→odom→ \to→published_frame
```

或者

```markdown
map_frame→ \to→published_frame
```

故设置时注意TF树的连通性