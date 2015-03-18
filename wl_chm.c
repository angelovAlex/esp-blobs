


bool chm_check_same_channel() {
    int a4 = ieee80211_chan2ieee(g_ic[83]);
    int a2 = ieee80211_chan2ieee(chm_get_current_channel());
    return (a4 == a2) ? 1 : 0;
}