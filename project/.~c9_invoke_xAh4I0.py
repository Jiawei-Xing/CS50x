from flask import Flask, redirect, render_template, request

app = Flask(__name__)

@app.route("/", method=['GET','POST'])
def search():
    if request.method = 'GET':
        return render_template("search.htm")

        data = request.form.get("data")