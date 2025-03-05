# ch29_1.py
from PIL import Image
import pytesseract

text  = pytesseract.image_to_string(Image.open('d:\\Python\\ch29\\data29_1.jpg'))
print(text)



