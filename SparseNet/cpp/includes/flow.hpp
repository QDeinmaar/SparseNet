#pragma once

#include <cstdint>
#include <string>

#if defined(_WIN32)
    #include <winsock2.h>
    #include <ws2tcpip.h>
#else
    #include <netinet/in.h>
#endif

enum class  Protocol { TCP, UDP, ICMP };
enum class IPVersion : uint8_t { IPv4 = 4, IPv6 = 6 };

struct Flow
{
    uint64_t timestamp_ms;

    IPVersion ip_version;
    union 
    {
        struct in_addr ipv4;
        struct in6_addr ipv6;
    } src_ip, dest_ip;

    uint16_t src_port;
    uint16_t dest_port;

    uint64_t bytes;
    uint64_t packets;
    uint32_t duration_ms;

    Protocol protocol;
};

// function to get The Protocol

inline std::string GetProtocolName(Protocol p) {
    switch(p){
        case Protocol::TCP: return "TCP";
        case Protocol::UDP: return "UDP";
        case Protocol::ICMP: return "ICMP";

        default: return "Unknown";
    }
}