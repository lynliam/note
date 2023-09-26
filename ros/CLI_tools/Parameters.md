# Parameters

* #### brief introduction

  * as node settings   &&  a configuration value of a node
  * A node can store parameters as integers, floats, booleans, strings, and lists.

* ```ros2 param list```

  * ```shell
    #this show parameters belongling to your nodes
    ros2 param list
    ```

  * Every node has the parameter `use_sim_time`;

* ```ros2 param get```

  * ```shell
    #To determine a parameter’s type
    ros2 param get <node_name> <parameter_name>
    ```

* ```ros2 param set```

  * ```shell
    #To change a parameter's value 
    ros2 param set <node_name> <parameter_name> <value>
    ```

* ```ros2 param dump```

  * ```shell
    #view all of a node's current parameter values by using the command
    ros2 param dump <node_name>
    
    #example  and this can save it into the file "turtlesim.yaml"
    ros2 param dump /turtlesim > turtlesim.yaml
    ```

* ```ros2 param load```

  * ```shell
    #load parameters from a file
    ros2 param load <node_name> <parameter_file>
    #Read-only parameters can only be modified at startup and not afterwards, that is why there are some warnings for the “qos_overrides” parameters.
    ```

* load parameter file on node startup

  * ```shell
    #To start the same node using your saved parameter values
    ros2 run <package_name> <executable_name> --ros-args --params-file <file_name>
    #example
    ros2 run turtlesim turtlesim_node --ros-args --params-file turtlesim.yaml
    ```

  * 