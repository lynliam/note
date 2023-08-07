# Using time

**Goal:** Learn how to get a **transform** at a specific time and wait for a transform to be available on the tf2 tree using `lookupTransform()` function.

This tutorial will teach you how to **get a transform** at a **specific time**.

Evaluate the `lookupTransform()` call:

```c++
transformStamped = tf_buffer_->lookupTransform(
   toFrameRel,
   fromFrameRel,
   tf2::TimePointZero);
```

TimePointZero equal 0.   For tf2, time 0 means “the latest available” transform in the buffer.

```c++
//  rclcpp::Time now = this->get_clock()->now();
//  transformStamped = tf_buffer_->lookupTransform(
//     toFrameRel,
//     fromFrameRel,
//     now);
```

tf2 provides a nice tool that will wait until a transform becomes available. You use this by adding a timeout parameter to `lookupTransform()`：

```c++
rclcpp::Time now = this->get_clock()->now();
transformStamped = tf_buffer_->lookupTransform(
   toFrameRel,
   fromFrameRel,
   now,
   50ms);
```

