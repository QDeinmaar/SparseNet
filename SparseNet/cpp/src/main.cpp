#include <iostream>
#include "flow.hpp"

using namespace std;

int main () {
    cout << "SparseNet started !" << endl;

    char ip_src[INET6_ADDRSTRLEN];
    char ip_dest[INET6_ADDRSTRLEN];

    Flow flow_test;

    flow_test.timestamp_ms = 790786531000;
    flow_test.ip_version = IPVersion::IPv4;

    inet_pton(AF_INET, "192.168.2.0", &flow_test.src_ip.ipv4);
    inet_pton(AF_INET, "104.10.32.2", &flow_test.dest_ip.ipv4);

    flow_test.src_port = 5340;
    flow_test.dest_port = 443;

    flow_test.protocol = Protocol::UDP;

    flow_test.packets = 2600;
    flow_test.bytes = 3349720;
    flow_test.duration_ms = 1000;

    cout << "--- Flow Record Captured ---\n";

    if(flow_test.ip_version == IPVersion::IPv4){
        inet_ntop(AF_INET, &flow_test.src_ip.ipv4, ip_src, sizeof(ip_src));
        inet_ntop(AF_INET, &flow_test.dest_ip.ipv4, ip_dest, sizeof(ip_dest));
    } else {
        inet_ntop(AF_INET6, &flow_test.src_ip.ipv6, ip_src, sizeof(ip_src));
        inet_ntop(AF_INET6, &flow_test.dest_ip.ipv6, ip_dest, sizeof(ip_dest));
        } 
    
    cout << "Address source : " << ip_src << "\n";
    cout << "Address destination : " << ip_dest << " \n";

    cout << "Protocol: " << GetProtocolName(flow_test.protocol) << "\n";
    cout << "Port: " << flow_test.dest_port << "\n";
    cout << "Packets: " << flow_test.packets << "\n";
    cout << "Duration (ms): " << flow_test.duration_ms << "\n";

    return 0;
}  