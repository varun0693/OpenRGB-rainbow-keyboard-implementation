#!/bin/bash

echo "Stopping Rainbow..."
killall rainbow_driver 2>/dev/null

# Optional: Set lights to off or a static color immediately after stopping, in this case whitw
openrgb --mode direct --color FFFFFF > /dev/null 2>&1
