


bool chm_check_same_channel() {
    int a4 = ieee80211_chan2ieee(g_ic[83]);
    int a2 = ieee80211_chan2ieee(chm_get_current_channel());
    return (a4 == a2) ? 1 : 0;
}

int chm_get_current_channel() {
    int *a2 = (int *)0x3ffe9abc;
    return a2[13];
}