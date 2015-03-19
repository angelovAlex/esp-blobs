


void sub_402532a4() {
    _xtos_set_exception_handler(9, sub_40101130)
    _xtos_set_exception_handler(0, sub_40101130)
    _xtos_set_exception_handler(2, sub_40101130)
    _xtos_set_exception_handler(3, sub_40101130)
    _xtos_set_exception_handler(28, sub_40101130)
    _xtos_set_exception_handler(29, sub_40101130)
    _xtos_set_exception_handler(8, sub_40101130)
    ets_install_putc1(/*off_40253244*/)
    
    if (rtc_get_reset_reason() == 4 || rtc_get_reset_reason() == 2){
        sleep_reset_analog_rtcreg_8266
    }

    read_macaddr_from_otp(*(0x3ffeaeb2))
    wifi_softap_cacl_mac(*(0x3ffeaeac),*(0x3ffeaeb2));
    wdt_eventq[2] = 0x104a8c0;
    wdt_eventq[4] = 0x104a8c0;
    wdt_eventq[3] = 0xffffff;
    ets_timer_init();
    lwip_init();
    
    //error: wrong if cond
    
    a12 = ((uint8_t *)(0x3ffe9630))[92];
    wifi_mode_set(a12);
    if (a12 == 1 || a12 == 3){
        wifi_station_start();
    }
    if (a12 == 2 || a12 == 3){
        wifi_softap_start();
    }
    if (wifi_station_get_auto_connect()){
        wifi_station_connect();
    }
    wdt_init();
    if (done_cb != 0){
        done_cb();
    }
}