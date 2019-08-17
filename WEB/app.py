import json

from flask import Flask, render_template, redirect, request
from flask_socketio import SocketIO, send, emit
from flask_cors import CORS

app = Flask(__name__)
socketio = SocketIO(app)
CORS(app)

estado = {
    "JANELA" : 0,
    "SENSOR" : 0
}
dados = {"LDR" : 0}

@app.route("/")
def rota_inicial():
    return render_template("index.html")

@app.route("/upload", methods = ["POST"])
def rota_upload():
        global dados
        dados = request.get_json
        socketio.emit("atualiza",dados)
        return "200"

@app.route("/download", methods = ["GET"])
def rota_download():
    global estado
    global change
    if (change==1):
        change=0
        return json.dumps(estado)
    return "1"

if __name__ == "__main__":
    app.run("0.0.0.0",port=8080)