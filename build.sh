#!/bin/bash
# top-level build.sh for smartclock

source shared.sh


EXTERNAL_REL=resources/packages
DEFCONFIG_NAME=raspberrypi4_lvgl_defconfig
DEFCONFIG_SRC=resources/configs/${DEFCONFIG_NAME}
OVERLAY_DIR=resources/board/rootfs_overlay

git submodule init
git submodule sync
git submodule update
set -e
cd "$(dirname "$0")"

# Copy defconfig into buildroot/configs
if [ ! -f "$DEFCONFIG_SRC" ]; then
  echo "ERROR: defconfig not found at $DEFCONFIG_SRC" >&2
  exit 1
fi
cp "$DEFCONFIG_SRC" buildroot/configs/$DEFCONFIG_NAME
echo "Installed defconfig to buildroot/configs/$DEFCONFIG_NAME"

# Run Buildroot
if [ ! -e buildroot/.config ]; then
  echo "Generating .config from $DEFCONFIG_NAME"
  make -C buildroot defconfig \
       BR2_EXTERNAL=$EXTERNAL_REL \
       BR2_DEFCONFIG=$DEFCONFIG_NAME \
       BR2_ROOTFS_OVERLAY=$OVERLAY_DIR
else
  echo "Reusing existing .config--rebuilding"
  make -C buildroot \
       BR2_EXTERNAL=$EXTERNAL_REL \
       BR2_ROOTFS_OVERLAY=$OVERLAY_DIR
fi

