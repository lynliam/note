# ROS2 Launch System

The launch system in ROS is responsible for helping the user describe the configuration of their system and then execute it as described.

> **the main roles of `roslaunch` from ROS 1 **
>
> - launch nodes
> - launching nodes remotely via SSH
> - setting parameters on the parameter server
> - automatic respawning of processes that die
> - static, XML based description of the nodes to launch, parameters to set, and where to run them

> 1. `<include>`s: you can easily include other .launch files and also assign them a namespace so that their names do not confict with yours.
> 2. `<group>`s: you can group together a collection of nodes to give them the same name remappings.
> 3. aliase `<machine>s`:  separate machine definitions
> 4. `<env> `tag can specify the environment



### Differences in ROS2

#### Relatonship Between Nodes and Processes:

there can be **multiple nodes per process** while the ROS1 only could have one node var one process. 

#### Launching Nodes(Process) Remotely and portability

























