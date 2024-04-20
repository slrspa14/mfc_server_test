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