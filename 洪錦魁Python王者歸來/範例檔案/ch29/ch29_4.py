# ch29_4.py
from PIL import Image
import pytesseract

text  = pytesseract.image_to_string(Image.open('d:\\Python\\ch29\\data29_4.jpg'),
                                               lang='chi_sim')
print(text)
with open('d:\\Python\\ch29\\out29_4.txt', 'w', encoding='utf-8') as fn:
    fn.write(text)


