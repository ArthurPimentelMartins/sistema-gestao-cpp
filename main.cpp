#include <iostream>
#include <string>

struct Categorias {
    int codigo;
    std::string descricao;
};

struct Produtos {
    int codigo;
    std::string descricao;
    int codigo_categoria;
    int quant_estoque;
    int estoque_minimo;
    int estoque_maximo;
    float preco_unitario;
};

struct Clientes {
    int codigo;
    std::string nome;
    std::string endereco;
    std::string telefone;
};

struct Vendedores {
    int codigo;
    std::string nome;
    std::string telefone;
};

struct Vendas {
    int codigo;
    int codigo_cliente;
    int codigo_vendedor;
    std::string data;
};

struct ItensVenda {
    int codigo_venda;
    int codigo_produto;
    int quantidade;
};

//1)
void lerCategorias(Categorias categorias[], int &contCategorias) {
    std::cout << "|||||||||||||||||||||||||||||||||||||\n";
    std::cout << "           LEITURA CATEGORIA         \n";
    std::cout << "|||||||||||||||||||||||||||||||||||||\n\n";

    bool lerMaisUm = true;
    while (lerMaisUm) {
        int codigoTemp;
        std::cout << "Informe o codigo da categoria: ";
        std::cin >> codigoTemp;
        
        std::cin.ignore(); 

        bool codigoExiste = false;
        int inicio = 0;
        int fim = contCategorias - 1;

        while (inicio <= fim) {
            int meio = inicio + (fim - inicio) / 2;

            if (categorias[meio].codigo == codigoTemp) {
                codigoExiste = true;
                break;
            }

            if (categorias[meio].codigo < codigoTemp) {
                inicio = meio + 1;
            } else {
                fim = meio - 1;
            }
        }

        if (codigoExiste) {
            std::cout << "Erro: A categoria com o codigo " << codigoTemp << " ja esta cadastrada!\n";
        } else {
            categorias[contCategorias].codigo = codigoTemp;

            std::cout << "Informe a descricao da categoria: ";
            std::getline(std::cin, categorias[contCategorias].descricao);

            contCategorias++;
            std::cout << "Categoria cadastrada com sucesso!\n";

            for (int i = 0; i < contCategorias - 1; i++) {
                for (int j = 0; j < contCategorias - i - 1; j++) {
                    if (categorias[j].codigo > categorias[j + 1].codigo) {
                        Categorias temp = categorias[j];
                        categorias[j] = categorias[j + 1];
                        categorias[j + 1] = temp;
                    }
                }
            }
        }

        std::string novaCat;
        std::cout << "\nQuer adicionar mais uma categoria? (s/n): ";
        std::getline(std::cin, novaCat);
        
        if (novaCat == "n" || novaCat == "N") {
            lerMaisUm = false;
        }
        std::cout << "\n"; 
    }
}

