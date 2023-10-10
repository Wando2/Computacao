def indiceMedio(arr,inicio,fim):
    if inicio == fim:
        return inicio
    
    meio = (inicio + fim) // 2
    
    indiceEsquerda = indiceMedio(arr,inicio,meio)
    indiceDireita = indiceMedio(arr,meio+1,fim)
    
    somaIndices = indiceEsquerda + indiceDireita
    
    return somaIndices // 2



#test cases
arr = [7, 3, 1, 9, 4, 8]
posicao_valor_medio = indiceMedio(arr, 0, len(arr) - 1)
valor_medio = arr[posicao_valor_medio]
print(f"O valor médio é {valor_medio} e está na posição {posicao_valor_medio}")