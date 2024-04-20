#pragma once

// CListenSocket 명령 대상

class CListenSocket : public CAsyncSocket
{
public:
	CListenSocket();
	virtual ~CListenSocket();

	CPtrList m_ptrclientSocket;//소켓 담을거
	virtual void OnAccept(int nErrorCode);
};


