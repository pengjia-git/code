import requests
from bs4 import BeautifulSoup


r = requests.get('http://sz.centanet.com/chengjiao/')
#print type(r)
#print r.status_code
#print r.encoding

soup = BeautifulSoup(r.text)
print soup.title
