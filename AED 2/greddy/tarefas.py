def SelecaoTarefas(tarefas):
    # Ordena as tarefas por data de término
    tarefas_ordenadas = sorted(tarefas, key=lambda x: x["fim"])

    # Inicializa a seleção de tarefas (S) com a primeira tarefa
    selecao = [tarefas_ordenadas[0]]
    r = tarefas_ordenadas[0]["fim"]

    # Itera sobre as tarefas restantes
    for i in range(1, len(tarefas_ordenadas)):
        # Verifica se a tarefa atual pode ser adicionada à seleção
        if tarefas_ordenadas[i]["inicio"] > r:
            selecao.append(tarefas_ordenadas[i])
            r = tarefas_ordenadas[i]["fim"]

    return selecao


# Definindo as tarefas como pares (inicio, fim)
tarefas = [
    {"inicio": 1, "fim": 14},
    {"inicio": 10, "fim": 13},
    {"inicio": 2, "fim": 3},
    {"inicio": 2, "fim": 6},
    {"inicio": 9, "fim": 11},
    {"inicio": 12, "fim": 15},
    {"inicio": 5, "fim": 8},
    {"inicio": 7, "fim": 8},
]

# Chamando a função SelecaoTarefas() com a lista de tarefas
selecao = SelecaoTarefas(tarefas)

# Imprimindo a seleção resultante
print("Seleção de Tarefas:")
for tarefa in selecao:
    print(f"Início: {tarefa['inicio']}, Fim: {tarefa['fim']}")
