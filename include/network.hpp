#pragma once

#ifndef __IUT_NETWORK_H__
#define __IUT_NETWORK_H__


#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#else // ^^^ _WIN32 / !_WIN32 vvv
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif // !_WIN32

#include <stdexcept> // std::runtime_error
#include <cstring> // memset
#include <vector> // std::vector
#include <string> // std::to_string

namespace iut
{
#ifdef _WIN32
	using socket_t = SOCKET;
#else // ^^^ _WIN32 / !_WIN32 vvv
	using socket_t = int;
#endif // !_WIN32

	static constexpr const char* LOCALHOST = "127.0.0.1";

	namespace port
	{
		enum : uint32_t
		{
			DEFAULT = 5000
		};
	}

#ifdef _WIN32
#define BAD_SOCKET INVALID_SOCKET
#else // ^^^ _WIN32 / !_WIN32 vvv
#define BAD_SOCKET -1
#endif // !_WIN32

	class i_socket
	{
	public:

		inline i_socket() noexcept(false)
			: m_ip(LOCALHOST), m_port(port::DEFAULT)
		{
#ifdef _WIN32
			WSADATA wsadata;

			if (WSAStartup(MAKEWORD(2, 2), &wsadata))
			{
				throw std::runtime_error("WSAStartup failed");
			}
#endif // !_WIN32
		}

		inline i_socket(const char* _Ip, uint32_t _Port) noexcept(false)
			: m_ip(_Ip), m_port(_Port)
		{
#ifdef _WIN32
			WSADATA wsadata;

			if (WSAStartup(MAKEWORD(2, 2), &wsadata))
			{
				throw std::runtime_error("WSAStartup failed");
			}
#endif // !_WIN32
		}

		inline i_socket(const i_socket&) = delete;

		inline i_socket(i_socket&&) noexcept = delete;

		inline virtual ~i_socket() noexcept
		{
#ifdef _WIN32
			WSACleanup();
#endif // !_WIN32
		}

		inline i_socket& operator=(const i_socket&) = delete;

		inline i_socket& operator=(i_socket&&) noexcept = delete;

	protected:

		const char* m_ip;
		uint32_t m_port;

	}; // class !i_socket

	class tcp_server final : public i_socket
	{
	public:

		inline tcp_server() noexcept(false)
			: super()
		{
			m_listen_socket = socket(PF_INET, SOCK_STREAM, 0);

			if (m_listen_socket == BAD_SOCKET)
			{
				throw std::runtime_error("Error while creating socket");
			}

			m_address_len = sizeof(m_local_address);
			memset(&m_local_address, 0, m_address_len);
			m_local_address.sin_family = PF_INET;
#ifdef _WIN32
			m_local_address.sin_addr.S_un.S_addr = INADDR_ANY;
#else // ^^^ _WIN32 / !_WIN32 vvv
			m_local_address.sin_addr.s_addr = htonl(INADDR_ANY);
#endif // !_WIN32
			m_local_address.sin_port = htons(m_port);
		}

		inline tcp_server(const char* _Ip, uint32_t _Port) noexcept(false)
			: super(_Ip, _Port)
		{
			m_listen_socket = socket(PF_INET, SOCK_STREAM, 6);

			if (m_listen_socket == BAD_SOCKET)
			{
				throw std::runtime_error("Error while creating socket");
			}

			m_address_len = sizeof(m_local_address);
			memset(&m_local_address, 0, m_address_len);
			m_local_address.sin_family = PF_INET;
#ifdef _WIN32
			m_local_address.sin_addr.S_un.S_addr = INADDR_ANY;
#else // ^^^ _WIN32 / !_WIN32 vvv
			m_local_address.sin_addr.s_addr = htonl(INADDR_ANY);
#endif // !_WIN32
			m_local_address.sin_port = htons(m_port);
		}

		inline virtual ~tcp_server() noexcept
		{
#ifdef _WIN32
			closesocket(m_listen_socket);
#else // ^^^ _WIN32 / !_WIN32 vvv
			close(m_listen_socket);
#endif // !_WIN32
		}

		inline bool is_running() const noexcept
		{
			return m_is_running;
		}

		inline size_t size() const noexcept
		{
			return m_connection_sockets.size();
		}

		inline void send(size_t _Index, const char* _Data) const noexcept(false)
		{
			size_t size = strlen(_Data);

#ifdef _WIN32
			if (::send(m_connection_sockets[_Index], _Data, size, 0) == SOCKET_ERROR)
			{
				throw std::runtime_error("Error while sending data");
			}
#else // ^^^ _WIN32 / !_WIN32 vvv
			if (::write(m_connection_sockets[_Index], _Data, size) == -1)
			{
				throw std::runtime_error("Error while sending data");
			}
#endif // !_WIN32
		}

		[[nodiscard]] inline char* receive(size_t _Sender, size_t _Size) const noexcept(false)
		{
			char* buffer = new char[_Size];

#ifdef _WIN32
			if (::recv(m_connection_sockets[_Sender], buffer, _Size, 0) == SOCKET_ERROR)
			{
				throw std::runtime_error("Error while receiving data");
			}
#else // ^^^ _WIN32 / !_WIN32 vvv
			if (::read(m_connection_sockets[_Sender], buffer, _Size) == -1)
			{
				throw std::runtime_error("Error while receiving data");
			}
#endif // !_WIN32

			return buffer;
		}

		inline void bind() const noexcept(false)
		{
			if (::bind(m_listen_socket, reinterpret_cast<const sockaddr*>(&m_local_address), m_address_len) < 0)
			{
				perror("Error while binding socket");
				throw std::runtime_error("Error while binding socket");
			}
		}

