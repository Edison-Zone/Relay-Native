
#include "com_homemods_relay_pi_bluetooth_BluetoothSocketNativeImpl.h"
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/l2cap.h>

/*
 * Class:     com_homemods_relay_pi_bluetooth_BluetoothSocketNativeImpl
 * Method:    readN
 * Signature: (I[BI)I
 */
JNIEXPORT jint JNICALL Java_com_homemods_relay_pi_bluetooth_BluetoothSocketNativeImpl_readN
  (JNIEnv *env, jobject thisObj, jint socket, jbyteArray bytes, jint max) {
    jbyte *arr = env->GetByteArrayElements(bytes, 0);

    int count = read(socket, arr, max* sizeof(jbyte));

    env->ReleaseByteArrayElements(bytes, arr, 0);

    return count;
}

/*
 * Class:     com_homemods_relay_pi_bluetooth_BluetoothSocketNativeImpl
 * Method:    writeN
 * Signature: (I[BI)V
 */
JNIEXPORT jint JNICALL Java_com_homemods_relay_pi_bluetooth_BluetoothSocketNativeImpl_writeN
  (JNIEnv *env, jobject thisObj, jint socket, jbyteArray bytes, jint count) {
    int status = write(socket, bytes, count);
    return status;
}

/*
 * Class:     com_homemods_relay_pi_bluetooth_BluetoothSocketNativeImpl
 * Method:    closeN
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_homemods_relay_pi_bluetooth_BluetoothSocketNativeImpl_closeN
  (JNIEnv *env, jobject thisObj, jint socket) {
    close(socket);
}
