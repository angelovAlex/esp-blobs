

void lwip_init() {
    netif_init();
    udp_init();
    tcp_init();
    igmp_init();
    dns_init();
    sys_timeouts_init();
}