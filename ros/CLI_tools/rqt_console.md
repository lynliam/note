# Using `rqt_console` to view logs

* #### brief introduction

  * a GUI tool used to introspect log messages 





* start :

  * ```shell
    ros2 run rqt_console rqt_console
    ```



* logger levels

  * ```shell
    #indicate the system is going to terminate to try to protect itself from detriment.
    Fatal
    
    #indicate significant issues that won’t necessarily damage the system, but are preventing it from functioning properly
    Error
    
    #messages indicate unexpected activity or non-ideal results that might represent a deeper issue, but don’t harm functionality outright
    Warn
    
    #indicate event and status updates that serve as a visual verification that the system is running as expected.
    Info
    
    #detail the entire step-by-step process of the system execution
    Debug
    ```

  * Normally, only `Debug` messages are hidden because they’re the only level less severe than `Info`

  * ```shell
    ros2 run turtlesim turtlesim_node --ros-args --log-level WARN
    ```

    