//
//Copyright [2016] [SnapRoute Inc]
//
//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
//	 Unless required by applicable law or agreed to in writing, software
//	 distributed under the License is distributed on an "AS IS" BASIS,
//	 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//	 See the License for the specific language governing permissions and
//	 limitations under the License.
//
// _______  __       __________   ___      _______.____    __    ____  __  .___________.  ______  __    __
// |   ____||  |     |   ____\  \ /  /     /       |\   \  /  \  /   / |  | |           | /      ||  |  |  |
// |  |__   |  |     |  |__   \  V  /     |   (----` \   \/    \/   /  |  | `---|  |----`|  ,----'|  |__|  |
// |   __|  |  |     |   __|   >   <       \   \      \            /   |  |     |  |     |  |     |   __   |
// |  |     |  `----.|  |____ /  .  \  .----)   |      \    /\    /    |  |     |  |     |  `----.|  |  |  |
// |__|     |_______||_______/__/ \__\ |_______/        \__/  \__/     |__|     |__|      \______||__|  |__|
//

#ifndef PLUGIN_MGR_H
#define PLUGIN_MGR_H
#include <stdint.h>
#define LENOF(st) ((sizeof(st))/(sizeof(st[0])))
#define MAX_NUM_PORTS 256
#define MAX_CMD_SIZE 128
#define MAC_ADDR_LEN 6
#define DEFAULT_VLAN_ID 4095
#define CPU_VLAN_ID 4095
#define ALL_INTERFACES -1
#define NETIF_NAME_LEN_MAX 16
#define BOOT_MODE_COLDBOOT 0
#define BOOT_MODE_WARMBOOT 1
#define MAX_PORT_NAME_LEN 16
#define MAX_PORT_DESC_LEN 128
#define MAX_VLAN_ID 4096
#define MAX_IF_TYPE_ENUM 128
#define MAX_MEDIA_TYPE_ENUM 64
#define MAX_DUPLEX_TYPE_ENUM 3
#define NEIGHBOR_TYPE_COPY_TO_CPU 0x1
#define NEIGHBOR_TYPE_BLACKHOLE 0x2
#define NEIGHBOR_TYPE_FULL_SPEC_NEXTHOP 0x4
#define NEIGHBOR_L2_ACCESS_TYPE_PORT 0x8
#define NEIGHBOR_L2_ACCESS_TYPE_LAG 0x10
#define NEIGHBOR_TYPE_VXLAN 0x20
#define NEXTHOP_TYPE_COPY_TO_CPU 0x1
#define NEXTHOP_TYPE_BLACKHOLE 0x2
#define NEXTHOP_TYPE_FULL_SPEC_NEXTHOP 0x4
#define NEXTHOP_L2_ACCESS_TYPE_PORT 0x8
#define NEXTHOP_L2_ACCESS_TYPE_LAG 0x10
#define INTF_STATE_DOWN 0
#define INTF_STATE_UP 1
#define ALL_ZEROS_MAC_ADDR {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
#define LACP_MAC_ADDR {0x01, 0x80, 0xc2, 0x00, 0x00, 0x02}
#define INVALID_OBJECT_ID 0xFFFFFFFFFFFFFFFF
#define MAC_ENTRY_LEARNED 0x1
#define MAC_ENTRY_AGED 0x2
#define ROUTE_TYPE_CONNECTED 0x00000001
#define ROUTE_TYPE_SINGLEPATH 0x00000002
#define ROUTE_TYPE_MULTIPATH 0x00000004
#define ROUTE_OPERATION_TYPE_UPDATE 0x00000008
#define MAX_NEXTHOPS_PER_GROUP 32
#define INTF_TYPE_MASK 0x7f000000
#define INTF_TYPE_SHIFT 24
#define INTF_ID_MASK 0xffffff
#define INTF_ID_SHIFT 0
#define INTF_ID_FROM_IFINDEX(ifIndex) ((ifIndex & INTF_ID_MASK) >> INTF_ID_SHIFT)
#define INTF_TYPE_FROM_IFINDEX(ifIndex) ((ifIndex & INTF_TYPE_MASK) >> INTF_TYPE_SHIFT)
#define IFINDEX_FROM_IF_ID_TYPE(id, type) ((id & INTF_ID_MASK)|((type << INTF_TYPE_SHIFT) & INTF_TYPE_MASK))
#define MAX_NEXTHOPS_PER_ECMP_ROUTE 32
#define VXLAN_UDP_DEST_PORT 4789

