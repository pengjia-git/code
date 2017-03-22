#!/bin/bash
AP_SSID=`cat /tmp/fuse_a/apk_serial`
if [ -z "${AP_SSID}" ]; then
	echo "AP_SSID is null"
fi
