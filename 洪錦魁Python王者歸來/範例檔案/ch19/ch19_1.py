# ch19_1.py
import openpyxl

fn = 'sales.xlsx'
wb = openpyxl.load_workbook(fn)     # wb是Excel檔案物件
print(type(wb))


