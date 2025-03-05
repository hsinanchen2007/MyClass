# ch17_2.py
import docx

def getFile(fn):
    '''讀取檔案與適度編輯檔案'''
    wdoc = docx.Document(fn)                # 建立Word檔案物
    txt = []
    for paragraph in wdoc.paragraphs:
        print(paragraph.text)               # 輸出文件所讀取的Paragraph內容
        txt.append('    ' + paragraph.text) # 內縮同時將每一段Paragraph組成串列
    return '\n\n'.join(txt)                 # 將串列組成字串同時段落隔行輸出
print(getFile('data17_2.docx'))


    



        


