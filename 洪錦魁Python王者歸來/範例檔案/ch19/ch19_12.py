# ch19_12.py
import openpyxl

fn = 'sales.xlsx'
wb = openpyxl.load_workbook(fn, data_only=True)
ws = wb.get_sheet_by_name('2020Q1')             # 目前工作表2020Q1
for cell in list(ws.columns)[0]:                # A欄
    print(cell.value)
for cell in list(ws.rows)[2]:                   # 索引是2
    print(cell.value, end=' ')    


