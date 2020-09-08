import csv
import sqlite3
from sys import argv

if len(argv) != 2:
    print("Usage: import.py filename.csv")
    quit()

con = sqlite3.connect("students.db")    # connect with sql file
cur = con.cursor()

with open(argv[1], 'r') as std_csv:
    std = csv.DictReader(std_csv)       # read csv as dictionary
    for row in std:
        name = row['name'].split()
        if len(name) == 2:
            cur.execute("INSERT INTO students (first, last, house, birth) VALUES(?, ?, ?, ?)",       # insert info into db (middle name = null)
                        (name[0], name[1], row['house'], row['birth']))
        elif len(name) == 3:
            cur.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                        (name[0], name[1], name[2], row['house'], row['birth']))

con.commit()
con.close()
