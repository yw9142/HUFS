#!C:\Users\pyw08\Desktop\Python\venv\Scripts\python.exe
# EASY-INSTALL-ENTRY-SCRIPT: 'high==0.1.0','console_scripts','high'
__requires__ = 'high==0.1.0'
import re
import sys
from pkg_resources import load_entry_point

if __name__ == '__main__':
    sys.argv[0] = re.sub(r'(-script\.pyw?|\.exe)?$', '', sys.argv[0])
    sys.exit(
        load_entry_point('high==0.1.0', 'console_scripts', 'high')()
    )
