#include "StdAfx.h"
#include "NetStream.h"

CNetworkStream::CNetworkStream()
{
	m_sock = INVALID_SOCKET;
}

CNetworkStream::~CNetworkStream()
{
	Clear();
}

auto CNetworkStream::Clear() -> void
{
	if (m_sock == INVALID_SOCKET)
		return;

	closesocket(m_sock);
	m_sock = INVALID_SOCKET;
}