//1
void lerProdutos(Produtos produtos[], int &contProdutos, Categorias categorias[], int contCategorias) {
    std::cout << "|||||||||||||||||||||||||||||||||||||\n";
    std::cout << "            LEITURA PRODUTO          \n";
    std::cout << "|||||||||||||||||||||||||||||||||||||\n\n";

    if (contCategorias == 0) {
        std::cout << "ERRO: Nenhuma categoria cadastrada no sistema!\n";
        std::cout << "Por favor, acesse a opcao 1 do menu e cadastre categorias primeiro.\n\n";
        return;
    }

    bool lerMaisUm = true;
    while (lerMaisUm) {
        int codigoTemp;
        std::cout << "Informe o codigo do Produto: ";
        std::cin >> codigoTemp;
        
        std::cin.ignore(); 

        bool codigoExiste = false;
        int inicio = 0;
        int fim = contProdutos - 1;

        while (inicio <= fim) {
            int meio = inicio + (fim - inicio) / 2;

            if (produtos[meio].codigo == codigoTemp) {
                codigoExiste = true;
                break; 
            }

            if (produtos[meio].codigo < codigoTemp) {
                inicio = meio + 1; 
            } else {
                fim = meio - 1;    
            }
        }

        if (codigoExiste) {
            std::cout << "Erro: O produto com o codigo " << codigoTemp << " ja esta cadastrado!\n";
        } else {
            produtos[contProdutos].codigo = codigoTemp;

            std::cout << "Informe a descricao do Produto: ";
            std::getline(std::cin, produtos[contProdutos].descricao);

            bool categoriaValida = false;
            int codCatTemp;

            while (!categoriaValida) {
                std::cout << "Informe o codigo da categoria: ";
                std::cin >> codCatTemp;

                bool achouCategoria = false;
                int inicioCat = 0;
                int fimCat = contCategorias - 1;

                while (inicioCat <= fimCat) {
                    int meioCat = inicioCat + (fimCat - inicioCat) / 2;

                    if (categorias[meioCat].codigo == codCatTemp) {
                        achouCategoria = true;
                        std::cout << "   -> Categoria encontrada: " << categorias[meioCat].descricao << "\n";
                        break;
                    }

                    if (categorias[meioCat].codigo < codCatTemp) {
                        inicioCat = meioCat + 1;
                    } else {
                        fimCat = meioCat - 1;
                    }
                }

                if (achouCategoria) {
                    categoriaValida = true; 
                } else {
                    std::cout << "   Erro: Categoria nao encontrada! Digite um codigo valido.\n";
                }
            }
            
            produtos[contProdutos].codigo_categoria = codCatTemp;

            std::cout << "Informe a quantidade maxima do estoque: ";
            std::cin >> produtos[contProdutos].estoque_maximo;

            std::cout << "Informe a quantidade minima do estoque: "; 
            std::cin >> produtos[contProdutos].estoque_minimo;

            if (produtos[contProdutos].estoque_maximo < produtos[contProdutos].estoque_minimo) {
                std::cout << "Erro, estoque Maximo abaixo do Minimo";
                return;
            }

            std::cout << "Informe a quantidade em estoque do produto: ";
            std::cin >> produtos[contProdutos].quant_estoque;

            std::cout << "Informe o preco unitario do produto: ";
            std::cin >> produtos[contProdutos].preco_unitario;
                        
            std::cin.ignore(); 

            contProdutos++;
            std::cout << "Produto cadastrado com sucesso!\n";

            for (int i = 0; i < contProdutos - 1; i++) {
                for (int j = 0; j < contProdutos - i - 1; j++) {
                    if (produtos[j].codigo > produtos[j + 1].codigo) {
                        Produtos temp = produtos[j];
                        produtos[j] = produtos[j + 1];
                        produtos[j + 1] = temp;
                    }
                }
            }
        }

        std::string novoProd;
        std::cout << "\nQuer adicionar mais um produto? (s/n): ";
        std::getline(std::cin, novoProd);
        
        if (novoProd == "n" || novoProd == "N") {
            lerMaisUm = false;
        }
        std::cout << "\n";
    }
}

