Questão 1112 do site [VJudge](https://vjudge.net)

O problema consistia contar quantos ratos chegariam na saída dentro do tempo do timer.

Para isso, foi implementado um djikstra de cada nó (incluindo o próprio nó saída) para o nó saída, verificando se o peso do menor caminho entre os dois era igual ou menor que o timer. 

![submissão aceita](AC.png)