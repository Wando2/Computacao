
def calcular_custo_esperado(pi, vi):
    return pi * vi

def testar_confiabilidade(componentes, probabilidades, custos):
    # Calcular o custo esperado de falha para cada componente
    custos_esperados = [calcular_custo_esperado(pi, vi) for pi, vi in zip(probabilidades, custos)]

    # Ordenar componentes pelo custo esperado
    componentes_ordenados = sorted(range(len(componentes)), key=lambda i: custos_esperados[i])

    custo_total = 0
    for i in componentes_ordenados:
        # Testar o componente
        custo_total += custos[i]
        if falha_no_teste(probabilidades[i]):  # Esta função simula se o componente falha ou não
            return False, custo_total  # Sistema não confiável

    return True, custo_total  # Sistema confiável

# Exemplo de uso
componentes = ['c1', 'c2', 'c3']
probabilidades = [0.1, 0.2, 0.3]  # Probabilidades de falha
custos = [5, 10, 15]              # Custos de teste

confiavel, custo = testar_confiabilidade(componentes, probabilidades, custos)
print(f"Sistema confiável: {confiavel}, Custo total: {custo}")