# Passing Additional argument



There are two message: 

* Add arguments to your constructor
* Use a "initialize" method



## 1.0   Add arguments to your constructor

```c++
// Action_A has a different constructor than the default one.
class Action_A: public SyncActionNode
{

public:
    // additional arguments passed to the constructor
    Action_A(const std::string& name, const NodeConfig& config,
             int arg_int, std::string arg_str):
        SyncActionNode(name, config),
        _arg1(arg_int),
        _arg2(arg_str) {}

    // this example doesn't require any port
    static PortsList providedPorts() { return {}; }

    // tick() can access the private members
    NodeStatus tick() override;

private:
    int _arg1;
    std::string _arg2;
};
```

## 2.0   Use a "initialize" method

```c++
class Action_B: public SyncActionNode
{

public:
    // The constructor looks as usual.
    Action_B(const std::string& name, const NodeConfig& config):
        SyncActionNode(name, config) {}

    // We want this method to be called ONCE and BEFORE the first tick()
    void initialize(int arg_int, const std::string& arg_str)
    {
        _arg1 = arg_int;
        _arg2 = arg_str;
    }

    // this example doesn't require any port
    static PortsList providedPorts() { return {}; }

    // tick() can access the private members
    NodeStatus tick() override;

private:
    int _arg1;
    std::string _arg2;
};


BT::BehaviorTreeFactory factory;

// Register as usual, but we still need to initialize
factory.registerNodeType<Action_B>("Action_B");

// Create the whole tree. Instances of Action_B are not initialized yet
auto tree = factory.createTreeFromText(xml_text);

// visitor will initialize the instances of 
auto visitor = [](TreeNode* node)
{
  if (auto action_B_node = dynamic_cast<Action_B*>(node))
  {
    action_B_node->initialize(69, "interesting_value");
  }
};

// Apply the visitor to ALL the nodes of the tree
tree.applyVisitor(visitor);
```