//2)
void inclusaoClientes(Clientes clientes[], int &cont) {
    std::cout << "|||||||||||||||||||||||||||||||||||||\n";
    std::cout << "            Leitura Cliente          \n"; 
    std::cout << "|||||||||||||||||||||||||||||||||||||\n\n";

    bool lerMaisUm = true;
    while (lerMaisUm) {
        int codigoTemp;
        bool codigoExiste = false;
        
        std::cout << "Informe o codigo do cliente: ";
        std::cin >> codigoTemp;
        
        std::cin.ignore();

        int inicio = 0;
        int fim = cont - 1;

        while (inicio <= fim) {
            int meio = inicio + (fim - inicio) / 2;

            if (clientes[meio].codigo == codigoTemp) {
                codigoExiste = true;
                break;
            }

            if (clientes[meio].codigo < codigoTemp) {
                inicio = meio + 1;
            } else {
                fim = meio - 1;    
            }
        }

        if (codigoExiste) {
            std::cout << "Erro: O cliente com o codigo " << codigoTemp << " ja esta cadastrado!\n";
        } else {
            clientes[cont].codigo = codigoTemp;

            std::cout << "Digite o nome: ";
            std::getline(std::cin, clientes[cont].nome);

            std::cout << "Digite o endereco: ";
            std::getline(std::cin, clientes[cont].endereco);

            std::cout << "Digite o telefone: ";
            std::getline(std::cin, clientes[cont].telefone);

            cont++;
            std::cout << "Cliente cadastrado com sucesso!\n";

            for (int i = 0; i < cont - 1; i++) {
                for (int j = 0; j < cont - i - 1; j++) {
                    if (clientes[j].codigo > clientes[j + 1].codigo) {
                        Clientes temp = clientes[j];
                        clientes[j] = clientes[j + 1];
                        clientes[j + 1] = temp;
                    }
                }
            }
        }

        std::string novoCli;
        std::cout << "\nQuer adicionar mais um cliente? (s/n): ";
        std::getline(std::cin, novoCli);
        
        if (novoCli == "n" || novoCli == "N") {
            lerMaisUm = false;
        }
        std::cout << "\n"; 
    }
}

//3)
void inclusaoVendedores(Vendedores vendedores[], int &cont) {
    std::cout << "|||||||||||||||||||||||||||||||||||||\n";
    std::cout << "           Leitura Vendedores        \n"; 
    std::cout << "|||||||||||||||||||||||||||||||||||||\n\n";

    bool lerMaisUm = true;
    while (lerMaisUm) {
        int codigoTemp;
        bool codigoExiste = false;
        
        std::cout << "Informe o codigo do Vendedor: ";
        std::cin >> codigoTemp;
        
        std::cin.ignore();

        int inicio = 0;
        int fim = cont - 1;

        while (inicio <= fim) {
            int meio = inicio + (fim - inicio) / 2;

            if (vendedores[meio].codigo == codigoTemp) {
                codigoExiste = true;
                break; 
            }

            if (vendedores[meio].codigo < codigoTemp) {
                inicio = meio + 1; 
            } else {
                fim = meio - 1;    
            }
        }

        if (codigoExiste) {
            std::cout << "Erro: O vendedor com o codigo " << codigoTemp << " ja esta cadastrado!\n";
        } else {
            vendedores[cont].codigo = codigoTemp;

            std::cout << "Digite o nome: ";
            std::getline(std::cin, vendedores[cont].nome);

            std::cout << "Digite o telefone: ";
            std::getline(std::cin, vendedores[cont].telefone);

            cont++;
            std::cout << "Vendedor cadastrado com sucesso!\n";

            for (int i = 0; i < cont - 1; i++) {
                for (int j = 0; j < cont - i - 1; j++) {
                    if (vendedores[j].codigo > vendedores[j + 1].codigo) {
                        Vendedores temp = vendedores[j];
                        vendedores[j] = vendedores[j + 1];
                        vendedores[j + 1] = temp;
                    }
                }
            }
        }

        std::string novoVend;
        std::cout << "\nQuer adicionar mais um vendedor? (s/n): ";
        std::getline(std::cin, novoVend);
        
        if (novoVend == "n" || novoVend == "N") {
            lerMaisUm = false;
        }
        std::cout << "\n";
    }
}

