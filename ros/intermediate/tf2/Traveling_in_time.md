# Traveling in time

## [Advanced API for lookupTransform()](http://docs.ros.org/en/humble/Tutorials/Intermediate/Tf2/Time-Travel-With-Tf2-Cpp.html#id3)[](http://docs.ros.org/en/humble/Tutorials/Intermediate/Tf2/Time-Travel-With-Tf2-Cpp.html#advanced-api-for-lookuptransform)

To ask the tf2 that particular question, we will use an advanced API  that gives us the power to say explicitly when to acquire the specified  transformations. This is done by calling the `lookupTransform()` method with additional parameters. Your code now would look like this:

```
rclcpp::Time now = this->get_clock()->now();
rclcpp::Time when = now - rclcpp::Duration(5, 0);
t = tf_buffer_->lookupTransform(
    toFrameRel,
    now,
    fromFrameRel,
    when,
    "world",
    50ms);
```

The advanced API for `lookupTransform()` takes six arguments:

1. Target frame
2. The time to transform to
3. Source frame
4. The time at which source frame will be evaluated
5. Frame that does not change over time, in this case the `world` frame
6. Time to wait for the target frame to become available
