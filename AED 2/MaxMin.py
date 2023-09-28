def MaxMin(e, d, s):
    if e == d:
        return (s[e], s[e])
    elif d == e + 1:
        if s[e] < s[d]:
            return (s[e], s[d])
        else:
            return (s[d], s[e])
    else:
        m = (e + d) // 2
        (a1, b1) = MaxMin(e, m, s)
        (a2, b2) = MaxMin(m + 1, d, s)
        return (min(a1, a2), max(b1, b2))

# Exemplo de uso:
s = [5, 2, 9, 1, 5, 6]
minimo, maximo = MaxMin(0, len(s) - 1, s)
print("Mínimo:", minimo)
print("Máximo:", maximo)