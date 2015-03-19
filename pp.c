

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

