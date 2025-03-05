# ch19_4.py
import openpyxl

fn = 'sales.xlsx'
wb = openpyxl.load_workbook(fn)
ws = wb.get_sheet_by_name('2020Q3')     # 設定目前工作表
print("目前工作表 = ", ws.title)






