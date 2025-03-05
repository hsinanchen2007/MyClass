# ch19_11.py
import openpyxl

fn = 'sales.xlsx'
wb = openpyxl.load_workbook(fn, data_only=True)
ws = wb.get_sheet_by_name('2020Q1')     # 目前工作表2020Q1
print(type(ws.rows))                    # 獲得ws.rows資料類型
print(type(ws.columns))                 # 獲得ws.columns資料類型

    

