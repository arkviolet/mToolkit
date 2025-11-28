#pragma once

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdint.h>
#include <sys/socket.h>

#include <ctime>
#include <string>
#include <vector>

namespace mToolkit {
namespace utilities {

class Net {
 public:
  static bool AsRange(const std::string& value, uint16_t& head, uint16_t& tail);

  static bool AsNetByte(const std::string& value, uint32_t& head, uint32_t& tail);

  static bool AsHostByte(const std::string& value, uint32_t& head, uint32_t& tail);

  static bool TraverseAddressFromHost(const char* host, std::vector<std::string>& list);

  static bool CloseSocket(int32_t socket);

  static bool DisableNagle(int32_t socket);

  static bool EnableLinger(int32_t socket, int32_t timeout = 0);

  static bool EnableNonBlock(int32_t socket);

  static bool EnableReuseAddress(int32_t socket);

  static bool GetLocalAddress(int32_t socket, struct sockaddr_in& address);

  static bool GetRemoteAddress(int32_t socket, struct sockaddr_in& address);

  static bool SetSendTimeout(int32_t sock, std::time_t second);

  static bool SetReceiveTimeout(int32_t sock, std::time_t second);

  static bool SetSendBufferSize(int32_t sock, int32_t size);

  static bool SetReceiveBufferSize(int32_t sock, int32_t size);

  static int32_t GetFamily(int32_t sock);

  static int32_t GetSendBufferSize(int32_t sock);

  static int32_t GetReceiveBufferSize(int32_t sock);

  static uint32_t AsNetByte(const char* value);

  static uint32_t AsHostByte(const char* value);

  static std::string AsString(uint32_t value);
};

}  // namespace utilities
}  // namespace mToolkit
