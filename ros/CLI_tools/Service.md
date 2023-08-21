# Services

* #### brief introduction

  * Services are based on **a call-and-response model**,
  * Services only provide data when they are specifically called by **a client**.

  * A service can have **many client** but only **one** server

* ```ros2 service list``` 
  
  * Add**```-t```** or**```--show-types```**    to see the type of services
  * return a list of services currently active.
  * nearly every node have six services with **parameters**
  
* ```ros2 service type```

  * ```shell
    #services have types that describe how the request and response data of a service
    #find out the type of a service 
    ros2 service type <service_name>
    #example:
    ros2 service type /clearr
    ```

    

* ```ros2 service find```

  * ```shell
    #to find all services of a specific type
    ros2 service find <type_name>
    ```

* ```ros2 interface show```

  * ```shell
    #to know the structure of the input arguments
    ros2 interface show <type_name>
    ```

  * The `---` separates the request structure (above) from the response structure (below).

* ```ros2 servoce call```
  *  ```shell
     ros2 service call <service_name> <service_type> <arguments>
     
     arguments 中的参数和参数名后的:之间要有空格·······！！！！！
     ```
  
    