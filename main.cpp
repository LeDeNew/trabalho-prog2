#include <iostream>
#include <string>
#include <algorithm>
#include <assert.h>
using namespace std;

// Struct = Feito
typedef struct
{
    string nome_livro;
    string autor_livro;
    int ano_lancamento_livro;
    string estilo_livro;
} biblioteca;

// Declarando variaveis globais
int opcao = 0;
int opcao_busca = 0;
int numero_de_livros = 0;
biblioteca *lista = NULL;
char desejo;

void imprimir_entrada_biblioteca()
{
    cout << "Bem vindo a sua biblioteca virtual!!!" << endl;
    cout << endl;
    cout << "Selecione alguma das opcoes de busca: " << endl;
    cout << "1 - Mostrar todos os livros salvos:" << endl
         << "2 - Buscar Livros:" << endl
         << "3 - Adicionar Livros:" << endl
         << "4 - Ordenar ano de lancamento dos livros:" << endl
         << "5 - Sair:" << endl;
}

void imprimir_busca()
{
    cout << "Selecione alguma das opcoes de busca: " << endl;
    cout << "1 - Buscar nome do Livro:" << endl
         << "2 - Buscar autor do Livro:" << endl
         << "3 - Buscar ano de lancamento do Livro:" << endl
         << "4 - Buscar estilo do Livro (Ex: Romance, Ficcao, Poesia, Fabula etc):" << endl
         << "5 - Sair:" << endl;
}

int verificando_anos(int &ano)
{
    while (true)
    {
        if (cin >> ano)
        {
            cin.ignore();
            if (ano >= 1 && ano <= 2024)
            {
                return ano;
            }
            else
            {
                cout << "Opcao invalida! Por favor, digite um ano existente." << endl;
            }
        }
        else
        {
            cout << "Entrada invalida! Por favor, digite um ano." << endl;
            cin.clear();
        }
    }
}

void adicionar_livros()
{
    cout << "Adicione o nome do seu livro: ";
    biblioteca novoLivro;
    getline(cin, novoLivro.nome_livro);
    transform(novoLivro.nome_livro.begin(), novoLivro.nome_livro.end(), novoLivro.nome_livro.begin(), ::toupper);
    cout << endl
         << "Adicione o autor(a) do seu livro: ";
    getline(cin, novoLivro.autor_livro);
    transform(novoLivro.autor_livro.begin(), novoLivro.autor_livro.end(), novoLivro.autor_livro.begin(), ::toupper);

    cout << endl
         << "Adicione o ano de lancamento do seu livro: ";
    verificando_anos(novoLivro.ano_lancamento_livro);
    cin.clear();

    cout << endl
         << "Adicione o estilo do seu livro (Ex: Romance, Ficcao, Poesia, Fabula etc): ";
    getline(cin, novoLivro.estilo_livro);
    transform(novoLivro.estilo_livro.begin(), novoLivro.estilo_livro.end(), novoLivro.estilo_livro.begin(), ::toupper);

    // Alocação de memória = Feito
    biblioteca *tempLista = new biblioteca[numero_de_livros + 1];
    for (int i = 0; i < numero_de_livros; ++i)
    {
        tempLista[i] = lista[i];
    }
    tempLista[numero_de_livros] = novoLivro;
    delete[] lista;
    lista = tempLista;
    ++numero_de_livros;
}

// Aritmética de ponteiros = Feito
void percorrer_vetor(biblioteca *lista, int numero_de_livros)
{
    for (int i = 0; i < numero_de_livros; i++)
    {
        cout << "Nome do livro: " << (lista + i)->nome_livro << endl;
        cout << "Autor do livro: " << (lista + i)->autor_livro << endl;
        cout << "Ano de lancamento do livro: " << (lista + i)->ano_lancamento_livro << endl;
        cout << "Estilo do livro: " << (lista + i)->estilo_livro << endl;
        cout << endl;
    }
}

