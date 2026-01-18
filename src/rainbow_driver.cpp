#include "OpenRGB/Client.hpp"
#include <iostream>
#include <thread>
#include <cmath>
#include <vector>

using namespace orgb;
using namespace std::chrono;

// Helper to convert HSV to RGB
Color HSVtoColor(float H, float S, float V) {
    float r, g, b;
    int i = int(H * 6);
    float f = H * 6 - i;
    float p = V * (1 - S);
    float q = V * (1 - f * S);
    float t = V * (1 - (1 - f) * S);

    switch (i % 6) {
        case 0: r = V; g = t; b = p; break;
        case 1: r = q; g = V; b = p; break;
        case 2: r = p; g = V; b = t; break;
        case 3: r = p; g = q; b = V; break;
        case 4: r = t; g = p; b = V; break;
        case 5: r = V; g = p; b = q; break;
    }
    return Color((unsigned char)(r * 255), (unsigned char)(g * 255), (unsigned char)(b * 255));
}

int main() {
    // 1. Connect to OpenRGB Server
    Client client("Rainbow Driver");
    std::cout << "Connecting to OpenRGB..." << std::endl;
    
    ConnectStatus status = client.connect("127.0.0.1");
    if (status != ConnectStatus::Success) {
        std::cerr << "Connection failed! Is OpenRGB SDK Server running?" << std::endl;
        return 1;
    }

    // 2. Find the Keyboard
    DeviceListResult result = client.requestDeviceList();
    const Device* targetDevice = nullptr;

    for (const auto& device : result.devices) {
        // We look for the "Dumb" USB interface we know works
        if (device.name.find("ASUS Aura Keyboard") != std::string::npos) {
            targetDevice = &device;
            std::cout << "Found Device: " << device.name << std::endl;
            break;
        }
    }

    if (!targetDevice) {
        std::cerr << "Keyboard not found! Make sure 'Device 1' is visible in OpenRGB." << std::endl;
        return 1;
    }

    // 3. The Infinite Rainbow Loop
    float hue = 0.0f;
    std::cout << "Rainbow Engine Started. Ctrl+C to stop." << std::endl;

    while (true) {
        // Calculate Color
        Color c = HSVtoColor(hue, 1.0f, 1.0f);

        // Update the device
        // This library handles the "whole device" update for us safely
        client.setDeviceColor(*targetDevice, c);

        // Spin the hue
        hue += 0.005f;
        if (hue > 1.0f) hue = 0.0f;

        // Frame Limiter (~60 FPS)
        std::this_thread::sleep_for(milliseconds(16));
    }

    return 0;
}