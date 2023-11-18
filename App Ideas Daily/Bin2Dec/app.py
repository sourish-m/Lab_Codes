# Flask app for binary to decimal converter

from flask import Flask, render_template, request, redirect, url_for

app = Flask(__name__)

@app.route('/', methods=['GET', 'POST'])
def startpage():
    decimal = None
    error = None

    if request.method == 'POST':
        binary = request.form['binary_input']
        try:
            decimal = int(binary, 2)
        except:
            error = 'Invalid input (only 0 and 1 allowed)'
        return render_template('index.html', decimal=decimal, error = error)

    return render_template('index.html')