# Actions

* #### brief introduction

  * intended for long running tasks 

  * built on topics and services and can be canceled by ***client*** or ***server***

  * **how it work**:

    * An “action client” node sends a goal to an “action server” node that  acknowledges the goal and returns a stream of feedback and a result.

  * | goal | feedback | result |
    | ---- | -------- | ------ |

    

<img src="/media/lynliam/data/markdown/ros/image/Action-SingleActionClient.gif" alt="Action-SingleActionClient"  />







* ```ros2 node info```

  * ```shell
    #to see the node's actions
    ros2 node info <node_name>
    ```

* ```ros2 action list```

  * ```shell
    #identify all the actions in the ROS graph
    ros2 action list
    #to return actions' type
    ros2 action list -t
    ```

* ```ros2 action info <action_name> ```

  * ```shell
    #it will tell you
    #example
    
    #Action: /turtle1/rotate_absolute
    #Action clients: 1
    #    /teleop_turtle
    #Action servers: 1
    #    /turtlesim
    ```

    

* ```ros2 interface show```

  * ```shell
    #return the structure of the acftion type
    ```

    

* ```ros2 action send_goal```

  * ```shell
    #send an action goal
    ros2 action send_goal <action_name> <action_type> <values>
    #<values> need to be in YAML format.
    #To see the feedback of this goal, add --feedback to the ros2 action send_goal command:
    ros2 action send_goal /turtle1/rotate_absolute turtlesim/action/RotateAbsolute "{theta: -1.57}" --feedback
    ```
    
    