//5)
void inclusaoItensVenda(ItensVenda itensVenda[], int &contItensVenda, Produtos produtos[], int contProdutos, int codigoVendaAtual) {
    std::cout << "|||||||||||||||||||||||||||||||||||||\n";
    std::cout << "           Leitura Itens Venda       \n";
    std::cout << "|||||||||||||||||||||||||||||||||||||\n\n";

    int codProduto;
    std::cout << "Digite o codigo do Produto: ";
    std::cin >> codProduto;
    std::cin.ignore(); 

    bool produtoEncontrado = false;
    int indiceProd = -1; 

    int inicio = 0;
    int fim = contProdutos - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (produtos[meio].codigo == codProduto) {
            produtoEncontrado = true;
            std::cout << "Produto encontrado: " << produtos[meio].descricao << "\n";
            std::cout << "Preco unitario: R$ " << produtos[meio].preco_unitario << "\n";
            indiceProd = meio;
            break;
        }

        if (produtos[meio].codigo < codProduto) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;   
        }
    }

    if (produtoEncontrado) {
        int qntItensPedidos;
        std::cout << "Digite a quantidade de Itens: ";
        std::cin >> qntItensPedidos;
        std::cin.ignore();

        if (qntItensPedidos <= produtos[indiceProd].quant_estoque) {
            produtos[indiceProd].quant_estoque -= qntItensPedidos; 
            
            itensVenda[contItensVenda].codigo_produto = codProduto;
            itensVenda[contItensVenda].quantidade = qntItensPedidos;
            itensVenda[contItensVenda].codigo_venda = codigoVendaAtual;
            
            contItensVenda++;
            std::cout << "Item adicionado a venda com sucesso!\n";
            
        } else {
            std::cout << "Erro: Quantidade insuficiente no estoque. Temos apenas " << produtos[indiceProd].quant_estoque << " itens.\n"; 
        }
    } else {
        std::cout << "Erro: Produto nao encontrado!\n";
    }
}