		inline void listen() const noexcept(false)
		{
			if (::listen(m_listen_socket, 1) < 0)
			{
				throw std::runtime_error("Error while listening socket");
			}
		}

		inline void accept() noexcept(false)
		{
			sockaddr_in client_address;
			socklen_t client_address_len = sizeof(client_address);
			memset(&client_address, 0, client_address_len);

			m_connection_sockets.push_back(::accept(m_listen_socket, reinterpret_cast<sockaddr*>(&client_address), &m_address_len));
			socket_t accepted_socket = m_connection_sockets.back();

			if (accepted_socket == BAD_SOCKET)
			{
				throw std::runtime_error("Error while accepting socket");
			}
		}

		inline void close(size_t _Index) const noexcept
		{
#ifdef _WIN32
			closesocket(m_connection_sockets[_Index]);
#else // ^^^ _WIN32 / !_WIN32 vvv
			close(m_connection_sockets[_Index]);
#endif // !_WIN32
		}

		inline void broadcast(const char* _Data) const noexcept(false)
		{
			for (size_t i = 0; i < m_connection_sockets.size(); ++i)
			{
				send(i, _Data);
			}
		}

		inline void run() noexcept(false)
		{
			m_is_running = true;

			bind();
			listen();
		}

		inline void shutdown() noexcept
		{
			broadcast("stop");

			for (size_t i = 0; i < m_connection_sockets.size(); ++i)
			{
				close(i);
			}

			m_connection_sockets.clear();
			m_is_running = false;

#ifdef _WIN32
			closesocket(m_listen_socket);
#else // ^^^ _WIN32 / !_WIN32 vvv
			close(m_listen_socket);
#endif // !_WIN32
		}

	private:

		using super = i_socket;

	private:

		socket_t m_listen_socket;
		std::vector<socket_t> m_connection_sockets;
		sockaddr_in m_local_address = {};
		socklen_t m_address_len = 0;
		std::vector<sockaddr_in> m_remote_addresses;
		bool m_is_running = false;

	}; // class !tcp_server

	class client_socket final : public i_socket
	{
	public:

		inline client_socket() noexcept(false)
			: super()
		{
			m_socket = socket(AF_INET, SOCK_STREAM, 6);

			if (m_socket == BAD_SOCKET)
			{
				throw std::runtime_error("Error while creating socket");
			}

			m_address_len = sizeof(m_local_address);
			memset(&m_local_address, 0, m_address_len);
#ifdef _WIN32
			auto result = getaddrinfo(
				m_ip,
				std::to_string(m_port).c_str(),
				nullptr,
				&m_local_address
			);

			if (result != 0)
			{
				throw std::runtime_error("Error while getting address info");
			}
#else // ^^^ _WIN32 / !_WIN32 vvv
			m_local_address.sin_family = PF_INET;
			m_local_address.sin_addr.s_addr = inet_addr(_Ip);
			m_local_address.sin_port = htons(_Port);
#endif // !_WIN32
		}

		inline client_socket(const char* _Ip, uint32_t _Port) noexcept(false)
			: super(_Ip, _Port)
		{
			m_socket = socket(PF_INET, SOCK_STREAM, 0);

			if (m_socket == BAD_SOCKET)
			{
				throw std::runtime_error("Error while creating socket");
			}

			m_address_len = sizeof(m_local_address);
			memset(&m_local_address, 0, m_address_len);
#ifdef _WIN32
			auto result = getaddrinfo(
				_Ip,
				std::to_string(_Port).c_str(),
				nullptr,
				&m_local_address
			);

			if (result != 0)
			{
				throw std::runtime_error("Error while getting address info");
			}
#else // ^^^ _WIN32 / !_WIN32 vvv
			m_local_address.sin_family = PF_INET;
			m_local_address.sin_addr.s_addr = inet_addr(_Ip);
			m_local_address.sin_port = htons(_Port);
#endif // !_WIN32
		}

		inline virtual ~client_socket() noexcept
		{
#ifdef _WIN32
			closesocket(m_socket);
#else // ^^^ _WIN32 / !_WIN32 vvv
			close(m_socket);
#endif // !_WIN32
		}

		inline void send(const char* _Data) const noexcept(false)
		{
			size_t size = strlen(_Data);

#ifdef _WIN32
			if (::send(m_socket, _Data, size, 0) == SOCKET_ERROR)
			{
				throw std::runtime_error("Error while sending data");
			}
#else // ^^^ _WIN32 / !_WIN32 vvv
			if (::write(m_socket, _Data, size) == -1)
			{
				throw std::runtime_error("Error while sending data");
			}
#endif // !_WIN32
		}

		[[nodiscard]] inline char* receive(size_t _Size) const noexcept(false)
		{
			char* buffer = new char[_Size];

#ifdef _WIN32
			if (::recv(m_socket, buffer, _Size, 0) == SOCKET_ERROR)
			{
				throw std::runtime_error("Error while receiving data");
			}
#else // ^^^ _WIN32 / !_WIN32 vvv
			if (::read(m_socket, buffer, _Size) == -1)
			{
				throw std::runtime_error("Error while receiving data");
			}
#endif // !_WIN32

			return buffer;
		}

		inline void connect() const noexcept(false)
		{
			if (::connect(m_socket, reinterpret_cast<const sockaddr*>(&m_local_address), m_address_len) < 0)
			{
				throw std::runtime_error("Error while connecting socket");
			}
		}

	private:

		using super = i_socket;

	private:

		socket_t m_socket;
#ifdef _WIN32
		addrinfo* m_local_address = nullptr;
#else // ^^^ _WIN32 / !_WIN32 vvv
		sockaddr_in m_local_address = {};
#endif // !_WIN32
		socklen_t m_address_len = 0;

	}; // class !client_socket

} // !namespace iut

#endif // !__IUT_NETWORK_H__