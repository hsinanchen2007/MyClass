# ch28_28.py
import pyautogui
import time

print("請在10秒內開啟記事本並設為焦點視窗")
time.sleep(10)

pyautogui.typewrite('Taiwan\t')                     # Taiwan
pyautogui.typewrite('Hung\t')                       # 姓
pyautogui.typewrite('Jiin-Kwei\t')                  # 名
pyautogui.typewrite('Jiin-Kwei\t')                  # 名
pyautogui.typewrite('Hung\t')                       # 姓
pyautogui.typewrite('1975\t')                       # 出生年        
pyautogui.typewrite('01\t')                         # 月
pyautogui.typewrite('01\t')                         # 日
pyautogui.typewrite('\t')                           # 選男生
pyautogui.typewrite('Ming-Chi Inst. of Tech\t')     # 學校
pyautogui.typewrite('Deartment of ME')              # 科系





