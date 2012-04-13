#include "StdAfx.h"
#include "GlobalCenter.h"

CGlobalCenter Global2;			// 实体
IGlobal* Global = &Global2;		// App全局访问接口

CGlobalCenter::CGlobalCenter(void)
{
}


CGlobalCenter::~CGlobalCenter(void)
{
}

HRESULT CGlobalCenter::Initialize( IModule* UpperFrame/*=NULL*/ )
{
	_InitializeLog();		// 所有地方都依赖log，所以当最先初始化
	_InitializeConfig();
	return S_OK;
}

HRESULT CGlobalCenter::UnInitialize()
{
	_UnInitializeConfig();
	_UnInitializeLog();
	return S_OK;
}

HRESULT CGlobalCenter::Run()
{
	return S_OK;
}

HRESULT CGlobalCenter::Terminate()
{
	return S_OK;
}

HRESULT CGlobalCenter::GetIConfig( IConfig** pConfig )
{
	*pConfig = dynamic_cast<IConfig*>(&m_config);
	return S_OK;
}

void CGlobalCenter::_InitializeConfig()
{
	m_config.Initialize(NULL);
	GetCurrentDirectory(MAX_PATH,m_configFilePath.GetBuffer(MAX_PATH));
	m_configFilePath.ReleaseBuffer();
	m_configFilePath += PathSplit;
	m_configFilePath += CONFIGXMLFILE;
	m_config.LoadConfigFromXML(m_configFilePath);
}

void CGlobalCenter::_UnInitializeConfig()
{
	m_config.SaveConfigToXML();
	m_config.UnInitialize();
}

HRESULT CGlobalCenter::CheckLastError(LPCTSTR helpStr)
{
	DWORD dw = GetLastError();
	CString str;
	str.Format(_T("检查LastError : %d"),dw);
	if (helpStr)
	{
		str.AppendFormat(_T("(%s)"),helpStr);
	}
	Log(LogFile_General,str);
	return dw;
}

