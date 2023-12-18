# Services



## 1.0     Service server

### Initialization

Starting from a code where RCL is initialized and a micro-ROS node is created, there are three ways to initialize a service server:

- Reliable (default):

  ```c
  // Service server object
  rcl_service_t service;
  const char * service_name = "/addtwoints";
  
  // Get message type support
  const rosidl_message_type_support_t * type_support =
    ROSIDL_GET_SRV_TYPE_SUPPORT(example_interfaces, srv, AddTwoInts);
  
  // Initialize server with default configuration
  rcl_ret_t rc = rclc_service_init_default(
    &service, &node,
    type_support, service_name);
  
  if (rc != RCL_RET_OK) {
    ...  // Handle error
    return -1;
  }
  ```

- Best effort:

  ```c
  // Service server object
  rcl_service_t service;
  const char * service_name = "/addtwoints";
  
  // Get message type support
  const rosidl_message_type_support_t * type_support =
    ROSIDL_GET_SRV_TYPE_SUPPORT(example_interfaces, srv, AddTwoInts);
  
  // Initialize server with default configuration
  rcl_ret_t rc = rclc_service_init_best_effort(
    &service, &node,
    type_support, service_name);
  
  if (rc != RCL_RET_OK) {
    ...  // Handle error
    return -1;
  }
  ```

- Custom QoS:

  ```c
  // Service server object
  rcl_service_t service;
  const char * service_name = "/addtwoints";
  
  // Get message type support
  const rosidl_message_type_support_t * type_support =
    ROSIDL_GET_SRV_TYPE_SUPPORT(example_interfaces, srv, AddTwoInts);
  
  // Set service QoS
  const rmw_qos_profile_t * qos_profile = &rmw_qos_profile_services_default;
  
  // Initialize server with customized quality-of-service options
  rcl_ret_t rc = rclc_service_init(
    &service, &node, type_support,
    service_name, qos_profile);
  
  if (rc != RCL_RET_OK) {
    ...  // Handle error
    return -1;
  }
  ```



### Callback

The client request message will contain two integers `a` and `b`, and expects the `sum` of them as a response:

```c
// Function prototype:
void (* rclc_service_callback_t)(const void *, void *);

// Implementation example:
void service_callback(const void * request_msg, void * response_msg){
  // Cast messages to expected types
  example_interfaces__srv__AddTwoInts_Request * req_in =
    (example_interfaces__srv__AddTwoInts_Request *) request_msg;
  example_interfaces__srv__AddTwoInts_Response * res_in =
    (example_interfaces__srv__AddTwoInts_Response *) response_msg;

  // Handle request message and set the response message values
  printf("Client requested sum of %d and %d.\n", (int) req_in->a, (int) req_in->b);
  res_in->sum = req_in->a + req_in->b;
}
```

Note that it is necessary to cast each message to the expected type

Once the service and the executor are initialized, the service callback must be added to the executor in order to process incoming requests once the executor is spinning:

```c
// Service message objects
example_interfaces__srv__AddTwoInts_Response response_msg;
example_interfaces__srv__AddTwoInts_Request request_msg;

// Add server callback to the executor
rc = rclc_executor_add_service(
  &executor, &service, &request_msg,
  &response_msg, service_callback);

if (rc != RCL_RET_OK) {
  ...  // Handle error
  return -1;
}

// Spin executor to receive requests
rclc_executor_spin(&executor);
```





## 2.0    Service Client

### Initialization

The service client initialization is almost identical to the server one:

- Reliable (default):

  ```
  // Service client object
  rcl_client_t client;
  const char * service_name = "/addtwoints";
  
  // Get message type support
  const rosidl_message_type_support_t * type_support =
    ROSIDL_GET_SRV_TYPE_SUPPORT(example_interfaces, srv, AddTwoInts);
  
  // Initialize client with default configuration
  rcl_ret_t rc = rclc_client_init_default(
    &client, &node,
    type_support, service_name);
  
  if (rc != RCL_RET_OK) {
    ...  // Handle error
    return -1;
  }
  ```

- Best effort:

  ```
  // Service client object
  rcl_client_t client;
  const char * service_name = "/addtwoints";
  
  // Get message type support
  const rosidl_message_type_support_t * type_support =
    ROSIDL_GET_SRV_TYPE_SUPPORT(example_interfaces, srv, AddTwoInts);
  
  // Initialize client with default configuration
  rcl_ret_t rc = rclc_client_init_best_effort(
    &client, &node,
    type_support, service_name);
  
  if (rc != RCL_RET_OK) {
    ...  // Handle error
    return -1;
  }
  ```

- Custom QoS:

  ```
  // Service client object
  rcl_client_t client;
  const char * service_name = "/addtwoints";
  
  // Get message type support
  const rosidl_message_type_support_t * type_support =
    ROSIDL_GET_SRV_TYPE_SUPPORT(example_interfaces, srv, AddTwoInts);
  
  // Set client QoS
  const rmw_qos_profile_t * qos_profile = &rmw_qos_profile_services_default;
  
  // Initialize server with customized quality-of-service options
  rcl_ret_t rc = rclc_client_init(
    &client, &node, type_support,
    service_name, qos_profile);
  
  if (rc != RCL_RET_OK) {
    ...  // Handle error
    return -1;
  }
  ```

### Callback

The executor is responsible to call the configured callback when the service response arrives. The function will have the response message as its only argument, containing the values sent by the server.

It is necessary to cast the response message to the expected type. Example:

```
// Function prototype:
void (* rclc_client_callback_t)(const void *);

// Implementation example:
void client_callback(const void * response_msg){
  // Cast response message to expected type
  example_interfaces__srv__AddTwoInts_Response * msgin =
    (example_interfaces__srv__AddTwoInts_Response * ) response_msg;

  // Handle response message
  printf("Received service response %ld + %ld = %ld\n", req.a, req.b, msgin->sum);
}
```

Once the client and the executor are initialized, the client callback must be added to the executor in order to receive the service response once the executor is spinning:

```
// Response message object
example_interfaces__srv__AddTwoInts_Response res;

// Add client callback to the executor
rcl_ret_t rc = rclc_executor_add_client(&executor, &client, &res, client_callback);

if (rc != RCL_RET_OK) {
  ...  // Handle error
  return -1;
}

// Spin executor to receive requests
rclc_executor_spin(&executor);
```

### Send a request

Once the service client and server are configured, the service client can perform a request and spin the executor to get the reply. Following the example on `AddTwoInts.srv`:

```
// Request message object (Must match initialized client type support)
example_interfaces__srv__AddTwoInts_Request request_msg;

// Initialize request message memory and set its values
example_interfaces__srv__AddTwoInts_Request__init(&request_msg);
request_msg.a = 24;
request_msg.b = 42;

// Sequence number of the request (Populated in rcl_send_request)
int64_t sequence_number;

// Send request
rcl_send_request(&client, &request_msg, &sequence_number);

// Spin the executor to get the response
rclc_executor_spin(&executor);
```

## Message initialization

Before sending or receiving a message, it may be necessary to initialize its memory for types with strings or sequences. Check the [Handling messages memory in micro-ROS](https://micro.ros.org/docs/tutorials/advanced/handling_type_memory/) section for details.

## Cleaning Up

To destroy an initialized service or client:

```
// Destroy service server and client
rcl_service_fini(&service, &node);
rcl_client_fini(&client, &node);
```

This will delete any automatically created infrastructure on the agent (if possible) and deallocate used memory on the client side.