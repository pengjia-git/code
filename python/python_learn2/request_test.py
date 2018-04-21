import requests

r = requests.get('http://sz.centanet.com/chengjiao/')
#print type(r)
#print r.status_code
#print r.encoding
print r.text
#print r.cookies
