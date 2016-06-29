SnapRoute ASIC Daemon 
========================

More documentation is available at 
[Product Overview] (http://opensnaproute.github.io/docs/)

Complete system architecture can be found 
[Here](http://opensnaproute.github.io/docs/architecture.html) 


![alt text](https://github.com/OpenSnaproute/asicd/blob/master/Asic_Daemon.jpg "High level architecture diagram")

##Overview
Snaproute's asic daemon serves as a hardware abstraction layer (HAL). A common northbound API interface is exposed to all protocol daemons. This interface allows provisioning a range of packet processing ASICs such as Broadcom, Mellanox, Cavium. Support for software simulation on a linux host OS is also provided.

##Software Architecture
####Northbound interface :
The asic daemons northbound interface is implemented using thrift RPC. This is the interface that is used by users/protocols to apply configuration.

####Core resource managers :
The core infrastructure within Asicd is distributed across multiple resource managers, e.x. portMgr.go, routeMgr.go, neighborMgr.go etc. Each of these individual resource managers support Create/Retrieve/Update and Delete operations on the corresponding resource. These resource managers also maintain any relevant state data for each corresponding resource.

####Plugins :
The asic daemon uses a plugin based approach to effectively abstract differences between ASICs from multiple vendors. The following plugins and asic vendors are currently supported
- Vendor SDK (Broadcom)
- SAI (Mellanox, Barefoot)
- Softswitch (Linux host)

####Events handling :
The asicd daemon supports signaling/notification of asynchronous events. The notification engine employs a nano message based publisher. Notifications for the following events are supported
- Port operational state changes
- Vlan/Lag interface creation/deletion
- IP interface operational state changes
