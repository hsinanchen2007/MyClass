# ch19_10.py
import openpyxl

fn = 'sales.xlsx'
wb = openpyxl.load_workbook(fn, data_only=True)
ws = wb.get_sheet_by_name('2020Q1')             # 目前工作表2020Q1
for j in range(4,7):                            # row做索引增值
    for i in range(1,6):                        # column做索引增值
        print("%5s" % ws.cell(column=i, row=j).value, end=' ')   
    print()                                     # 換行輸出


  




