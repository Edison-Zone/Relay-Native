

if(WIN32 OR APPLE OR NOT UNIX)
    message(STATUS "Platform not supported by Bluez - using provided implementation")
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/cmake/bluez)
    return()
else()
    set(bluez_dir bluez)

    set(bluez_src ${bluez_dir}/attrib/att.c
                    ${bluez_dir}/attrib/gatt.c
                    ${bluez_dir}/attrib/gattrib.c
                    ${bluez_dir}/btio/btio.c
                    ${bluez_dir}/lib/bluetooth.c
                    ${bluez_dir}/lib/hci.c
                    ${bluez_dir}/lib/sdp.c
                    ${bluez_dir}/lib/uuid.c
                    ${bluez_dir}/src/log.c
                    ${bluez_dir}/src/shared/queue.c
                    ${bluez_dir}/src/shared/util.c
                    ${bluez_dir}/src/shared/mgmt.c
                    ${bluez_dir}/src/shared/crypto.c
                    ${bluez_dir}/src/shared/ecc.c
                    ${bluez_dir}/src/shared/ringbuf.c
                    ${bluez_dir}/src/shared/tester.c
                    ${bluez_dir}/src/shared/hci.c
                    ${bluez_dir}/src/shared/hci-crypto.c
                    ${bluez_dir}/src/shared/hfp.c
                    ${bluez_dir}/src/shared/uhid.c
                    ${bluez_dir}/src/shared/pcap.c
                    ${bluez_dir}/src/shared/btsnoop.c
                    ${bluez_dir}/src/shared/ad.c
                    ${bluez_dir}/src/shared/att.c
                    ${bluez_dir}/src/shared/gatt-helpers.c
                    ${bluez_dir}/src/shared/gatt-client.c
                    ${bluez_dir}/src/shared/gatt-server.c
                    ${bluez_dir}/src/shared/gatt-db.c
                    ${bluez_dir}/src/shared/gap.c
                    ${bluez_dir}/src/shared/io-glib.c
                    ${bluez_dir}/src/shared/timeout-glib.c)

    include_directories(${bluez_dir} ${bluez_dir}/attrib ${bluez_dir}/btio ${bluez_dir}/lib)
    link_directories(${bluez_dir} ${bluez_dir}/attrib ${bluez_dir}/btio ${bluez_dir}/lib)
endif()