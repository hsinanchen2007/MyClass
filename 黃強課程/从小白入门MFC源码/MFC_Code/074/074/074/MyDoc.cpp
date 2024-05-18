// MyDoc.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyDoc.h"


// CMyDoc

IMPLEMENT_DYNCREATE(CMyDoc, CDocument)

CMyDoc::CMyDoc()
{
}

BOOL CMyDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CMyDoc::~CMyDoc()
{
}


BEGIN_MESSAGE_MAP(CMyDoc, CDocument)
END_MESSAGE_MAP()


// CMyDoc ���

#ifdef _DEBUG
void CMyDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CMyDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CMyDoc ���л�

void CMyDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())//�洢�ļ�
	{
		// TODO:  �ڴ���Ӵ洢����
		CEditView * pView = (CEditView *)m_viewList.GetHead();
		
		pView->GetEditCtrl().GetWindowText(m_txt);
		ar.WriteString(m_txt);
	}
	else//���ļ�
	{
		// TODO:  �ڴ���Ӽ��ش���

		//ar.ReadString(m_txt); ֻ�ܶ�ȡһ��
		TCHAR tmp[1024] = {0};
		ar.Read(tmp, 1024);
		m_txt = tmp;
	}
}
#endif


// CMyDoc ����


void CMyDoc::DeleteContents()
{
	// TODO: �ڴ����ר�ô����/����û���

	m_txt = L"";

	CDocument::DeleteContents();
}
