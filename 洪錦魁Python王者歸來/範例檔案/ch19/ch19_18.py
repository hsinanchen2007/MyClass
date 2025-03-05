# ch19_18.py
import openpyxl

fn = 'sales.xlsx'
wb = openpyxl.load_workbook(fn)     # 開啟sales.xlsx活頁簿
wb.save('out19_18.xlsx')            # 將活頁簿儲存至out19_18.xlsx








