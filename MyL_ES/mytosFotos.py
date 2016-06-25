import urllib2, httplib, cookielib
httplib.HTTPConnection.debuglevel = 1

urls = []
idcarta = 1
totalCartas = 237
hdr = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.1271.64 Safari/537.11',
	       'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
	       'Accept-Charset': 'ISO-8859-1,utf-8;q=0.7,*;q=0.3',
	       'Accept-Encoding': 'none',
	       'Accept-Language': 'en-US,en;q=0.8',
	       'Connection': 'keep-alive'}
#for j in range(1,237):
#	url = "http://www.cambiacartas.com/im/selectCard/card_id/"+str(85807-j)+"/cards_lang/1"
#	urls.append(urllib2.urlopen(url))
def foo(site, hdr):
	try:
		req = urllib2.Request(site, headers=hdr)
		handle = urllib2.urlopen(req)
		content = handle.read()
		with open(str(i)+'.jpg', 'wb') as outfile:
		    outfile.write(content)
	except urllib2.HTTPError, e:
   		print e.fp.read()



for i in range(idcarta, totalCartas):
	site = "http://www.cambiacartas.com/img/cards/mitos-y-leyendas/618/big/"+str(i)+".jpg"
	print site, str(i)+'.jpg'
	#req = urllib2.Request(site, headers=hdr)
	#handle = urllib2.urlopen(req)
	#content = handle.read()
	#with open(str(i)+'.jpg', 'wb') as outfile:
	#    outfile.write(content)
	foo(site, hdr)