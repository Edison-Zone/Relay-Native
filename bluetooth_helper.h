//
// Created by Sergey Savelyev on 1/17/18.
//

#ifndef EDISONNATIVE_BLUETOOTH_HELPER_H
#define EDISONNATIVE_BLUETOOTH_HELPER_H

#include <bluetooth/bluetooth.h>
#include <cstdlib>

extern "C" {
    int ba2strReal(const bdaddr_t *ba, char *str);

    int str2baReal(const char *str, bdaddr_t *ba);
}

#endif //EDISONNATIVE_BLUETOOTH_HELPER_H
