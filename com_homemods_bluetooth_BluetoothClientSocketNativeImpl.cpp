
#include "com_homemods_bluetooth_BluetoothClientSocketNativeImpl.h"
#include "bluetooth_helper.h"
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/l2cap.h>

/*
 * Class:     com_homemods_bluetooth_BluetoothClientSocketNativeImpl
 * Method:    connectN
 * Signature: (Ljava/lang/String;I)I
 */
JNIEXPORT jint JNICALL Java_com_homemods_bluetooth_BluetoothClientSocketNativeImpl_connectN
  (JNIEnv *env, jobject thisObj, jint socket, jstring address, jshort port) {
    struct sockaddr_l2 addr = { 0 };
    const char *addressC = env->GetStringUTFChars(address, 0);

    // set the connection parameters (who to connect to)
    addr.l2_family = AF_BLUETOOTH;
    addr.l2_psm = htobs(static_cast<unsigned short>(port));
    str2baReal( addressC, &addr.l2_bdaddr );

    env->ReleaseStringUTFChars(address, addressC);

    // connect to server
    int status = connect(socket, (struct sockaddr *)&addr, sizeof(addr));

    return status;
}

