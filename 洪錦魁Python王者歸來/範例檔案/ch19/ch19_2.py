# ch19_2.py
import openpyxl

fn = 'sales.xlsx'
wb = openpyxl.load_workbook(fn)     # wb是Excel檔案物件    
allSheets = wb.get_sheet_names()    # 所有工作表物件
print("所有工作表 = ", allSheets)

ws = wb.get_active_sheet()          # ws是目前工作表物件
print("目前工作表 = ", ws)





