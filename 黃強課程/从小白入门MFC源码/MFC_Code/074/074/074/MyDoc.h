#pragma once

// CMyDoc 文档

class CMyDoc : public CDocument
{
	DECLARE_DYNCREATE(CMyDoc)

public:
	CMyDoc();
	virtual ~CMyDoc();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // 为文档 I/O 重写
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
