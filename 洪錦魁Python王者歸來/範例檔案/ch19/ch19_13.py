# ch19_13.py
import openpyxl

fn = 'sales.xlsx'
wb = openpyxl.load_workbook(fn, data_only=True)
ws = wb.get_sheet_by_name('2020Q1')             # 目前工作表2020Q1
for row in ws.rows:
    for cell in row:
        print(cell.value, end=' ')
    print()



