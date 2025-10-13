# Dicionario-de-Ingles

1. Dados Gerais  
    Este trabalho tem como objetivo desenvolver um dicionário simplificado de inglês. Na aplicação,  
    deverá ser possível inserir novas palavras, consultar palavras e removê-las. Para armazenar as palavras  
    contidas no dicionário, deve ser utilizada uma estrutura de dados dinâmica não linear.

2. Estrutura de Armazenamento  
    Para armazenar as palavras do dicionário deve ser utilizada uma Árvore Binária de Busca (BST – Binary  
    Search Tree), conforme visto em aula. Dessa maneira, cada um dos nós deve armazenar um objeto que  
    representará uma palavra do dicionário, contendo a palavra em inglês, a sua tradução em português e a  
    classificação gramatical da palavra (substantivo, verbo, adjetivo, pronome, artigo, preposição, numeral,  
    advérbio, preposição, conjunção e interjeição). Neste cenário, considere que a chave de cada nó é a  
    palavra em inglês.

3. Inserção Inicial de Palavras: Inicialização  
    Inicialmente, o dicionário de inglês encontra-se vazio, sem nenhuma palavra. Para efetuar o  
    preenchimento inicial do dicionário, façam uso de um arquivo de palavras. Esse arquivo deve conter uma  
    quantidade considerável de palavras iniciadas com as diferentes letras do alfabeto. O arquivo deve  
    possuir formatação adequada que permita a sua leitura e a obtenção das informações necessárias de  
    cada palavra. As palavras devem estar ordenadas no arquivo.

    Lembrem-se que as operações realizadas em uma árvore binária de busca apresentam desempenho  
    diretamente proporcional à altura da árvore. Ao mesmo tempo, sabe-se que a altura de uma árvore  
    binária de busca será definida a partir da ordem em que seus elementos são inseridos na estrutura.  
    Assim, árvores contendo os mesmos elementos podem ter alturas bastante diferentes.

    Apenas como exemplo, se os n elementos de uma árvore binária de busca forem inseridos de forma  
    ordenada crescente ou decrescente em relação as suas chaves, teremos como resultado uma árvore  
    degenerada, que apresentará altura igual a n (máxima) e se comportará de forma bastante semelhante  
    a uma lista encadeada. Logo, as operações efetuadas nesta árvore tornam-se de pior caso com  
    complexidade O(n).

    Outra informação importante é que a altura esperada de uma BST com inserções aleatórias é log n,  
    uma vez que a probabilidade de ocorrer o pior caso é muito pequena. Assim, podemos afirmar que inserir  
    elementos aleatoriamente resulta em uma árvore com altura próxima da sua versão mais balanceada.  
    Portanto, as operações efetuadas nesta árvore tornam-se de complexidade O(log n).

    Considerando essas características da árvore binária de busca, observa-se que não é uma boa escolha  
    inserir as palavras na ordem em que elas estão dispostas no arquivo de palavras, pois isso criaria uma  
    árvore binária de busca de altura igual ao número de palavras presentes no arquivo. Deste modo, é  
    necessário que as palavras sejam inseridas na BST de maneira aleatória.

    Uma alternativa discutida em sala de aula foi a possibilidade de inserir as palavras presentes no  
    arquivo em alguma estrutura de dados temporária como uma lista duplamente encadeada com inserção  
    realizada apenas em uma de suas extremidades. A partir dela, sabendo do seu tamanho (número de  
    elementos), pode-se sortear a posição de um elemento da lista onde será obtida a palavra a ser inserida  
    na árvore binária de busca. Para encontrar a palavra, pode-se iniciar o percurso na lista pela sua cabeça  
    (head) ou pela sua cauda (tail), o que for mais próximo. Por exemplo, se em uma lista contendo 100  
    palavras, a posição sorteada é a de número 93, então podemos iniciar a busca pela cauda da lista. Com  
    isso teremos um caminho mais curto a percorrer do que se a busca fosse iniciada a partir da cabeça da  
    lista. Ao encontrar a posição procurada, a palavra é removida da lista duplamente encadeada e inserida  
    na BST. Este procedimento é repetido até que a lista duplamente encadeada se torne vazia e,  
    consequentemente, todas as palavras obtidas do arquivo estejam inseridas na BST.

4. Operações Após Inicialização  
    Após o dicionário ter sido inicializado com as palavras do arquivo, algumas devem ser disponibilizadas  
    para o usuário, tais como:  
    i. busca por uma palavra em inglês, retornando a sua tradução em português;  
    ii. remoção de uma palavra do dicionário;  
    iii. adição de novas palavras;  
    iv. percurso em ordem na árvore BST e  
    v. percurso em largura na árvore.  

    Considere que nos algoritmos de percurso, a ação de visitar um nó corresponde a imprimir a palavra  
    em inglês em tela ou em um arquivo de texto.
