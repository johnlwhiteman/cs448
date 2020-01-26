import json
import sys
from  pprint import pprint

def testEncryption(t):
    pprint(t)

def testDecryption(t):
    pprint(t)

def testEncryptionFile(t):
    pprint(t)

def testDecryptionFile(t):
    pprint(t)

try:
    with open("tests.json", "r", encoding="utf-8") as fd:
        tests = json.load(fd)
        for t in tests:
            testEncryption(t)
            testDecryption(t)
            testEncryptionFile(t)
            testDecryptionFile(t)

except IOError as e:
    print("Why!")
    sys.exit(1)
