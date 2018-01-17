//
// Created by Sergey Savelyev on 1/17/18.
//

#ifndef EDISONNATIVE_BLUETOOTH_HELPER_H
#define EDISONNATIVE_BLUETOOTH_HELPER_H

#include <bluetooth/bluetooth.h>
#include <cstdlib>

extern "C" {
    int ba2strReal(const bdaddr_t *ba, char *str)
    {
        return sprintf(str, "%2.2X:%2.2X:%2.2X:%2.2X:%2.2X:%2.2X",
                       ba->b[5], ba->b[4], ba->b[3], ba->b[2], ba->b[1], ba->b[0]);
    }

    int str2baReal(const char *str, bdaddr_t *ba)
    {
        int i;

        if (bachk(str) < 0) {
            memset(ba, 0, sizeof(*ba));
            return -1;
        }

        for (i = 5; i >= 0; i--, str += 3)
            ba->b[i] = strtol(str, NULL, 16);

        return 0;
    }
};

#endif //EDISONNATIVE_BLUETOOTH_HELPER_H