int buscar_por_nome(biblioteca lista[], int numero_de_livros)
{
    string nome;
    bool encontrado = false;

    cout << "Digite o nome do livro que deseja buscar: ";
    getline(cin, nome);
    transform(nome.begin(), nome.end(), nome.begin(), ::toupper);


    for (int i = 0; i < numero_de_livros; i++)
    {
        if (lista[i].nome_livro == nome)
        {
            encontrado = true;
            cout << "Livro encontrado:" << endl;
            cout << "Nome: " << lista[i].nome_livro << endl;
            cout << "Autor: " << lista[i].autor_livro << endl;
            cout << "Ano de lancamento: " << lista[i].ano_lancamento_livro << endl;
            cout << "Estilo: " << lista[i].estilo_livro << endl;
        }
    }

    if (!encontrado)
    {
        cout << "Livro nao encontrado." << endl;
    }

    return 0;
}

int buscar_por_autor(biblioteca lista[], int numero_de_livros)
{
    string autor;
    bool encontrado = false;

    cout << "Digite o autor do livro que deseja buscar: ";
    getline(cin, autor);
    transform(autor.begin(), autor.end(), autor.begin(), ::toupper);

    for (int i = 0; i < numero_de_livros; i++)
    {
        if (lista[i].autor_livro == autor)
        {
            encontrado = true;
            cout << "Livro encontrado:" << endl;
            cout << "Nome: " << lista[i].nome_livro << endl;
            cout << "Autor: " << lista[i].autor_livro << endl;
            cout << "Ano de lancamento: " << lista[i].ano_lancamento_livro << endl;
            cout << "Estilo: " << lista[i].estilo_livro << endl;
        }
    }
    if (!encontrado)
    {
        cout << "Livro nao encontrado." << endl;
    }

    return 0;
}

int buscar_por_ano(biblioteca lista[], int numero_de_livros)
{
    int ano;
    bool encontrado = false;

    cout << "Digite o ano do livro que deseja buscar: ";
    cin >> ano;
    cin.ignore();

    for (int i = 0; i < numero_de_livros; i++)
    {
        if (lista[i].ano_lancamento_livro == ano)
        {
            encontrado = true;
            cout << "Livro encontrado:" << endl;
            cout << "Nome: " << lista[i].nome_livro << endl;
            cout << "Autor: " << lista[i].autor_livro << endl;
            cout << "Ano de lancamento: " << lista[i].ano_lancamento_livro << endl;
            cout << "Estilo: " << lista[i].estilo_livro << endl;
        }
    }
    if (!encontrado)
    {
        cout << "Livro nao encontrado." << endl;
    }

    return 0;
}

int buscar_por_estilo(biblioteca lista[], int numero_de_livros)
{
    string estilo;
    bool encontrado = false;

    cout << "Digite o estilo do livro que deseja buscar: ";
    getline(cin, estilo);
    transform(estilo.begin(), estilo.end(), estilo.begin(), ::toupper);

    for (int i = 0; i < numero_de_livros; i++)
    {
        if (lista[i].estilo_livro == estilo)
        {
            encontrado = true;
            cout << "Livro encontrado:" << endl;
            cout << "Nome: " << lista[i].nome_livro << endl;
            cout << "Autor: " << lista[i].autor_livro << endl;
            cout << "Ano de lancamento: " << lista[i].ano_lancamento_livro << endl;
            cout << "Estilo: " << lista[i].estilo_livro << endl;
        }
    }
    if (!encontrado)
    {
        cout << "Livro nao encontrado." << endl;
    }

    return 0;
}

// Ordenação + Recursão = Feito
void bubbleSort_ordenar_ano_livros(biblioteca *lista, int numero_de_livros)
{
    if (numero_de_livros > 1)
    {
        for (int i = 0; i < numero_de_livros - 1; i++)
        {
            if (lista[i].ano_lancamento_livro > lista[i + 1].ano_lancamento_livro)
            {
                biblioteca temp = lista[i];
                lista[i] = lista[i + 1];
                lista[i + 1] = temp;
            }
        }
        bubbleSort_ordenar_ano_livros(lista, numero_de_livros - 1);
    }
}

int ler_opcoes()
{
    int opcao;
    while (true)
    {
        cout << "Digite a sua opcao (1 a 5): ";
        if (cin >> opcao)
        {
            cin.ignore();
            if (opcao >= 1 && opcao <= 5)
            {
                return opcao;
            }
            else
            {
                cout << "Opcao invalida! Por favor, digite um numero entre 1 e 5." << endl;
            }
        }
        else
        {
            cout << "Entrada invalida! Por favor, digite um numero." << endl;
            cin.clear();
            cin.ignore();
        }
    }
}

