#ifndef SLIRP4NETNS_H
# define SLIRP4NETNS_H
#include <arpa/inet.h>

struct hostfwd_t {
	bool is_udp;
	struct in_addr hostaddr;
	uint16_t hostport;
	struct in_addr guestaddr;
	uint16_t guestport;
};

struct slirp_config {
	unsigned int mtu;
	struct in_addr vnetwork; // 10.0.2.0
	struct in_addr vnetmask; // 255.255.255.0
	struct in_addr vhost; // 10.0.2.2
	struct in_addr vdhcp_start; // 10.0.2.15
	struct in_addr vnameserver; // 10.0.2.3
	struct in_addr recommended_vguest; // 10.0.2.100 (slirp itself is unaware of vguest)
	bool enable_ipv6;
	int hostfwd_count;
	struct hostfwd_t *forwards;
	bool disable_host_loopback;
};
int do_slirp(int tapfd, int exitfd, const char *api_socket, struct slirp_config *cfg);

#endif
