from flask import Flask, redirect, render_template, request
from cs50 import SQL

db = SQL("sqlite:///gtdb.db")

app = Flask(__name__)


@app.route("/", methods=['GET','POST'])
def home():
    if request.method == 'GET':
        return render_template("home.html")
    else:
        home.genomes = request.form.get("genomes").split()
        return redirect("/taxonomy")


@app.route("/taxonomy", methods=['GET','POST'])
def taxonomy():
    if request.method == 'GET':
        results = db.execute("SELECT * FROM bacteria WHERE genome IN (?)", home.genomes)
        return render_template("taxonomy.html", results=results)
    else:
        return redirect("/summary")


@app.route("/summary", methods=['GET'])
def summary():
    domain = db.execute("SELECT domain, COUNT(domain) FROM bacteria WHERE genome IN (?) GROUP BY domain ORDER BY COUNT(domain) DESC", home.genomes)
    phylum = db.execute("SELECT phylum, COUNT(phylum) FROM bacteria WHERE genome IN (?) GROUP BY phylum ORDER BY COUNT(phylum) DESC", home.genomes)
    class1 = db.execute("SELECT class, COUNT(class) FROM bacteria WHERE genome IN (?) GROUP BY class ORDER BY COUNT(class) DESC", home.genomes)
    order = db.execute("SELECT order1, COUNT(order1) FROM bacteria WHERE genome IN (?) GROUP BY order1 ORDER BY COUNT(order1) DESC", home.genomes)
    family = db.execute("SELECT family, COUNT(family) FROM bacteria WHERE genome IN (?) GROUP BY family ORDER BY COUNT(family) DESC", home.genomes)
    genus = db.execute("SELECT genus, COUNT(genus) FROM bacteria WHERE genome IN (?) GROUP BY genus ORDER BY COUNT(genus) DESC", home.genomes)
    species = db.execute("SELECT species, COUNT(species) FROM bacteria WHERE genome IN (?) GROUP BY species ORDER BY COUNT(species) DESC", home.genomes)
    return render_template("summary.html", domain=domain, phylum=phylum, class1=class1, order=order, family=family, genus=genus, species=species)