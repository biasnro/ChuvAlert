import requests
while(1):
    valor = int(input("Informe um numero:"))
    r = requests.post("http://chuva2.herokuapp.com/upload", json = {"LDR":valor})
    print(r.status_code)