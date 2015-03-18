

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

int send_nulldata(a2){
    
    a3 = 0x18
    if (a2[30][2] & 0x42) { a3 = 0x1A }
    int a2_;
    _a2 = ieee80211_getmgtframe(a2_, a3, 0)
    if (_a2 == 0)
    {
        return 1;
    } else {
        ((int16_t *)_a2)[10] = a3
        if (a2[30][2] & 0x2)
        {
            __a2 = ieee80211_send_setup(a2, _a2, 0x48, 0x10, (a2[0] + 0x27), (a2 + 0x30), a2[30][2])
        } else {
            __a2 = ieee80211_send_setup(a2, _a2, 0xC8, 0, (a2[0] + 0x27), (a2 + 0x30), a2[30][2])
            ((int8_t *)_a2[4])[24] = 0
            if (((int8_t *)a2[30])[105] != 0)
            {
                ((int8_t *)_a2[4])[24] = 0x20
            }
            ((int8_t *)_a2[4])[25] = 0
        }
        
        if (a2[30][2] & 0x10)
        {
            ((int8_t *)_a2[4])[1] |= 0x10
        }
        
        if ((g_ic[4] - a2) != 0) { a2 = 1 }
        if (a2 == 0)
        {
            a3 = 0
        } else {
            a3 = ((int16_t *)a2[30])[13]
        }
        
        ((int8_t *)_a2[8])[6] &= 0x8F
        ((int8_t *)_a2[8])[6] |= a2[0]
        ((int8_t *)_a2[8])[4] &= 0xF0
        ((int8_t *)_a2[8])[0] &= 0xFE
        
        _a2[8][4] = *(0x3ff20a00)[128]
        ((int8_t *)_a2[8])[0] &= 0xFD
        ((int8_t *)_a2[8])[0] |= ((a2 & 0x1) << 1)
        if (((int16_t *)a2[30])[13] && !(_a2[8][0] & 0x80)) {
            rc_get_trc_by_index(a3 & 0xff)
        }
        _a2[6] = a2
        if (chm_check_same_channel())
        {
            return ppTxPkt(_a2)
        } else {
            _a2[7] = 0
            g_ic[113][0] = _a2
            g_ic[113] = (_a2 + 0x1C)
            return 0
        }
    }
}