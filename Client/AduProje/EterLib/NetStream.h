#pragma once

class CNetworkStream
{
public:
	CNetworkStream();
	virtual ~CNetworkStream();

	auto Clear() -> void;
private:
	SOCKET m_sock;
};