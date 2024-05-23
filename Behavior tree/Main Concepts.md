# Main Concepts

BehaviorTree.CPP  can be easily integrated into your favourite distributed middleware.

## Instantiate trees at run-time using the XML format

## The tick() callbacks







# The XML schema

```xml
 <root BTCPP_format="4">
     <BehaviorTree ID="MainTree">
        <Sequence name="root_sequence">
            <SaySomething   name="action_hello" message="Hello"/>
            <OpenGripper    name="open_gripper"/>
            <ApproachObject name="approach_object"/>
            <CloseGripper   name="close_gripper"/>
        </Sequence>
     </BehaviorTree>
 </root>
```

- In terms of number of children:
  - `ControlNodes` contain **1 to N children**.
  - `DecoratorNodes` and Subtrees contain **only 1 child**.
  - `ActionNodes` and `ConditionNodes` have **no child**.

