cmake_minimum_required(VERSION 3.10)
project(RainbowDriver)

set(CMAKE_CXX_STANDARD 17)

# 1. Include Paths
# We include 'sdk/external' so the code can say #include <CppUtils-Essential/xyz>
include_directories(sdk/include)
include_directories(sdk/external)

# 2. Source Files
# We list the SDK files AND the external library files you just found.
add_library(OpenRGBClient 
    # Core SDK
    sdk/src/Client.cpp
    sdk/src/MiscUtils.cpp
    sdk/src/Color.cpp
    sdk/src/ProtocolMessages.cpp
    sdk/src/Exceptions.cpp
    sdk/src/DeviceInfo.cpp
    sdk/src/ProtocolCommon.cpp

    # External: Network Utils (The "TcpSocket" errors)
    sdk/external/CppUtils-Network/NetAddress.cpp
    sdk/external/CppUtils-Network/HostInfo.cpp
    sdk/external/CppUtils-Network/Socket.cpp
    sdk/external/CppUtils-Network/SystemErrorInfo.cpp

    # External: Essential Utils (The "BinaryStream" errors)
    sdk/external/CppUtils-Essential/ContainerUtils.cpp
    sdk/external/CppUtils-Essential/LangUtils.cpp
    sdk/external/CppUtils-Essential/CriticalError.cpp
    sdk/external/CppUtils-Essential/BinaryStream.cpp
    sdk/external/CppUtils-Essential/StreamUtils.cpp
    sdk/external/CppUtils-Essential/StringUtils.cpp
)

# 3. Create Executable
add_executable(rainbow_driver main.cpp)

# 4. Link Libraries
target_link_libraries(rainbow_driver OpenRGBClient pthread)
