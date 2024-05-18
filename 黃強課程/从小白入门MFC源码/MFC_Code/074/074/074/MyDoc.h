#pragma once

// CMyDoc �ĵ�

class CMyDoc : public CDocument
{
	DECLARE_DYNCREATE(CMyDoc)

public:
	CMyDoc();
	virtual ~CMyDoc();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // Ϊ�ĵ� I/O ��д
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual BOOL OnNewDocument();

public:
	CString m_txt;

	DECLARE_MESSAGE_MAP()


	virtual void DeleteContents();
};
