
void ieee80211_proto_attach(ic) {
    ic[3] = 1;
    ic[7] = ic[7] | 0x40000;
    ppRegisterTxCallback(ieee80211_tx_mgt_cb, 2);
}