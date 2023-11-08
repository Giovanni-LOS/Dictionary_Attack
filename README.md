# Projeto de um ataque de força bruta do tipo "ataque de dicionário" em C.

- Este projeto consiste em um software em linguagem C para a partir de um arquivo de usuários com senhas criptografadas com SHA256 e um arquivo de senhas em claro consideradas fracas, produzir um relatório de quebra de senhas, que indica quais usuários tiveram a sua senha quebrada e constitui a entrega total do trabalho 3 da disciplina de Programação de Computadores 1 (semestre 2023/2) do Instituto Federal de Brasília.

- Compilação:
    1. Através do arquivo makefile, utilizando o comando Make. ($ make)
    2. Execução do programa gerado. ($ ./main arquivo_usuarios arquivo_senhas relatório)

- Execução
    1. Linha de comando passando 3 argumentos junto à execução do programa.
        - Obs.: Os argumentos devem ser passados na seguinte ordem:
            - Arquivo de usuários
            - Arquivo de senhas
            - Arquivo de relatório
        - Exemplo: $ ./main arquivo_usuarios arquivo_senhas relatório
        - Obs.: Os arquivos de usuários e senhas devem estar no mesmo diretório do programa.
        - Obs.: O arquivo de relatório será gerado no mesmo diretório do programa.

- Desenvolvimento
    1. Desenvolvido na plataforma Clion (2023.2.2), compilador GNU gcc/g++.
    2. Testado no sistema operacional Arch Linux (Kernel 5.14.2-arch1-1 x86_64).
    3. Make version 4.4.1 .


- Autoria e contribuições:
  Giovanni L. O. da Silva Copyright (c) 2023 Author. All Rights Reserved.