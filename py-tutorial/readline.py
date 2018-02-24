f = open("/Users/Kwonkwon/TIL/py-tutorial/readme.md", "r")

while True:
    line = f.readline()
    if not line:break
    print(line)

f.close()

