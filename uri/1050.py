num = int(raw_input())

ddds = {}
ddds[61] = 'Brasilia'
ddds[71] = 'Salvador'
ddds[11] = 'Sao Paulo'
ddds[21] = 'Rio de Janeiro'
ddds[32] = 'Juiz de Fora'
ddds[19] = 'Campinas'
ddds[27] = 'Vitoria'
ddds[31] = 'Belo Horizonte'

if num in ddds:
    print ddds[num]
else:
    print 'DDD nao cadastrado'