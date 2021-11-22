from cs50 import SQL

db = SQL("sqlite:///gtdb.db")
with open("bac120_taxonomy.tsv") as f:
    for line in f:
        row = [line.split('\t')[0][3:]] + line.split('\t')[1].split(';')
        db.execute("INSERT INTO bacteria VALUES (?,?,?,?,?,?,?,?)",
                    row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7])
