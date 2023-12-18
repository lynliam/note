# Blackboard and ports

BehaviorTree.CPP provides a basic mechanism of **dataflow** through **ports**

> MAIN CONCEPTS
>
> - A "Blackboard" is a simple **key/value storage** shared by all the nodes of the Tree.
> - An "entry" of the Blackboard is a **key/value pair**.
> - An **Input port** can read an entry in the Blackboard, whilst an **Output port** can write into an entry.

![tutorial_blackboard-c21790e0c974974f0f3eca9efeb4b765](02 Blackboard and Ports.assets/tutorial_blackboard-c21790e0c974974f0f3eca9efeb4b765-1701697531833-3.svg)

## Input ports

A valid input can be:

* a **static string** that the Node will read and parse
* a **pointer** to an entry of the Blackboard, identified by a **key**