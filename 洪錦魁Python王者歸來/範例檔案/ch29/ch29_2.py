# ch29_2.py
from PIL import Image
import pytesseract

text  = pytesseract.image_to_string(Image.open('d:\\Python\\ch29\\data29_2.jpg'))
print(text)
with open('d:\\Python\\ch29\\out29_2.txt', 'w') as fn:
    fn.write(text)


