# ch29_3.py
from PIL import Image
import pytesseract

text  = pytesseract.image_to_string(Image.open('d:\\Python\\ch29\\data29_3.jpg'),
                                    lang='chi_tra')
print(text)
with open('d:\\Python\\ch29\\out29_3.txt', 'w') as fn:
    fn.write(text)


