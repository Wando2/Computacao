import random


def falha_no_teste(probabilidade):
    """
    Determina se um componente falha ou não durante o teste.
    A falha é simulada com base na probabilidade de falha do componente.

    :param probabilidade: A probabilidade de falha do componente.
    :return: True se o componente falhar, False caso contrário.
    """
    return random.random() < probabilidade


def calcular_custo_esperado(pi, vi):
    return pi * vi


def testar_confiabilidade(componentes, probabilidades, custos):
    # Criar tuplas de (componente, probabilidade, custo)
    componentes_info = [
        (comp, pi, vi) for comp, pi, vi in zip(componentes, probabilidades, custos)
    ]

    # Ordenar componentes pelo custo esperado
    componentes_ordenados = sorted(
        componentes_info, key=lambda x: calcular_custo_esperado(x[1], x[2])
    )

    custo_total = 0
    for comp, pi, vi in componentes_ordenados:
        # Testar o componente
        custo_total += vi
        if falha_no_teste(pi):  # Esta função simula se o componente falha ou não
            return False, custo_total  # Sistema não confiável

    return True, custo_total  # Sistema confiável 


# Exemplo de uso
componentes = ["c1", "c2", "c3"]
probabilidades = [0.1, 0.2, 0.3]  # Probabilidades de falha
custos = [5, 10, 15]  # Custos de teste

confiavel, custo = testar_confiabilidade(componentes, probabilidades, custos)
print(f"Sistema confiável: {confiavel}, Custo total: {custo}")
