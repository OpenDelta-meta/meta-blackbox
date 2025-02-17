SUMMARY = "Hardware drivers for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"
require conf/license/license-close.inc

PACKAGE_ARCH = "${MACHINE_ARCH}"

SRC_URI = "http://source.mynonpublic.com/unibox/linuxdvb_7405-${KV}-${SRCDATE}.tar.gz"


PV = "${KV}+${SRCDATE}"

S = "${WORKDIR}"

INHIBIT_PACKAGE_STRIP = "1"

do_compile() {
}

do_populate_sysroot() {
}

do_install() {
    install -d ${D}${nonarch_base_libdir}/modules/${KV}/extra
    install -d ${D}${sysconfdir}/modules-load.d
    for i in linuxdvb; do
        install -m 0755 ${WORKDIR}/$i.ko ${D}${nonarch_base_libdir}/modules/${KV}/extra
        echo $i >> ${D}${sysconfdir}/modules-load.d/_${MACHINE}.conf
    done
}

FILES_${PN} += "${sysconfdir}/modules-load.d/_${MACHINE}.conf ${nonarch_base_libdir}/modules/${KV}/extra"
