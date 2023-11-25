# CLI TOOL



```shell
#node
ros2 node list
ros2 node info


#topic
ros2 topic list
				ros2 topic list -t

ros2 topic echo
ros2 topic info

ros2 interface show 
ros2 topic pub <topic_name> <msg_type> '<args>'
ros2 topic hz

#service
ros2 service list -t
ros2 service type <service_name>
ros2 service find
ros2 interface show
ros2 service call


#parameters
 ros2 param list
 ros2 param get
 ros2 param set
 ros2 param dump
 ros2 param load
 
 
 #action
 ros2 node info
 ros2 action list
 ros2 action info
 ros2 interface show
 ros2 action send_goal
```

