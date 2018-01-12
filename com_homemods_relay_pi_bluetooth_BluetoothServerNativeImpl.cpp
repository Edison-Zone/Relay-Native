
#include "com_homemods_relay_pi_bluetooth_BluetoothServerNativeImpl.h"
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/l2cap.h>

/*
 * Class:     com_homemods_relay_pi_bluetooth_BluetoothServerNativeImpl
 * Method:    allocSocket
 * Signature: (S)I
 */
JNIEXPORT jint JNICALL Java_com_homemods_relay_pi_bluetooth_BluetoothServerNativeImpl_allocSocket
  (JNIEnv *env, jobject thisObj, jshort port) {
    struct sockaddr_l2 loc_addr = { 0 }, rem_addr = { 0 };
    int s;

    // allocate socket
    s = socket(AF_BLUETOOTH, SOCK_SEQPACKET, BTPROTO_L2CAP);

    // bind socket to port 0x1001 of the first available
    // bluetooth adapter
    loc_addr.l2_family = AF_BLUETOOTH;
    loc_addr.l2_bdaddr = {{0, 0, 0, 0, 0, 0}};
    loc_addr.l2_psm = htobs(static_cast<unsigned short>(port));

    bind(s, (struct sockaddr *)&loc_addr, sizeof(loc_addr));

    return s;
}
