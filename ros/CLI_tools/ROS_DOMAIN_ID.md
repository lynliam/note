# The ROS_DOMAIN_ID 

* ### explanation :

  * DDS: the default middleware that ROS 2 uses for communication
  * In DDS, the primary mechanism for having different logical networks share a physical network is known as the Domain ID.



* ### short version:

  * choosing a domain ID between 0 and 101

* Long version 
  * hightest domain ID  ---  232    depends on the highest port number (65535)





* For maximum compatibility, some additional platform-specific constraints should be followed when choosing a domain ID. In particular, it is best to avoid allocating domain IDs in the operating system’s [ephemeral port range](https://en.wikipedia.org/wiki/Ephemeral_port).