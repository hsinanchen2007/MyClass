# ch19_3.py
import openpyxl

fn = 'sales.xlsx'
wb = openpyxl.load_workbook(fn)
ws = wb.get_active_sheet()
print("目前工作表 = ", ws.title)






