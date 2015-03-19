

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