//4)
void registroVendas(Vendas vendas[], int &contVendas, Clientes clientes[], int contClientes, Vendedores vendedores[], int contVendedores, ItensVenda itensVenda[], int &contItensVenda, Produtos produtos[], int contProdutos) {
    std::cout << "|||||||||||||||||||||||||||||||||||||\n";
    std::cout << "          Registro de Venda          \n";
    std::cout << "|||||||||||||||||||||||||||||||||||||\n\n";

    if (contClientes == 0 || contVendedores == 0 || contProdutos == 0) {
        std::cout << "ERRO: O sistema nao atende aos requisitos minimos para uma venda!\n";
        std::cout << "Clientes cadastrados: " << contClientes << "\n";
        std::cout << "Vendedores cadastrados: " << contVendedores << "\n";
        std::cout << "Produtos cadastrados: " << contProdutos << "\n\n";
        std::cout << "Por favor, cadastre pelo menos um de cada antes de vender.\n";
        return; 
    }

    int codVenda;
    std::cout << "Digite o codigo da Venda: ";
    std::cin >> codVenda;
    std::cin.ignore(); 
 
    bool vendaExiste = false;
    int inicioV = 0;
    int fimV = contVendas - 1;

    while (inicioV <= fimV) {
        int meio = inicioV + (fimV - inicioV) / 2;

        if (vendas[meio].codigo == codVenda) {
            vendaExiste = true;
            break;
        }
        
        if (vendas[meio].codigo < codVenda) {
            inicioV = meio + 1;
        } else {
            fimV = meio - 1;
        }
    }
    
    if (vendaExiste) {
        std::cout << "Erro: A venda com o codigo " << codVenda << " ja esta registrada!\n";
        return; 
    }

    std::string dataVenda;
    std::cout << "Digite a Data da venda: ";
    std::getline(std::cin, dataVenda);

    int codCliente;
    std::cout << "Digite o codigo de Cliente: ";
    std::cin >> codCliente;
    
    bool clienteEncontrado = false;
    int inicioC = 0;
    int fimC = contClientes - 1;

    while (inicioC <= fimC) {
        int meio = inicioC + (fimC - inicioC) / 2;

        if (clientes[meio].codigo == codCliente) {
            clienteEncontrado = true;
            std::cout << "Cliente encontrado: " << clientes[meio].nome << "\n";
            vendas[contVendas].codigo_cliente = codCliente;
            break;
        }
        if (clientes[meio].codigo < codCliente) {
            inicioC = meio + 1;
        } else {
            fimC = meio - 1;
        }
    }

    if (!clienteEncontrado) {
        std::cout << "Erro: Cliente nao encontrado! Operacao cancelada.\n";
        return; 
    }
  
    int codVendedor;
    std::cout << "Digite o codigo do Vendedor: ";
    std::cin >> codVendedor;
    std::cin.ignore();

    bool vendedorEncontrado = false;
    int inicioVend = 0;
    int fimVend = contVendedores - 1;

    while (inicioVend <= fimVend) {
        int meio = inicioVend + (fimVend - inicioVend) / 2;

        if (vendedores[meio].codigo == codVendedor) {
            vendedorEncontrado = true;
            std::cout << "Vendedor encontrado: " << vendedores[meio].nome << "\n";
            vendas[contVendas].codigo_vendedor = codVendedor;
            break;
        }
        if (vendedores[meio].codigo < codVendedor) {
            inicioVend = meio + 1;
        } else {
            fimVend = meio - 1;
        }
    }

    if (!vendedorEncontrado) {
        std::cout << "Erro: Vendedor nao encontrado! Operacao cancelada.\n";
        return; 
    }

    int itensAntesDaVenda = contItensVenda; 

    bool lerMaisUm = true;
    while (lerMaisUm) {
        std::cout << "\nDeseja adicionar um item a venda? (s/n): ";
        std::string resposta;
        std::getline(std::cin, resposta);
        
        if (resposta == "n" || resposta == "N") {
            lerMaisUm = false;
        } else {
            inclusaoItensVenda(itensVenda, contItensVenda, produtos, contProdutos, codVenda);
        }
    }
    
    if (contItensVenda > itensAntesDaVenda) {
        vendas[contVendas].codigo = codVenda;
        vendas[contVendas].data = dataVenda;
        contVendas++;
        
        for (int i = 0; i < contVendas - 1; i++) {
            for (int j = 0; j < contVendas - i - 1; j++) {
                if (vendas[j].codigo > vendas[j + 1].codigo) {
                    Vendas temp = vendas[j];
                    vendas[j] = vendas[j + 1];
                    vendas[j + 1] = temp;
                }
            }
        }

        std::cout << "\nVenda registrada com sucesso!\n";
    } else {
        std::cout << "\nErro: Nenhum produto foi adicionado. A venda foi CANCELADA!\n";
        std::cout << "(O codigo " << codVenda << " continua livre para ser usado).\n";
    }
}

//6)
void consultarProdutos(Produtos produtos[], int contProdutos) {
    std::cout << "|||||||||||||||||||||||||||||||||||||\n";
    std::cout << "           INICIANDO CONSULTA        \n";
    std::cout << "|||||||||||||||||||||||||||||||||||||\n\n";

    bool consultarMaisUm = true;
    while (consultarMaisUm) {
        int codProd;
        std::cout << "Digite o codigo do Produto: ";
        std::cin >> codProd;
        
        std::cin.ignore(); 

        bool produtoEncontrado = false;

        for(int i = 0; i < contProdutos; i++) {
            if (codProd == produtos[i].codigo) {
                std::cout << "\n--- Produto Encontrado ---\n";
                std::cout << "Descricao: " << produtos[i].descricao << "\n";
                std::cout << "Codigo da Categoria: " << produtos[i].codigo_categoria << "\n";
                std::cout << "Quantidade em estoque: " << produtos[i].quant_estoque << "\n";
                std::cout << "Estoque Minimo: " << produtos[i].estoque_minimo << "\n";
                std::cout << "Estoque Maximo: " << produtos[i].estoque_maximo << "\n";
                std::cout << "Preco Unitario: R$ " << produtos[i].preco_unitario << "\n";
                std::cout << "Preco total Estoque: R$ " << produtos[i].quant_estoque * produtos[i].preco_unitario << "\n";
                std::cout << "--------------------------\n";

                produtoEncontrado = true;
                break;
            } 
        }

        if (!produtoEncontrado) {
            std::cout << "Erro: Codigo de Produto nao encontrado.\n";
        }

        std::string novaConsulta;
        std::cout << "\nDeseja consultar outro produto? (s/n): ";
        std::getline(std::cin, novaConsulta);
        
        if (novaConsulta == "n" || novaConsulta == "N") {
            consultarMaisUm = false;
        }
        std::cout << "\n";
    }
}

