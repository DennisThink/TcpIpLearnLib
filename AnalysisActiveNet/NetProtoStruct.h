#ifndef _DENNIS_THINK_TCP_IP_NET_PROTO_STRUCT_H_
#define _DENNIS_THINK_TCP_IP_NET_PROTO_STRUCT_H_
//Mac地址头部
struct MacAddrHeader
{
    unsigned char mDestMacAddr[6];
    unsigned char mSrcMacAddr[6];
    unsigned short m_type;
};

#endif