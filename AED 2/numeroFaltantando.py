def InteiroFaltante(n, nums):
    # Passo 1: Determine o elemento mediano
    median = (n[0] + n[1]) // 2

    # Passo 2: Verifique se o elemento mediano está em nums
    if median not in nums:
        return median

    # Passo 3: Divida nums em duas partes
    left_nums = [x for x in nums if x <= median]
    right_nums = [x for x in nums if x > median]

    # Passo 4: Verifique o tamanho de left_nums
    if len(left_nums) < median + 1:
        # Passo 5: Recursão na parte esquerda
        return InteiroFaltante([n[0], median], left_nums)
    else:
        # Passo 6: Recursão na parte direita
        return InteiroFaltante([median + 1, n[1]], right_nums)

# Exemplo de uso
n = [0, 5]  # Intervalo de 0 a 5 (inclusive)
nums = [5, 3, 1, 4, 0]
missing_number = InteiroFaltante(n, nums)
print("O número ausente é:", missing_number)