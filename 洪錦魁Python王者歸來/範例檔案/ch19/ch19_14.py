# ch19_14.py
import openpyxl

fn = 'sales.xlsx'
wb = openpyxl.load_workbook(fn, data_only=True)
ws = wb.get_sheet_by_name('2020Q1')             # 目前工作表2020Q1
for col in ws.columns:
    for cell in col:
        print(cell.value, end=' ')
    print()



