# ch17_9.py
import docx

wdoc = docx.Document()
table = wdoc.add_table(rows=2, cols=2)
row = table.rows[0]             # 建立row 0表格資料
row.cells[0].text = '書號'
row.cells[1].text = '我的著作'
row = table.rows[1]             # 建立row 1表格資料
row.cells[0].text = 'XA1711'
row.cells[1].text = 'HTML5+CSS3王者歸來'
wdoc.save('out17_9.docx')





