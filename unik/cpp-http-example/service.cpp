#include <net/inet4>
#include <os>

constexpr int port{8080};

void Service::start(const std::string &) {
  using namespace std::string_literals;

  auto &server = net::Inet4::stack().tcp().bind(port);
  server.on_connect([](auto conn) {
    conn->on_read(1024, [conn](auto buf, size_t n) {
      auto response{
          "HTTP/1.1 200 OK\r\n"
          "Content-Type: text/html; charset=UTF-8\r\n\r\n"
          "<!DOCTYPE html><html><head><title>Hello from unikerneland!</title>"
          "</head>"
          "<body><h1>Hello, you UniKernel world!</h1></body></html>\r\n"s};
      conn->write(response);
      conn->close();
    });
  });
}
