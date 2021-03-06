
#include "com_homemods_bluetooth_BluetoothServerSocketNativeImpl.h"
#include "bluetooth_helper.h"
#include <unistd.h>
#include <cerrno>
#include <bluetooth/l2cap.h>

/*
 * Class:     com_homemods_bluetooth_BluetoothServerSocketNativeImpl
 * Method:    listenN
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_homemods_bluetooth_BluetoothServerSocketNativeImpl_listenN
  (JNIEnv *env, jobject thisObj, jint socket) {
    int result = listen(socket, 1);

    if (result == -1) { //If failed
	printf("listen failed\n");
        checkError(errno);
    }

}

/*
 * Class:     com_homemods_bluetooth_BluetoothServerSocketNativeImpl
 * Method:    acceptConnectionN
 * Signature: (I)V
 */
JNIEXPORT jint JNICALL Java_com_homemods_bluetooth_BluetoothServerSocketNativeImpl_acceptConnectionN
  (JNIEnv *env, jobject thisObj, jint socket) {
    struct sockaddr_l2 rem_addr = { 0 };
    socklen_t opt = sizeof(rem_addr);
    char buf[1024] = { 0 };

    int client = accept(socket, (struct sockaddr *)&rem_addr, &opt);

    if (client == -1) { //If failed
	printf("accept failed\n");
        checkError(errno);
    }

    ba2strReal( &rem_addr.l2_bdaddr, buf);

    jstring name = env->NewStringUTF(buf);
    env->SetObjectField(thisObj, env->GetFieldID(env->GetObjectClass(thisObj), "connectionName", "Ljava/lang/String;"), name);

    return client;
}

/*
 * Class:     com_homemods_bluetooth_BluetoothServerSocketNativeImpl
 * Method:    closeN
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_homemods_bluetooth_BluetoothServerSocketNativeImpl_closeN
  (JNIEnv *env, jobject thisObj, jint socket) {
    close(socket);
}