//7)
void produtosAbaixoDoMinimo(Produtos produtos[], int contProdutos) {
    std::cout << "|||||||||||||||||||||||||||||||||||||\n";
    std::cout << "        RELATORIO DE REPOSICAO       \n";
    std::cout << "|||||||||||||||||||||||||||||||||||||\n\n";

    float totalGeralReposicao = 0.0;
    bool precisaReposicao = false;

    for(int i = 0; i < contProdutos; i++) {
        if (produtos[i].quant_estoque < produtos[i].estoque_minimo) {
            precisaReposicao = true;
            
            std::cout << "--- PRODUTO ABAIXO DO ESTOQUE MINIMO ---\n";
            std::cout << "Codigo: " << produtos[i].codigo << "\n";
            std::cout << "Descricao: " << produtos[i].descricao << "\n";
            std::cout << "Quantidade em estoque: " << produtos[i].quant_estoque << "\n";
            std::cout << "Estoque Maximo: " << produtos[i].estoque_maximo << "\n";

            int qntProdComprar = produtos[i].estoque_maximo - produtos[i].quant_estoque;
            float valorCompra = qntProdComprar * produtos[i].preco_unitario;

            std::cout << "\n>> ACAO: FAZER REPOSICAO <<\n";
            std::cout << "Quantidade a ser comprada: " << qntProdComprar << "\n";
            std::cout << "Valor da compra: R$ " << valorCompra << "\n";
            std::cout << "----------------------------------------\n\n";

            totalGeralReposicao += valorCompra;
        }
    }

    if (!precisaReposicao) {
        std::cout << "Todos os produtos estao com o estoque em dia!\n\n";
    } else {
        std::cout << "========================================\n";
        std::cout << "VALOR TOTAL PARA A REPOSICAO: R$ " << totalGeralReposicao << "\n";
        std::cout << "========================================\n\n";
    }
}

//8)
void totalVendas(ItensVenda itensVenda[], int contItensVenda, Produtos produtos[], int contProdutos) {
    std::cout << "|||||||||||||||||||||||||||||||||||||\n";
    std::cout << "         RELATORIO DE VENDAS         \n";
    std::cout << "|||||||||||||||||||||||||||||||||||||\n\n";

    if (contItensVenda == 0) {
        std::cout << "Aviso: Nenhuma venda foi registrada ainda no sistema.\n\n";
        return; 
    }

    float somaTotal = 0.0;
    std::cout << "Processando todos os itens vendidos...\n";
    
    for (int i = 0; i < contItensVenda; i++) {
        int codProduto = itensVenda[i].codigo_produto;
        
        int inicio = 0;
        int fim = contProdutos - 1;

        while (inicio <= fim) {
            int meio = inicio + (fim - inicio) / 2;

            if (produtos[meio].codigo == codProduto) {
                somaTotal += produtos[meio].preco_unitario * itensVenda[i].quantidade;
                break; 
            }

            if (produtos[meio].codigo < codProduto) {
                inicio = meio + 1; 
            } else {
                fim = meio - 1; 
            }
        }
    }

    std::cout << "----------------------------------------\n";
    std::cout << "VALOR TOTAL ARRECADADO: R$ " << somaTotal << "\n";
    std::cout << "----------------------------------------\n\n";
}

