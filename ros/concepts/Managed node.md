# Managed Nodes

## 1.0   Background

A managed life cycle for nodes allows greater control over the state of ROS system. It will allow roslaunch to ensure that all components have been instantiated correctly before it allows any component to begin executing its behaviour. It will also allow nodes to be restarted or replaced on-line.



## 2.0     Lifecycle

![The proposed node life cycle state machine](Managed node.assets/life_cycle_sm.png)

The **blue blank** are 4 ***primary states***

- `Unconfigured`
- `Inactive`
- `Active`
- `Finalized`

There are also 6 transition states which are intermediate states **during a requested transition**.

- `Configuring`
- `CleaningUp`
- `ShuttingDown`
- `Activating`
- `Deactivating`
- `ErrorProcessing`

There are 7 transitions exposed to a supervisory process, they are:

- `create`
- `configure`
- `cleanup`
- `activate`
- `deactivate`
- `shutdown`
- `destroy`

