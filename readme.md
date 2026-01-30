High-Performance Generic ArrayList in C (SBO Optimized)

Uma implementação de lista dinâmica baseada no Array List do Java em C puro. Esta, projetada com foco em localidade de dados e eficiência de memória. O projeto utiliza técnicas avançadas de gerenciamento de memória manual para minimizar cache misses e reduzir fragmentação da Heap.

Diferenciais Técnicos:
-Small Buffer Optimization(SBO) -> Se o dado for menor ou igual a 56 bytes, ele é armazenado inLine dentro da estrutura da lista (Stack-friendly), evitando alocações dinâmicas desnecessárias.

-Cache Line Alignment (64 bytes) -> A estrutura MemoryCell foi projetada para ocupar exatamente 64 bytes, garantindo que cada elemento se alinhe perfeitamente com uma linha de cache L1 em arquiteturas modernas de 64 bits.

-Tipagem Genérica e Segura -> Utiliza void* para suportar qualquer tipo de dado, mantendo a segurança através de um controle de tamanho (typeControl) definido na inicialização.

-Crescimento Amortizado -> Implementa expansão dinâmica de capacidade para garantir performance consistente em inserções em larga escala.

Arquitetura de memória:
Este projeto utiliza um union estratégico para otimizar o uso de memória inLine com dados pequenos, ao invés de alocar toda a memória na Heap e submeter a execução a uma "Busca de Ponteiros".

Em sistemas de alto desempenho, o gargalo difícilmente está no desempenho, localizando-se, principalmente, ao acesso da memória principal (RAM). Ao alinhar a célula ao Cache Line, garantimos que a CPU carregue o dado em um único ciclo de barramento sempre que possível, minimizando saltos de memória e, eliminando-os completamente em tipos primitivos e structs pequenas.

Memory Layout (Small Mode - Stack/Cache Friendly):
[ Mode (4b) | Padding (4b) | Data (56b - Inline) ] 
Total: 64 bytes (1 Cache Line)

Memory Layout (Big Mode - Heap):
[ Mode (4b) | Padding (4b) | Pointer (8b) | ... Unused ... ]
----> [ Data on Heap ]

Como Compilar e Rodar:
O projeto inclui um Makefile para automação do processo de build.

Pré-requisitos(GNU, Make)

Comandos:
-Compilar o projeto -> make build

-Executar teste de dados pequenos -> make run Mode=1

-Executar teste de dados grandes -> make run Mode=2

-Limpar binários -> make clear

----------------------------------------------------------------------

Desenvolvido por Gustavo Martinho Fernandes - Estudante de Ciência da Computação - IFMG Formiga


