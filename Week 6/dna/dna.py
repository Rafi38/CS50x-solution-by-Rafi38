from sys import argv
import csv

if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    quit()

with open(argv[2]) as dna:     # open sequence
    dna = dna.read()
    length = len(dna)

database = list()
with open(argv[1]) as datalist:     # open dna database and reserv in list of list
    datalist = csv.reader(datalist)
    for row in datalist:
        database.append(row)

sequence = list()
for i in database[0]:   # collect dna sequence
    if i == 'name':
        continue
    sequence.append(i)

# now count dna given sample dna 

dna_data = list()
for sq in sequence:
    max_repeat = 0
    repeat = 0
    l_sq = len(sq)
    for l in range(length):     # mach every sequence with given sample dna data
        if dna[l: l + l_sq] == sq:
            repeat += 1
            if max_repeat < repeat:   # update maximum repeat value
                max_repeat = repeat
            if dna[l + l_sq: l + l_sq * 2] != sq:    # if not continues....
                repeat = 0
    dna_data.append(str(max_repeat))

l_db = len(database)
l_smpl = len(dna_data)
for i in range(1, l_db):  
    if dna_data == database[i][1:]:     #  match with database
        print(database[i][0])
        quit()

print("No match")