# 🧩 Trabalho 4: Soluções de Algoritmos (LeetCode)

**Disciplina:** Projeto de Algoritmos (FGA0124)  
**Professor:** Maurício Serrano



## 📖 Sobre o Projeto

Este repositório contém as soluções desenvolvidas para o **Trabalho 4** da disciplina de **Projeto de Algoritmos**.  
O objetivo principal foi **aplicar e demonstrar o conhecimento teórico adquirido em aula** através da resolução de desafios práticos da plataforma **LeetCode**.

Selecionamos e implementamos a solução para **três problemas de nível Difícil**, cada um explorando **diferentes algoritmos avançados e estruturas de dados**.



## 👥 Equipe

| Matrícula   | Aluno                         |
|-------------:|-------------------------------|
| 231028989    | Joao Pedro Ferreira Moraes    |
| 231026680    | Cibelly Lourenço Ferreira     |


## 🛠️ Tecnologias Utilizadas

- **Linguagem:** C++



## 🚀 Desafios Resolvidos

Abaixo estão detalhados os problemas abordados, com uma breve explicação da estratégia utilizada e a referência à submissão LeetCode.



### 1. [4. Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)  
**Estratégia:** Busca Binária (Dividir e Conquistar)  
**Submissão:** LeetCode 4

A estratégia para este problema é encontrar a mediana em tempo **O(log(m+n))**, evitando a fusão linear.  
A solução é uma variação de **buscar o k-ésimo menor elemento** na união dos dois arrays.

- Se o comprimento total (m+n) for ímpar → k = (m+n)/2 + 1.  
- Se for par → k1 = (m+n)/2 e k2 = (m+n)/2 + 1 e a mediana é a média entre eles.

Implementação (intuições principais):
- A função `findKthElement(k)` escolhe pivôs em cada array (aprox. k/2) e compara `nums1[pivot1]` com `nums2[pivot2]`.
- Se `nums1[pivot1] < nums2[pivot2]`, os elementos até `pivot1` em `nums1` podem ser descartados (não contêm o k-ésimo).
- Processo repetido sobre os subarrays restantes até alcançar os casos-base (`k == 1` ou array vazio).

---

### 2. [2179. Count Good Triplets in an Array](https://leetcode.com/problems/count-good-triplets-in-an-array/)  
**Estratégia:** Fenwick Tree (Binary Indexed Tree - BIT)  
**Submissão:** LeetCode 2179

Transformamos o problema em contagem de subsequências crescentes de tamanho 3.

Definição de *good triplet* (x, y, z):

- `pos1[x] < pos1[y] < pos1[z]`
- `pos2[x] < pos2[y] < pos2[z]`

Se percorrermos `nums1` na ordem (índices i < j < k), a primeira condição já fica satisfeita. Assim, construímos:

- `A[i] = pos2[nums1[i]]`

O problema passa a ser: contar trios i < j < k tais que `A[i] < A[j] < A[k]`.

Solução em **O(N log N)**:
- Calcular para cada j:
  - `left_counts[j]`: quantos i < j com `A[i] < A[j]`.
  - `right_counts[j]`: quantos k > j com `A[k] > A[j]`.
- `left_counts` é obtido varrendo da esquerda para a direita usando uma Fenwick Tree que conta frequências de valores de `A`.
- `right_counts` é obtido varrendo da direita para a esquerda com outra Fenwick Tree.
- A resposta final é `sum(left_counts[j] * right_counts[j])` para todo j.

Observações de implementação:
- Como `A` contém posições, usamos compressão/normalização se necessário para indexar a BIT.
- Fenwick Tree permite atualizações e consultas prefixo em O(log N).

---

### 3. [1982. Find Array Given Subset Sums](https://leetcode.com/problems/find-array-given-subset-sums/)  
**Estratégia:** Recursão com Particionamento (multiset)  
**Submissão:** LeetCode 1982

Problema: dado o multiconjunto de todas as somas de subconjuntos `S` de um array desconhecido `arr` de tamanho `n`, reconstruir `arr`.

Ideia chave:
- Se `S_n` é o conjunto de `2^n` somas, ele é a união de `S_{n-1}` e `(S_{n-1} + x)`, onde `x` é um elemento de `arr`.
- Ordenando `S_n`, a diferença entre os dois menores elementos `d = S_n[1] - S_n[0]` deve ser `x` ou `-x`.
- Tentar `d` como candidato: particionar `S_n` em dois grupos (`s1` e `s2`) de tamanho `2^{n-1}` onde cada elemento de `s1` tem um par em `s2` que difere por `d`. Utilizamos um `multiset` (ou `map` de contagens) para lidar com duplicatas.

Processo recursivo:
1. Ordenar `S_n` e pegar `d = S_n[1] - S_n[0]`.
2. Tentar particionar `S_n` em `s1` e `s2` usando `d`:
   - Iterar sobre os elementos ordenados; para cada menor `s` disponível, remover `s` de `multiset`, procurar `s + d`; se existir, colocar `s` em `s1` e `s + d` em `s2`.
   - Se falhar (pareamento impossível), então `d` não é válido.
3. Após a partição bem-sucedida, determinar qual dos grupos é `S_{n-1}`: aquele que contém `0` (soma do subconjunto vazio).
   - Se `0 ∈ s1` então `x = d` e recurse com `s1`.
   - Se `0 ∈ s2` então `x = -d` e recurse com `s2`.
4. Repetir até reduzir a `n = 0`.

---

## 🎬 Vídeo de Apresentação

A explicação detalhada do raciocínio por trás de cada solução pode ser encontrada nos vídeos abaixo:

[4. Median of Two Sorted Arrays]()

[2179. Count Good Triplets in an Array]()

[1982. Find Array Given Subset Sums]()
