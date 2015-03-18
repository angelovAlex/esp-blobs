

void wDevDisableRx() {
    int *a3 = 0x3ff1fe00;
    a3[129] = a3[129] & 0x7fffffff;
}

void wDevEnableRx() {
    int *ptr = 0x3ff1fe00;
    a3[129] = a3[129] | 0x80000000;
}

void wDevForceAck6M(a2) {
    int *a4 = 0x3ff20200;
    if (a2) {
        a4[131] = 0x70b00;
    } else {
        a4[131] = 0x70c07;
    }
}

void wDevClearBssid(a2) {
    int *a5 = 0x3ff20a00;
    if (a2){
        a5[145] = a5[145] & 0xfffeffff;
    } else {
        a5[143] = a5[143] & 0xfffeffff;
    }
}

void wDev_ClearTxqCollisions() {
    int *a3 = 0x3ff20a00;
    a3[176] = a3[176] & 0xfffff000;
}