📦 Sistema de Gestão de Estoque e Vendas (C++)
Aplicação de console desenvolvida em C++ para o gerenciamento completo de um comércio, controlando Entidades como Categorias, Produtos, Clientes, Vendedores e Vendas.

O grande diferencial deste projeto é a manipulação de dados puramente em memória (sem uso de banco de dados), exigindo a implementação manual de algoritmos clássicos de ordenação e busca para garantir a performance e a integridade relacional.

🚀 Destaques Algorítmicos e Técnicos:

Busca Binária (Binary Search - O(log n)): Implementada do zero para validação rápida de chaves primárias (códigos de clientes, produtos, etc.) durante as inserções e vendas.

Ordenação Contínua (Bubble Sort): Lógica implementada para reordenar dinamicamente os arrays de structs a cada novo registro, garantindo o funcionamento correto da busca binária.

Relacionamento em Memória: Simulação de chaves estrangeiras ligando Vendas a Itens de Venda e a Produtos, operando através de iterações em arrays estáticos.

Regras de Negócio de Inventário: Baixa automática de estoque no ato da venda e geração algorítmica de relatórios de reposição (comparando estoque atual vs. estoque mínimo) com cálculo automático de custos.

🛠️ Tecnologias e Conceitos:

C++ (Standard Library)

Manipulação de Arrays e Structs

Passagem de parâmetros por Referência (&)

Algoritmos de Busca e Ordenação
