#include <iostream>

#include "flow.hpp"
#include "flowGen.hpp"

using namespace std;

int main () {
    FlowGenerator generator;

    for (int i = 1; i <= 10; i++) {
        Flow random_flow = generator.generateFlow(); 

        cout << "Flow #" << i << "\n";
        cout << " Protocol: " << GetProtocolName(random_flow.protocol) << "\n";
        cout << "  Source Port: " << random_flow.src_port << "\n";
        cout << "  Dest Port: " << random_flow.dest_port << "\n";
        cout << "  Packets: " << random_flow.packets << "\n";
        cout << "  Bytes: " << random_flow.bytes << "\n";
        cout << "  Duration: " << random_flow.duration_ms << "\n";
        cout << "---------------------------\n";
    }

    return 0;
}  