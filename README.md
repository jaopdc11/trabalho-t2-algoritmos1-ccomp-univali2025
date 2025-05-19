# Mastermind - Algoritmos e Programação

## Sobre o Trabalho

Este projeto é uma implementação do clássico jogo de lógica **Mastermind** (ou "Senha") para a disciplina de Algoritmos e Programação 1, solicitado pelo professor Rafael Ballottin na Universidade do Vale do Itajaí (UNIVALI).

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

## Sobre o Locale e Acentuação

Para garantir que os nomes dos integrantes e todas as mensagens do programa apareçam corretamente com acentos (ç, ã, é, etc.), foi utilizado o comando:

```cpp
setlocale(LC_ALL, "Portuguese");
```

- **Por que isso é importante?**  
  Sem esse comando, dependendo do computador, os acentos podem aparecer como símbolos estranhos ou não aparecer.
- **Por que não usar aspas vazias ("")?**  
  Se usar `setlocale(LC_ALL, "")`, o programa pega o idioma do computador onde foi compilado, o que pode não ser português. Por isso, foi definido explicitamente `"Portuguese"`.

---

## Regras do Jogo

- O computador gera um código secreto composto por **4 números diferentes** entre 1 e 6.
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
- **Geração do código**: Utilizamos a função `rand()` para gerar cada número do código, garantindo que não haja repetições. O uso de `srand()` pode ser feito com um valor fixo ou com `time(0)`, dependendo do que foi permitido pelo professor.
- **Validação de entrada**: O programa verifica se o palpite do usuário está dentro do intervalo permitido (1 a 6) e se não há números repetidos.
- **Cálculo dos pinos pretos e brancos**: A lógica compara cada posição do palpite com o código para contar acertos exatos (pretos) e acertos fora de posição (brancos).
- **Limpeza de tela e pausa**: Utiliza apenas comandos ensinados em aula, como `system("cls")` para limpar o terminal e `system("pause")` para pausar a execução.
- **Comentários detalhados**: O código está amplamente comentado para facilitar o entendimento, conforme orientação do professor.
- **Sem bibliotecas avançadas**: Não são utilizados arrays, funções, `cin.ignore`, nem bibliotecas além das básicas (`iostream`, `cstdlib` e `locale.h`).

---

## Como Jogar

- **Importante:** Sempre digite os 4 números do palpite separados por espaço na mesma linha (exemplo: `2 4 5 1`) e pressione Enter.
- Se digitar menos de 4 números, o programa aguardará a entrada dos demais.
- Caso digite números repetidos ou fora do intervalo, será exibida uma mensagem de erro e você poderá tentar novamente sem perder tentativa.

---

## Observações

- Todos os requisitos do enunciado foram seguidos à risca.
- O programa retorna ao menu principal após cada ação, exceto ao sair.
- **Acentuação garantida:** O comando `setlocale(LC_ALL, "Portuguese");` garante que nomes e mensagens apareçam corretamente, independentemente do computador.

---