//9)
void exclusaoClientes(Clientes clientes[], int &contClientes) {
    std::cout << "|||||||||||||||||||||||||||||||||||||\n";
    std::cout << "         EXCLUSAO DE CLIENTE         \n";
    std::cout << "|||||||||||||||||||||||||||||||||||||\n\n";

    if (contClientes == 0) {
        std::cout << "Aviso: Nenhum cliente cadastrado no sistema ainda.\n\n";
        return; 
    }

    bool clienteEncontrado = false;
    int codCliente;

    std::cout << "Digite o codigo do Cliente que deseja excluir: ";
    std::cin >> codCliente;
    std::cin.ignore();

    int inicio = 0;
    int fim = contClientes - 1;
    int indiceExclusao = -1; 

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (clientes[meio].codigo == codCliente) {
            indiceExclusao = meio;
            clienteEncontrado = true;
            break; 
        }

        if (clientes[meio].codigo < codCliente) {
            inicio = meio + 1; 
        } else {
            fim = meio - 1;   
        }
    }

    if (clienteEncontrado) {
        for (int j = indiceExclusao; j < contClientes - 1; j++) {
            clientes[j] = clientes[j + 1];
        }
        
        contClientes--;
        std::cout << "\nCliente excluido com sucesso!\n\n";
    } else {
        std::cout << "\nErro: O codigo do cliente nao foi encontrado.\n\n";
    }
}

int main(){
    Categorias categorias[50];
    int contCategorias = 0;
    
    Produtos produtos[100];
    int contProdutos = 0;
    
    Clientes clientes[100];
    int contClientes = 0;
    
    Vendedores vendedores[50];
    int contVendedores = 0;
    
    Vendas vendas[200];
    int contVendas = 0;
    
    ItensVenda itensVenda[500];
    int contItensVenda = 0;

    int opcao;

    do {
        system("cls");

        std::cout << "\n========================================\n";
        std::cout << "          SISTEMA DE GERENCIAMENTO      \n";
        std::cout << "========================================\n";
        std::cout << "1 - Cadastrar Categorias\n";
        std::cout << "2 - Cadastrar Produtos\n";
        std::cout << "3 - Cadastrar Cliente\n";
        std::cout << "4 - Cadastrar Vendedor\n";
        std::cout << "5 - Registrar Nova Venda\n";
        std::cout << "6 - Consultar Produto\n";
        std::cout << "7 - Relatorio: Estoque Abaixo do Minimo\n";
        std::cout << "8 - Relatorio: Total de Vendas\n";
        std::cout << "9 - Excluir Cliente\n";
        std::cout << "0 - Sair\n";
        std::cout << "========================================\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        std::cin.ignore(); 
        std::cout << "\n";

        switch (opcao) {
            case 1:
                lerCategorias(categorias, contCategorias);
                break;
                
             case 2:
                lerProdutos(produtos, contProdutos, categorias, contCategorias);
                break;

            case 3:
                inclusaoClientes(clientes, contClientes);
                break;

            case 4:
                inclusaoVendedores(vendedores, contVendedores);
                break;

            case 5:
                registroVendas(vendas, contVendas, clientes, contClientes, vendedores, contVendedores, itensVenda, contItensVenda, produtos, contProdutos);
                break;

            case 6:
                consultarProdutos(produtos, contProdutos);
                break;

            case 7:
                produtosAbaixoDoMinimo(produtos, contProdutos);
                break;

            case 8:
                totalVendas(itensVenda, contItensVenda, produtos, contProdutos);
                break;

            case 9:
                exclusaoClientes(clientes, contClientes);
                break;

            case 0:
                std::cout << "Encerrando o sistema... Obrigado por utilizar!\n";
                break;

            default:
                std::cout << "Opcao invalida! Por favor, digite um numero de 0 a 9.\n";
                break;
        }

        if (opcao != 0) {
            std::cout << "\n[ Pressione ENTER para voltar ao menu principal... ]";
            std::string pausa;
            std::getline(std::cin, pausa); 
        }

    } while (opcao != 0);

    return 0;
}