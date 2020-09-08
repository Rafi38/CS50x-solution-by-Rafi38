import sqlite3
from sys import argv

if len(argv) != 2:            # check input
    print("Usage: import.py filename.csv")
    quit()

cur = sqlite3.connect("students.db")  # connect with database
con = cur.cursor()
info = cur.execute(
    f'SELECT first, middle, last, birth FROM students WHERE house = "{argv[1]}" ORDER by last, first;')

for i in info:   # print data
    if isinstance(i[1], str):   # if middle name is not black
        print(i[0], i[1], i[2], ", born", i[3])
    else:                              # middlename blank or Nonetype
        print(i[0], i[2], ",born", i[3])
