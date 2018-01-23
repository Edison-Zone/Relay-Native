
#include "com_homemods_bluetooth_BluetoothClientNativeImpl.h"
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/l2cap.h>

/*
 * Class:     com_homemods_bluetooth_BluetoothClientNativeImpl
 * Method:    allocSocket
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_homemods_bluetooth_BluetoothClientNativeImpl_allocSocket
  (JNIEnv *env, jobject thisObj) {
    int s = socket(AF_BLUETOOTH, SOCK_SEQPACKET, BTPROTO_L2CAP);

    return s;
}
