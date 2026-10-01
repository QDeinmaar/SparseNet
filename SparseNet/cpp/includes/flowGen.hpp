#pragma once

#include "flow.hpp"
#include <random>

class FlowGenerator {
    private:
        std::mt19937 rng;
    
    public:
    FlowGenerator(){
        std::random_device rd;
        rng.seed(rd());
    }

    Flow generateFlow(){
        Flow f;
        f.ip_version = IPVersion::IPv4;

        std::uniform_int_distribution<uint16_t> port_dist (0, 2000);
        std::uniform_int_distribution<uint64_t> bytes_per_packet (64, 1500);
        std::uniform_int_distribution<uint64_t> packets_dist (1, 1000);
        std::uniform_int_distribution<uint32_t> duration_dist (10, 5000);

        std::uniform_int_distribution<int> proto_dist(0,2);
        switch(proto_dist(rng)){
            case 0 :
                    f.protocol = Protocol::TCP;
                    f.src_port = port_dist(rng);
                    f.dest_port = port_dist(rng);
                break;

            case 1 : 
                    f.protocol = Protocol::UDP;
                    f.src_port = port_dist(rng);
                    f.dest_port = port_dist(rng);
                break;

            case 2 : 
                    f.protocol = Protocol::ICMP;
                    f.src_port = 0;
                    f.dest_port = 0;
                break;
        }

        f.packets = packets_dist(rng);
        f.bytes =  f.packets * bytes_per_packet(rng);
        f.duration_ms = duration_dist(rng);

        std::uniform_int_distribution<uint32_t> ip_dist(0, 0XFFFFFFFF);
        f.src_ip.ipv4.s_addr = ip_dist(rng);
        f.dest_ip.ipv4.s_addr = ip_dist(rng);

        return f;
    }     
};