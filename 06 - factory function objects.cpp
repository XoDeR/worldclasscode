#include <string>
#include <iostream>

using namespace std::literals;

struct TCPConnection {
	void send(const char *s) { std::cout << "TCP: " << s << '\n'; }
};

struct UDPConnection {
	void send(const char *s) { std::cout << "UDP: " << s << '\n'; }
};

struct TCPConnectionFactory {
	TCPConnection operator()() { return TCPConnection(); }
};

struct UDPConnectionFactory {
	UDPConnection operator()() { return UDPConnection(); }
};

template <class ConnectionFactory>
void send(ConnectionFactory &conFactory) {
	auto con = conFactory();
	con.send("Hello");
}

int main(int argc, char *argv[]) {
	if (argc > 1 && argv[1] == "tcp"s) {
		TCPConnectionFactory factory;
		send(factory);
	}
	else {
		UDPConnectionFactory factory;
		send(factory);
	}
}
