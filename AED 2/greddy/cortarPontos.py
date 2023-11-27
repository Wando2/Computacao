def encontrar_pontos_minimos(intervalos):
    # Ordenar os intervalos pelo seu ponto de fim
    intervalos.sort(key=lambda x: x[1])

    pontos = []
    ultimo_ponto_selecionado = float("-inf")

    for inicio, fim in intervalos:
        if inicio > ultimo_ponto_selecionado:
            # Escolher o ponto de fim do intervalo
            ultimo_ponto_selecionado = fim
            pontos.append(fim)

    return pontos


# Exemplo de uso
intervalos = [(1, 4), (2, 3), (3, 5), (7, 9), (5, 6)]
pontos = encontrar_pontos_minimos(intervalos)
print("Pontos selecionados:", pontos)
