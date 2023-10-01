def verifica_padrao(i, string, padrao):
    # Inicializa uma variável para contar o número de ocorrências do padrão
    contagem = 0
    
    # Inicializa uma variável para acompanhar a posição atual na string
    posicao = 0
    
    # Itera sobre a string para encontrar o padrão
    for char in string:
        if char == padrao[posicao]:
            posicao += 1
            if posicao == len(padrao):
                # O padrão foi encontrado, incrementa a contagem e reinicia a posição
                contagem += 1
                posicao = 0
    
    # Verifica se o padrão ocorreu i vezes
    if contagem == i:
        return 'Y'
    else:
        return 'N'
    
    
def subsequencia(padrao, i, string):
    posLetras, contadorPadrao = 0, 0
    tamanhoString = len(string)
    tamanhoPadrao = len(padrao)

    for j in range(tamanhoString):
        if string[j] == padrao[posLetras]:
            posLetras += 1

            if posLetras == tamanhoPadrao:
                contadorPadrao += 1
                posLetras = 0

    return contadorPadrao == i

#teste subsequencia
print(subsequencia('aba', 2, 'abababa'))