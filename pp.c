

/*
 lmacRxDone - pp_post(5)
 lmacDiscardAgedMSDU - pp_post(4)
 ppDiscardMPDU - pp_post(4)
 ppCheckTxIdle - pp_post(8)
 ppProcessTxQ - pp_post(8)
 ppProcessWaitQ - pp_post(???)
 ppTxPkt - pp_post(???)
*/
void pp_post(a2) {
    ets_intr_lock();
    uint8_t *ptr = (uint8_t *)(0x3ffec620 + a2);
    if (ptr[0] != 0)
    {
        ets_intr_unlock();
    } else {
        ptr[0] = ptr[0] + 1;
        ets_intr_unlock();
        ets_post();
    }
}

/*
 ieee80211_proto_attach - ppRegisterTxCallback(ieee80211_tx_mgt_cb, 2)
 cnx_attach - ppRegisterTxCallback(sub_40244864, 0)
 wpa_attach - ppRegisterTxCallback(eapol_txcb, 3)
 pm_attach - ppRegisterTxCallback(loc_402567d8, 5), ppRegisterTxCallback(loc_402568a8, 6)
 ieee80211_hostap_attach - ppRegisterTxCallback(loc_402589c0, 4)
*/
void ppRegisterTxCallback(a2, a3) {

    uint8_t a5 = ((int8_t *)(noise_now[1] + 0xb8))[128]
    if (!((a5 >> a3) & 0x1)){
        ((int8_t *)(noise_now[1] + 0xb8))[128] = (1 << a3) | a5
        (noise_now[1] + a3*4)[79] = a2
        return 0
    }
    return 1
}

