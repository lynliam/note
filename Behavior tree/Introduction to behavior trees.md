# Introduction to behavior trees

![img](Introduction to behavior trees.assets/bt_intro_banner.png)

Abstraction in programming has **evolved** our use of computers from basic arithmetic operations to representing complex real-world phenomena using models.

Most of the time, you will find the abstractions that includes:

* **[teleo-reactive programs](https://teleoreactiveprograms.net/introduction/)**
* **[Petri nets](https://ieeexplore.ieee.org/abstract/document/725407)**
* **[finite-state machines (FSMs)](https://en.wikipedia.org/wiki/Finite-state_machine)**
* **[behavior trees (BTs)](https://arxiv.org/abs/1709.00084)**

Behavior trees actually began in the videogame industry to define behaviors for non-player characters (NPCs): Both [Unreal Engine](https://docs.unrealengine.com/en-US/InteractiveExperiences/ArtificialIntelligence/BehaviorTrees/BehaviorTreesOverview/index.html) and [Unity](https://opsive.com/support/documentation/behavior-designer/overview/).   It is **easy** to compose or modify, but **sacrifices** the ease of designing reactivce behaviors.

**BTs** can be defined by the following characteristics:

* **Behavior trees are trees (duh)**. They start at a root node and are designed to be traversed in a specific order until a terminal state is reached (success or failure).
* **Leaf nodes are executable behaviors:** Each leaf will do something, whether it’s a simple check or a complex action, and will output a status (success, failure, or running). In other words, leaf nodes are where you connect a BT to the lower-level code for your specific application.
* **Internal nodes control tree traversal:** The internal (non-leaf) nodes of the tree will accept the resulting status of their children and apply their own rules to dictate which node should be expanded next.



## Behavior tree terminology

![img](Introduction to behavior trees.assets/bt_node_types.png)

### Concept Explanation:

#### 1. TIcks :  

​	 Discrete update steps which ehavior trees execute in.  After a node ticks, it returns a **status** to its parent, which can be ***Success***, ***Failure***, or ***Running***.

#### 2. Execution nodes

​	They are leaves of the BT, can either be **Action** or **Condition** nodes.  ***condition nodes represent simple checks (e.g., “is the gripper open?”) while action nodes represent complex actions (e.g., “open the door”).***

#### 3. Control Node

**Control nodes** are internal nodes and define how to traverse the BT given the status of their children.   **Decorator** nodes only have one child node, while other type of nodes can have any number of children.

> Check out the images below to see how the different control nodes work.
>
> ![img](Introduction to behavior trees.assets/bt_sequence_node.png)
>
> Sequence nodes execute children in order until **one child returns Failure** or **all children returns Success**.
>
> ![img](Introduction to behavior trees.assets/bt_fallback_node.png)
>
> Fallback nodes execute children in order until **one of them returns Success** or **all children return Failure**. These nodes are key in designing recovery behaviors for your autonomous agents.
>
> ![img](Introduction to behavior trees.assets/bt_parallel_node.png)
>
> Parallel nodes will execute all their children in “parallel”. This is in quotes because it’s not true parallelism; at each tick, each child node will individually tick in order. Parallel nodes return Success when at least M child nodes (between 1 and N) have succeeded, and Failure when all child nodes have failed.
>
> ![img](Introduction to behavior trees.assets/bt_decorator_node.png)
>
> Decorator nodes modify a single child node with a custom policy. A decorator has its own set of rules for changing the status of the “decorated node”. For example, an “Invert” decorator will change Success to Failure, and vice-versa. While decorators can add flexibility to your behavior tree arsenal, you should stick to standard control nodes and common decorators as much as possible so others can easily understand your design.



### How to choose between  FSM  and   BTs ?

- In theory, it is possible to express anything as a BT, FSM, one of the other abstractions, or as plain code. However, each model has its own advantages and disadvantages in their intent to aid design at larger scale.
- Specific to BTs vs. FSMs, there is a tradeoff between **modularity** and **reactivity**. Generally, BTs are easier to compose and modify while FSMs have their strength in designing reactive behaviors.









































