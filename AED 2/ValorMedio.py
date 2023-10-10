def encontre_valor_medio(arr, inicio, fim):
    if inicio == fim:
        return inicio
    
    meio = (inicio + fim) // 2
    
    # Encontra o valor médio da metade esquerda
    valor_medio_esquerda = encontre_valor_medio(arr, inicio, meio)
    
    # Encontra o valor médio da metade direita
    valor_medio_direita = encontre_valor_medio(arr, meio + 1, fim)
    
    # Calcula a soma das posições dos valores médios encontrados
    soma_posicoes = valor_medio_esquerda + valor_medio_direita
    
    # Encontra a média das posições
    media_posicoes = soma_posicoes // 2
    
    return media_posicoes

# Exemplo de uso:
arr = [7, 3, 1, 9, 4, 8]
posicao_valor_medio = encontre_valor_medio(arr, 0, len(arr) - 1)
valor_medio = arr[posicao_valor_medio]
print(f"O valor médio é {valor_medio} e está na posição {posicao_valor_medio}")