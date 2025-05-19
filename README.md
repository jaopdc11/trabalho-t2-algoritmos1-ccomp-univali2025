# Mastermind - Algoritmos e Programação

## Sobre o Trabalho

Este projeto é uma implementação do clássico jogo de lógica **Mastermind** para a disciplina de Algoritmos e Programação 1, solicitado pelo professor Rafael Ballottin na Universidade do Vale do Itajaí (UNIVALI).

O objetivo do trabalho é exercitar lógica de programação, controle de fluxo, uso de variáveis simples e interação com o usuário, **sem utilizar arrays ou funções**, e mantendo todo o código dentro da função `main()`.

---

## Equipe

- João Pedro da Conceição Simas
- Clara Haag Rodrigues
- Leonardo de Souza Pereira

Professor: **Rafael Ballottin**  
Disciplina: **Algoritmos e Programação**  
Data: **Maio/2025**

---

## Regras do Jogo

- O computador gera um codigo secreto composto por **4 números diferentes** entre 1 e 6.
- O jogador tem **10 tentativas** para adivinhar o código.
- Após cada tentativa, o programa informa:
  - Quantos números estão corretos e na posição correta (pinos pretos).
  - Quantos números estão corretos, mas em posição errada (pinos brancos).
- Não é permitido repetir números no palpite.
- O jogo termina quando o jogador acerta o código ou esgota as tentativas.

---

## Estrutura do Programa

O programa é composto por um **menu principal** com três opções:

1. **Jogar**: Inicia o jogo Mastermind.
2. **Sobre**: Exibe informações sobre o trabalho, equipe e regras do jogo.
3. **Sair**: Encerra o programa.

---

## Decisões de Implementação

- **Sem arrays e funções**: Todo o código está dentro do `main()`, utilizando apenas variáveis simples, conforme exigido no enunciado.
- **Geração do código**: Utilizamos a função `rand()` para gerar cada número do código, garantindo que não haja repetições.
- **Validação de entrada**: O programa verifica se o palpite do usuário está dentro do intervalo permitido (1 a 6) e se não há números repetidos.
- **Cálculo dos pinos pretos e brancos**: A lógica compara cada posição do palpite com o código para contar acertos exatos (pretos) e acertos fora de posição (brancos).
- **Comentários detalhados**: O código está amplamente comentado para facilitar o entendimento, conforme orientação do professor.

---

## Como Executar

1. Compile o arquivo `.cpp` em qualquer compilador C++ padrão.
2. Execute o programa no terminal.
3. Siga as instruções do menu para jogar, ler sobre o trabalho ou sair.

---

## Observações

- O código foi desenvolvido para ser o mais didático possível, priorizando clareza e organização.
- Todos os requisitos do enunciado foram seguidos à risca.
- O programa retorna ao menu principal após cada ação, exceto ao sair.

---
