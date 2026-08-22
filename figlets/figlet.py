from pyfiglet import Figlet
import sys
import random

figlet = Figlet()
fonts = figlet.getFonts()

if len(sys.argv) == 3 and (sys.argv[1] in ('-f', '--fonts')) and (sys.argv[2] in fonts):
    f = sys.argv[2]
    figlet.setFont(font=f)
    s = input('Text: ')
    print(figlet.renderText(s))
elif len(sys.argv) == 1:
    f = random.choice(fonts)
    figlet.setFont(font=f)
    s = input('Text: ')
    print(figlet.renderText(s))
else:
    print('Invalid usage')
    sys.exit(1)