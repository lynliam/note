# Publishers and subscribers

## 1.0      Initialization

Based on desired **QoS**，there are 3 types :

- Reliable (default):

  ```c
  // Publisher object
  rcl_publisher_t publisher;
  const char * topic_name = "test_topic";
  
  // Get message type support
  const rosidl_message_type_support_t * type_support =
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32);
  
  // Creates a reliable rcl publisher
  rcl_ret_t rc = rclc_publisher_init_default(
    &publisher, &node,
    type_support, topic_name);
  
  if (RCL_RET_OK != rc) {
    ...  // Handle error
    return -1;
  }
  ```

- Best effort:

  ```c
  // Publisher object
  rcl_publisher_t publisher;
  const char * topic_name = "test_topic";
  
  // Get message type support
  const rosidl_message_type_support_t * type_support =
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32);
  
  // Creates a best effort rcl publisher
  rcl_ret_t rc = rclc_publisher_init_best_effort(
    &publisher, &node,
    type_support, topic_name);
  
  if (RCL_RET_OK != rc) {
    ...  // Handle error
    return -1;
  }
  ```

- Custom QoS:

  ```c
  // Publisher object
  rcl_publisher_t publisher;
  const char * topic_name = "test_topic";
  
  // Get message type support
  const rosidl_message_type_support_t * type_support =
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32);
  
  // Set publisher QoS
  const rmw_qos_profile_t * qos_profile = &rmw_qos_profile_default;
  
  // Creates a rcl publisher with customized quality-of-service options
  rcl_ret_t rc = rclc_publisher_init(
    &publisher, &node,
    type_support, topic_name, qos_profile);
  
  if (RCL_RET_OK != rc) {
    ...  // Handle error
    return -1;
  }
  ```

### Publish a message

```c
// Int32 message object
std_msgs__msg__Int32 msg;

// Set message value
msg.data = 0;

// Publish message
rcl_ret_t rc = rcl_publish(&publisher, &msg, NULL);

if (rc != RCL_RET_OK) {
  ...  // Handle error
  return -1;
}
```

> `rcl_publish` is ***thread safe*** and can be called from multiple threads.





## 2.0      Subscription

### Initialization

The suscriptor initialization is almost identical to the publisher one:

- Reliable (default):

  ```c
  // Subscription object
  rcl_subscription_t subscriber;
  const char * topic_name = "test_topic";
  
  // Get message type support
  const rosidl_message_type_support_t * type_support =
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32);
  
  // Initialize a reliable subscriber
  rcl_ret_t rc = rclc_subscription_init_default(
    &subscriber, &node,
    type_support, topic_name);
  
  if (RCL_RET_OK != rc) {
    ...  // Handle error
    return -1;
  }
  ```

- Best effort:

  ```c
  // Subscription object
  rcl_subscription_t subscriber;
  const char * topic_name = "test_topic";
  
  // Get message type support
  const rosidl_message_type_support_t * type_support =
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32);
  
  // Initialize best effort subscriber
  rcl_ret_t rc = rclc_subscription_init_best_effort(
    &subscriber, &node,
    type_support, topic_name);
  
  if (RCL_RET_OK != rc) {
    ...  // Handle error
    return -1;
  }
  ```

- Custom QoS:

  ```c
  // Subscription object
  rcl_subscription_t subscriber;
  const char * topic_name = "test_topic";
  
  // Get message type support
  const rosidl_message_type_support_t * type_support =
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32);
  
  // Set client QoS
  const rmw_qos_profile_t * qos_profile = &rmw_qos_profile_default;
  
  // Initialize a subscriber with customized quality-of-service options
  rcl_ret_t rc = rclc_subscription_init(
    &subscriber, &node,
    type_support, topic_name, qos_profile);
  
  if (RCL_RET_OK != rc) {
    ...  // Handle error
    return -1;
  }
  ```



### Callbacks

The executor is responsible to call the configured callback when a message is published. The function will have the message as its only argument, containing the values sent by the publisher:

```c
// Function prototype:
void (* rclc_subscription_callback_t)(const void *);

// Implementation example:
void subscription_callback(const void * msgin)
{
  // Cast received message to used type
  const std_msgs__msg__Int32 * msg = (const std_msgs__msg__Int32 *)msgin;

  // Process message
  printf("Received: %d\n", msg->data);
}
```

Once the subscriber and the executor are initialized, the subscriber callback must be added to the executor to receive incoming publications once its spinning:

```c
// Message object to receive publisher data
std_msgs__msg__Int32 msg;

// Add subscription to the executor
rcl_ret_t rc = rclc_executor_add_subscription(
  &executor, &subscriber, &msg,
  &subscription_callback, ON_NEW_DATA);

if (RCL_RET_OK != rc) {
  ...  // Handle error
  return -1;
}

// Spin executor to receive messages
rclc_executor_spin(&executor);
```



## Message initialization

Before publishing or receiving a message, it may be necessary to initialize its memory for types with strings or sequences. Check the [Handling messages memory in micro-ROS](https://micro.ros.org/docs/tutorials/advanced/handling_type_memory/) section for details.

## Cleaning Up

After finishing the publisher/subscriber, the node will no longer be advertising that it is publishing/listening on the topic. To destroy an initialized publisher or subscriber:

```c
// Destroy publisher
rcl_publisher_fini(&publisher, &node);

// Destroy subscriber
rcl_subscription_fini(&subscriber, &node);
```
