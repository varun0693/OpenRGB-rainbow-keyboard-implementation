#!/bin/bash

# 1. Start OpenRGB Server
# We check if it's running first so we don't open it twice.
if ! pgrep -x "openrgb" > /dev/null
then
    echo "Starting OpenRGB Server..."
    openrgb --server --startminimized > /dev/null 2>&1 &
    sleep 3  # Give it a moment to wake up
fi

# 2. Kill any old rainbow instance
killall rainbow_driver 2>/dev/null

# 3. Start the Rainbow Driver in the background
echo "Starting Rainbow Loop..."
/home/varun/rbowdriver/rainbow_driver > /dev/null 2>&1 &

echo "Rainbow is ON."
