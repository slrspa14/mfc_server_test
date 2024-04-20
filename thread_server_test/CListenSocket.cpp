// CListenSocket.cpp: 구현 파일
//

#include "pch.h"
#include "thread_server_test.h"
#include "CListenSocket.h"
#include "CClientSocket.h"

// CListenSocket

CListenSocket::CListenSocket()
{
}

CListenSocket::~CListenSocket()
{
}


// CListenSocket 멤버 함수


void CListenSocket::OnAccept(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CClientSocket* pClient = new CClientSocket;

	if (Accept(*pClient))
	{
		pClient->SetListenSocket(this);
		m_ptrclientSocket.AddTail(pClient);//끝에 추가
	}
	else
	{
		delete pClient;
		AfxMessageBox(_T("Accept 실패"));
	}

	CAsyncSocket::OnAccept(nErrorCode);
}
