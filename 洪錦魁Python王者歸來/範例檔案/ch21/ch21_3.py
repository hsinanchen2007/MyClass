# ch21_3.py
import requests

url = 'http://www.grandtech.info'
htmlfile = requests.get(url)
print(type(htmlfile))


