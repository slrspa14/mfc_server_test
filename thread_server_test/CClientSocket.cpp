// CClientSocket.cpp: 구현 파일
//

#include "pch.h"
#include "thread_server_test.h"
#include "CClientSocket.h"


// CClientSocket

CClientSocket::CClientSocket()
{
	//clistensocket 클래스 객체의 주소를 저장하는
	//멤버 m_plistensocket 추가 생성자 null 초기화
	m_pListenSocket = NULL;
}

CClientSocket::~CClientSocket()
{
}


// CClientSocket 멤버 함수
void CClientSocket::SetListenSocket(CAsyncSocket* pSocket)
{
	m_pListenSocket = pSocket;
}

void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CString strTmp = L"";
	CString IP = L"";
	UINT Port = 0;
	TCHAR buf[1024];
	memset(buf, sizeof(buf), 0);

	GetPeerName(IP, Port);
	if (Receive(buf, sizeof(buf) > 0))
	{
		
		strTmp.Format(_T("%s:%d : %s"), IP, Port, buf);
		//받아온 메시지 띄우기
	}
	CSocket::OnReceive(nErrorCode);
}
