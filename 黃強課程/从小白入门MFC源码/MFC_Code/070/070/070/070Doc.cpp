
// 070Doc.cpp : CMy070Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "070.h"
#endif

#include "070Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy070Doc

IMPLEMENT_DYNCREATE(CMy070Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy070Doc, CDocument)
END_MESSAGE_MAP()


// CMy070Doc ����/����

CMy070Doc::CMy070Doc()
{
	// TODO: �ڴ����һ���Թ������

}

CMy070Doc::~CMy070Doc()
{
}

BOOL CMy070Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMy070Doc ���л�

void CMy070Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())//�����ʱ��
	{
		// TODO: �ڴ���Ӵ洢����

		ar.WriteString( L"��һ��ʹ�õ��ĵ�!");
	}
	else//�򿪵�ʱ��
	{
		// TODO: �ڴ���Ӽ��ش���

		CString str;
		ar.ReadString(str);
		AfxMessageBox(str);
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CMy070Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CMy070Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CMy070Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy070Doc ���

#ifdef _DEBUG
void CMy070Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy070Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy070Doc ����
