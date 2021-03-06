#pragma once
#include "../FrameWork/FrameBase.hpp"

//////////////////////////////////////////////////////////////////////////
// Messages

// 特殊消息，获取模块所监听的消息列表
struct XMessage_GetListenList : public XMessage
{
	ImTheMessageOf(XMessage_GetListenList);

	std::list<CString>	msgIDList;
};

//////////////////////////////////////////////////////////////////////////
// 登陆相关

struct XMessage_Login : public XMessage
{
	ImTheMessageOf(XMessage_Login);

	CString username;
	CString pwd;
};

struct XMessage_LoginError : public XMessage
{
	ImTheMessageOf(XMessage_LoginError);

	ResultCode result;
};

struct XMessage_Login_Result : public XMessage
{
	ImTheMessageOf(XMessage_Login_Result);

	BOOL success;
	DWORD	userToken;
	BYTE	guid[16];
};

struct XMessage_ShowLogin : public XMessage
{
	ImTheMessageOf(XMessage_ShowLogin);
};

//////////////////////////////////////////////////////////////////////////
// 房间相关

struct XMessage_ShowRoomListWnd : public XMessage
{
	ImTheMessageOf(XMessage_ShowRoomListWnd);
};


struct XMessage_ShowRoomListWnd_Result : public XMessage
{
	ImTheMessageOf(XMessage_ShowRoomListWnd_Result);
};

struct XMessage_GetRoomList : public XMessage
{
	ImTheMessageOf(XMessage_GetRoomList);
};

struct XMessage_GetRoomList_Result : public XMessage
{
	ImTheMessageOf(XMessage_GetRoomList_Result);

	std::vector<int> roomID;
};

struct XMessage_ShowClassroom : public XMessage
{
	ImTheMessageOf(XMessage_ShowClassroom);
};

//////////////////////////////////////////////////////////////////////////
// Framework

struct XMessage_FrameStart : public XMessage
{
	ImTheMessageOf(XMessage_FrameStart);
};

struct XMessage_StartTest : public XMessage
{
	ImTheMessageOf(XMessage_StartTest);
};