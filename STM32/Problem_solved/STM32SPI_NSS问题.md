# NSS 是否为硬件SPI的问题

Slave select (NSS) pin management
There are two NSS modes:
● Software NSS mode: this mode is enabled by setting the SSM bit in the SPI_CR1
register (see Figure 209). In this mode, the external NSS pin is free for other
application uses and the internal NSS signal level is driven by writing to the SSI bit in
the SPI_CR1 register.
● Hardware NSS mode: there are two cases:
– NSS output is enabled: when the STM32F20xxx is operating as a Master and the
NSS output is enabled through the SSOE bit in the SPI_CR2 register, the NSS pin
is driven low and all the NSS pins of devices connected to the Master NSS pin see
a low level and become slaves when they are configured in NSS hardware mode.
When an SPI wants to broadcast a message, it has to pull NSS low to inform all
others that there is now a master for the bus. If it fails to pull NSS low, this means
that there is another master communicating, and a Hard Fault error occurs.
– NSS output is disabled: the multimaster capability is allowed.

 当SPI配置为hard模式后，通过检测NSS可以实现的是自身主机和从机模式的切换，而不是大多数人所认为的自动NSS。。。也就是说：在一个多SPI系统中，STM32 SPI通过NSS检测，一旦发现系统中无NSS低信号，自己就输出低，从而成为主机；当系统中有NSS低信号时（及已经有其它SPI宣布为主机），自己就配置为从机。 所谓的hard模式的NSS，实际就是为了实现多机间通信的。