int ler_opcao_busca()
{
    int opcao_busca;
    while (true)
    {
        cout << "Digite a sua opcao (1 a 5): ";
        if (cin >> opcao_busca)
        {
            cin.ignore();
            if (opcao_busca >= 1 && opcao_busca <= 5)
            {
                return opcao_busca;
            }
            else
            {
                cout << "Opcao invalida! Por favor, digite um numero entre 1 e 5." << endl;
            }
        }
        else
        {
            cout << "Entrada invalida! Por favor, digite um numero." << endl;
            cin.clear();
            cin.ignore();
        }
    }
}

void executar_opcao(int opcao, int opcao_busca)
{
    switch (opcao)
    {
    case 1:
        percorrer_vetor(lista, numero_de_livros);
        break;
    case 2:

        imprimir_busca();
        opcao_busca = ler_opcao_busca();
        system("cls");

        switch (opcao_busca)
        {
        case 1:
            cout << "Buscando livros pelo nome..." << endl;
            buscar_por_nome(lista, numero_de_livros);
            break;
        case 2:
            cout << "Buscando livros pelo autor..." << endl;
            buscar_por_autor(lista, numero_de_livros);
            break;
        case 3:
            cout << "Buscando livros pelo ano de lancamento..." << endl;
            buscar_por_ano(lista, numero_de_livros);
            break;
        case 4:
            cout << "Buscando livros pelo estilo..." << endl;
            buscar_por_estilo(lista, numero_de_livros);
            break;
        case 5:
            cout << "Saindo do programa..." << endl;
            exit(0);
        default:
            cout << "Opcao invalida. Por favor, digite um numero entre 1 e 5: ";
            break;
        }
        break;
    case 3:
        adicionar_livros();
        break;
    case 4:
        cout << "Ordenando o ano de lancamento dos livros de forma crescente..." << endl;
        bubbleSort_ordenar_ano_livros(lista, numero_de_livros);
        percorrer_vetor(lista, numero_de_livros);
        break;
    case 5:
        cout << "Saindo do programa..." << endl;
        exit(0);
    default:
        cout << "Opcao invalida. Por favor, digite um numero entre 1 e 5: ";
        break;
    }
}

void livros_preadicionados()
{
    lista = new biblioteca[6];

    lista[0].nome_livro = "O PEQUENO PRINCIPE";
    lista[0].autor_livro = "ANTOINE DE SAINT-EXUPERY";
    lista[0].ano_lancamento_livro = 1943;
    lista[0].estilo_livro = "FABULA";

    lista[1].nome_livro = "O LADRAO DE RAIOS";
    lista[1].autor_livro = "RICK RIORDAN";
    lista[1].ano_lancamento_livro = 2005;
    lista[1].estilo_livro = "FICCAO";

    lista[2].nome_livro = "DOM QUIXOTE";
    lista[2].autor_livro = "MIGUEL DE CERVANTES";
    lista[2].ano_lancamento_livro = 1625;
    lista[2].estilo_livro = "ROMANCE";

    lista[3].nome_livro = "A DIVINA COMEDIA";
    lista[3].autor_livro = "DANTE ALIGHIERI";
    lista[3].ano_lancamento_livro = 1314;
    lista[3].estilo_livro = "POESIA";

    lista[4].nome_livro = "POR LUGARES INCRIVEIS";
    lista[4].autor_livro = "JENNIFER NIVEN";
    lista[4].ano_lancamento_livro = 2015;
    lista[4].estilo_livro = "ROMANCE";

    lista[5].nome_livro = "JOGOS VORAZES";
    lista[5].autor_livro = "SUZANNE COLLINS";
    lista[5].ano_lancamento_livro = 2008;
    lista[5].estilo_livro = "FICCAO";

    numero_de_livros = 6;
}

int main()
{
    livros_preadicionados();

    do
    {
        imprimir_entrada_biblioteca();

        opcao = ler_opcoes();

        system("cls");

        executar_opcao(opcao, opcao_busca);

        cout << "Voce deseja fazer mais alguma coisa? S/N" << endl;
        cin >> desejo;
        system("cls");
        cin.ignore();
    } while (desejo == 'S' || desejo == 's');

    delete[] lista;

    return 0;
}
