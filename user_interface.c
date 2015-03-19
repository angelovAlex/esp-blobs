

uint8_t wifi_get_channel() {
    int *a2 = chm_get_current_channel();
    return ((uint8_t *)a2)[6];
}

int wifi_get_phy_mode() {
    int *a2 = (int *)0x3ffe96e0;
    return a2[186];
}

bool wifi_set_channel(a2) {
    if (a2 >= 0xE) return 0;
    chm_set_current_channel(g_ic + 0x78 + a2*12);
    return 1;
}

void wifi_set_promiscuous_rx_cb(a2) {
    ((int *)0x3ffeaef0)[59] = a2;
}