# Biblioteca C para o "Programming Abstractions in C" (PAIC)

A biblioteca `CRpaic` é uma biblioteca C especificamente projetada para o estudo
do livro "**Programming Abstractions in C: A Second Course in Computer
Science**" (PAIC). Este livro foi escrito por [Eric
S. Roberts](https://cs.stanford.edu/people/eroberts) em 1997, mas considero que
é, até hoje, um dos melhores livros para aprender conceitos importantes de
algoritmos e estruturas de dados, usando a linguagem C como ferramenta de
implementação. Aqui está a imagem da capa do livro:

![Foto da cada do
PAIC](https://raw.githubusercontent.com/computacaoraiz/CRpaic/master/imgs/paic.jpg)


# Sobre a `CRpaic`

Em 1995, Eric S. Roberts publicou um livro de introdução à ciência da computação
voltado para alunos totalmente iniciantes e sem experiência em C, chamado "**The
Art and Science of C: A Library-Based Introduction to Computer Science**":

![Foto da cada do
TAASOC](https://raw.githubusercontent.com/computacaoraiz/CRpaic/master/imgs/taasoc.jpg)

Para facilitar o aprendizado pelos alunos, Roberts criou uma biblioteca C
especial que acompanhava o livro, a **`cslib`**. Essa biblioteca exporta
diversos tipos de dados e subprogramas para facilitar o aprendizado pelos
alunos.

Em 1997, ao publicar o "**Programming Abstractions in C**", Roberts aproveitou a
mesma biblioteca.

A **`cslib`** é uma grande biblioteca com facilidades de
entrada e saída de dados, janelas gráficas, alocação de memória e muitas outras
facilidades para os alunos. Infelizmente seus quase 30 anos fizeram com que
algumas coisas não funcionem corretamente hoje em dia (em especial as
facilidades gráficas da biblioteca apresentam alguns problemas que, em
determinadas situações, podem congelar completamente seu computador). De
qualquer forma a idéia de Roberts foi importante e diversos cursos se basearam
na `cslib` para criar bibliotecas mais atuais para os alunos (por exemplo: a
disciplina [CS50: Introduction do Computer
Science](https://cs50.harvard.edu/x/), da Universidade de Harvard, criou a
[`libcs50`](https://github.com/cs50/libcs50) totalmente baseada e inspirada na
`cslib` de Roberts).

A **`CRpaic`** nasceu nesse mesmo movimento: fornecer uma biblioteca C para
facilitar o aprendizado dos alunos, mas com a característica de ser uma
biblioteca totalmente voltara para o estudo do PAIC (o que é indicado até mesmo
pelo nome: o "CR", obviamente, é de Comutação Raiz, e o "paic" é um acrônimo
formado com a primeira letra das palavras do título do livro). Algumas
características da `CRpaic`:

* É uma biblioteca especificamente projetada para o estudo do PAIC (mas pode ser
  utilizada em outros programas e estudos também);
* Foi baseada na `cslib` (Roberts) e na `libcs50` (Harvard); e
* É mais simples que a `cslib`: foram retirados diversos subprogramas que
  "facilitavam demais" a vida para os estudantes, por exemplo, os subprogramas
  de alocação dinâmica de memória (a motivação para isso é que o PAIC não é um
  curso introdutório e, nesse caso, espera-se que os alunos conheçam ou aprendam
  funcionalidades mais avançadas de C).

(restante em breve)
