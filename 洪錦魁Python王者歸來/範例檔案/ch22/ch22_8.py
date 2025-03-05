# ch22_8.py
from selenium import webdriver
import time

driverPath = 'D:\geckodriver\geckodriver.exe'
browser = webdriver.Firefox(executable_path=driverPath)
url = 'http://www.grandtech.info'
browser.get(url)                # 網頁下載至瀏覽器

eleLink = browser.find_element_by_link_text('認證考試')
print(type(eleLink))            # 列印eleLink資料類別
time.sleep(5)                   # 暫停5秒
eleLink.click()                 # 執行超連結至書級的證照類別