#define	PORT_PROTOCOL_ARP 		0x1
#define	PORT_PROTOCOL_DHCP 		0x2
#define	PORT_PROTOCOL_DHCP_RELAY 	0x4
#define	PORT_PROTOCOL_BGP 		0x8
#define	PORT_PROTOCOL_OSPF 		0x10
#define	PORT_PROTOCOL_VXLAN 		0x20
#define	PORT_PROTOCOL_MPLS		0x40
#define	PORT_PROTOCOL_BFD 		0x80

//Port attribute update flags
#define PORT_ATTR_PHY_INTF_TYPE 0x00000001
#define PORT_ATTR_ADMIN_STATE   0x00000002
#define PORT_ATTR_MAC_ADDR      0x00000004
#define PORT_ATTR_SPEED         0x00000080
#define PORT_ATTR_DUPLEX        0x00000010
#define PORT_ATTR_AUTONEG       0x00000020
#define PORT_ATTR_MEDIA_TYPE    0x00000040
#define PORT_ATTR_MTU           0x00000080
#define PORT_ATTR_BREAKOUT_MODE 0x00000100
//Port breakout modes
#define PORT_BREAKOUT_MODE_UNSUPPORTED 0
#define PORT_BREAKOUT_MODE_1x40  0x00000001
#define PORT_BREAKOUT_MODE_4x10  0x00000002
#define PORT_BREAKOUT_MODE_1x100 0x00000004
/* STP STATE definitions */
enum stpPortStates {
    StpPortStateBlocking = 0,
    StpPortStateLearning,
    StpPortStateForwarding,
    StpPortStateCount
};

enum hashTypes {
    HASHTYPE_SRCMAC_DSTMAC = 0,
    HASHTYPE_SRCIP_DSTIP = 6,
    HASHTYPE_END
};
enum mediaType {
    MediaTypeCount
};
enum duplexType {
    HalfDuplex = 0,
    FullDuplex,
    DuplexCount
};
enum portIfType {
    PortIfTypeMII,
    PortIfTypeGMII,
    PortIfTypeSGMII,
    PortIfTypeQSGMII,
    PortIfTypeSFI,
    PortIfTypeXFI,
    PortIfTypeXAUI,
    PortIfTypeXLAUI,
    PortIfTypeRXAUI,
    PortIfTypeCR,
    PortIfTypeCR2,
    PortIfTypeCR4,
    PortIfTypeKR,
    PortIfTypeKR2,
    PortIfTypeKR4,
    PortIfTypeSR,
    PortIfTypeSR2,
    PortIfTypeSR4,
    PortIfTypeSR10,
    PortIfTypeLR,
    PortIfTypeLR4,
    PortIfTypeCount
};
enum portStatTypes {
    IfInOctets = 0,
    IfInUcastPkts,
    IfInDiscards,
    IfInErrors,
    IfInUnknownProtos,
    IfOutOctets,
    IfOutUcastPkts,
    IfOutDiscards,
    IfOutErrors,
    portStatTypesMax
};

typedef struct ifMapInfo_s {
    char *ifName;
    int port;
} ifMapInfo_t;
typedef struct portConfig_s {
    uint8_t portNum;
    enum portIfType ifType;
    uint8_t adminState;
    uint8_t macAddr[MAC_ADDR_LEN];
    uint32_t portSpeed;
    enum duplexType duplex;
    uint8_t autoneg;
    enum mediaType media;
    int mtu;
    uint32_t breakOutMode;
    uint8_t isBreakOutSupported;
    uint8_t mappedToHw;
    uint8_t logicalPortInfo;
} portConfig;
typedef struct portState_s {
    uint8_t portNum;
    uint8_t operState;
    char portName[MAX_PORT_NAME_LEN];
    uint64_t stats[portStatTypesMax];
} portState;
typedef struct portBreakOutInfo_s {
    uint8_t logPortNum;
    uint8_t parentPort;
    uint32_t breakOutMode;
    uint8_t totalNumSubPorts;
} portBreakOutInfo_t;
#endif //PLUGIN_MGR_H