int ppTxPkt(a2) {

    a3 = (((int8_t *)a2[8])[6] >> 4) & 0x7
    a0 = ((int8_t *)a2[8])[4] & 0xf
    if (a0 == 0 || a0 == 3) {
        a2 = 2
    } else {
        if (a0 < 3)
        {
            a2 = 3
        } else {
            a2 = 1
            if (a0 < 6)
            {
                a2 = 0
            }
        }
    }
    
    if (a2 != a3)
    {
        os_printf("%s %u\n", "pp.c", 0x146)
        while(true){}
    }
    
    //failed
    /*
    block - (if_cond,loc_40257366)
    |  loc_402573BF
    |  |  loc_402573BF - second
    |  |  |  block - (if_cond,loc_402573FC)
    |  |  |  |  loc_402573FE
    |  |  |  |  |  block - (if_cond,loc_402573BA)
    |  |  |  if_or_expr
    |  |  |  |  loc_40257404 - second - second
    |  |  |  |  |  loc_402573FE
    |  |  |  |  |  |  block - (if_cond,loc_402573BA)
    |  |  |  |  block - (if_cond,loc_402573BA)
    |  |  loc_402573A5
    |  |  |  block - (if_cond,loc_402573BA)
    |  if_cond
    |  |  loc_402573A5
    |  |  |  block - (if_cond,loc_402573BA)\
    */
    movi.n     a4, 2            // a4 = 2            (HIDE)
    movi.n     a9, 0xC            // a9 = 0xC            (HIDE)
    addi     a1, a1, 0xF0            // a1 = a1 + 0xF0            (HIDE)
    s32i.n     a0, a1, 0            // (a1 + 0xF0)[0] = a0
    l32i.n     a7, a2, 0x10            // a7 = a2[4]            (HIDE)
    l32i.n     a5, a2, 0x20            // a5 = a2[8]            (HIDE)
    l8ui     a3, a7, 4            // a3 = ((int8_t *)a2[4])[4]
    l32i.n     a0, a5, 0            // a0 = a2[8][0]
    if (((int8_t *)a2[4])[4] & 0x1)
    {
        srli     a3, a0, 6
        extui     a0, a0, 0, 6            // a0 = (a2[8][0] >> 0) & 0x3f            (HIDE)
        or     a3, a3, a4            // a3 = ((int8_t *)a2[4])[4] | 2            (HIDE)
        slli     a3, a3, 6            // a3 = (((int8_t *)a2[4])[4] | 2) << 6
        or     a0, a0, a3            // a0 = ((a2[8][0] >> 0) & 0x3f) | ((((int8_t *)a2[4])[4] | 2) << 6)
        s32i.n     a0, a5, 0            // a2[8][0] = (((a2[8][0] >> 0) & 0x3f) | ((((int8_t *)a2[4])[4] | 2) << 6))
    }
    
    l8ui     a8, a7, 0            // a8 = ((int8_t *)a2[4])[0]            (HIDE)
    movi     a6, 0xF0            // a6 = 0xF0            (HIDE)
    and     a4, a8, a9            // a4 = ((int8_t *)a2[4])[0] & 0xC
    and     a6, a8, a6            // a6 = ((int8_t *)a2[4])[0] & 0xF0            (HIDE)
    bnei     a4, 8, loc_402573BF
    extui     a8, a0, 0, 6            // a8 = (a0 >> 0) & 0x3f            (HIDE)
    movi.n     a3, 8            // a3 = 8            (HIDE)
    srli     a0, a0, 6
    or     a0, a0, a3            // a0 = a0 | 8            (HIDE)
    slli     a0, a0, 6            // a0 = (a0 | 8) << 6            (HIDE)
    or     a0, a8, a0            // a0 = ((a0 >> 0) & 0x3f) | ((a0 | 8) << 6)            (HIDE)
    s32i.n     a0, a5, 0            // a2[8][0] = (((a0 >> 0) & 0x3f) | ((a0 | 8) << 6))
    if (beqi     a6, 0x40, loc_40257391)
    {
        movi     a4, 0xC0            // a4 = 0xC0
        bne     a6, a4, loc_402573A5
    }
    
    extui     a6, a0, 0, 6            // a6 = ((((a0 >> 0) & 0x3f) | ((a0 | 8) << 6)) >> 0) & 0x3f            (HIDE)
    l32r     a3, dword_40256C64            // a3 = *(dword_40256C64)            (HIDE)
    srli     a0, a0, 6
    and     a0, a0, a3            // a0 = (((a0 >> 0) & 0x3f) | ((a0 | 8) << 6)) & *(dword_40256C64)            (HIDE)
    slli     a0, a0, 6            // a0 = ((((a0 >> 0) & 0x3f) | ((a0 | 8) << 6)) & *(dword_40256C64)) << 6            (HIDE)
    or     a0, a6, a0            // a0 = (((((a0 >> 0) & 0x3f) | ((a0 | 8) << 6)) >> 0) & 0x3f) | (((((a0 >> 0) & 0x3f) | ((a0 | 8) << 6)) & *(dword_40256C64)) << 6)            (HIDE)
    s32i.n     a0, a5, 0            // a2[8][0] = ((((((a0 >> 0) & 0x3f) | ((a0 | 8) << 6)) >> 0) & 0x3f) | (((((a0 >> 0) & 0x3f) | ((a0 | 8) << 6)) & *(dword_40256C64)) << 6))
    
    srli     a4, a0, 6
    
    l32i.n     a0, a1, 0            // a0 = a0            (HIDE)
    if (a4 & 0x1)
    {
        l32i.n     a5, a2, 4            // a5 = a2[1]            (HIDE)
        l16ui     a4, a7, 0x16            // a4 = ((int16_t *)a2[4])[11]            (HIDE)
        l32i.n     a5, a5, 4            // a5 = a2[1][1]
        srli     a4, a4, 4
        s8i     a4, a5, 3            // ((int8_t *)a2[1][1])[3] = ((int16_t *)a2[4])[11]
    }
    
    addi     a1, a1, 0x10            // a1 = (a1 + 0xF0) + 0x10            (HIDE)

    
}