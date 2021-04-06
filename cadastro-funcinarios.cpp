#include <iostream>

using namespace std;

struct funcionario
{
    int idade;
    int matricula;
    funcionario *apont;
};

void instanciar_lista(funcionario *&novoFunc)
{
    novoFunc = NULL;
}

void inserir_inicio(funcionario *&novoFunc, int matricula, int idade)
{
    funcionario *novo = new funcionario;
    novo->matricula = matricula;
    novo->idade = idade;
    novo->apont = NULL;

    if (novoFunc == NULL)
    {
        novoFunc = novo;
    }
    else
    {
        novo->apont = novoFunc;
        novoFunc = novo;
    }
}

void inserir_final(funcionario *&novoFunc, int matricula, int idade)
{
    funcionario *novo = new funcionario;
    novo->idade = idade;
    novo->matricula = matricula;
    novo->apont = NULL;

    if (novoFunc == NULL)
        novoFunc = novo;
    else
    {
        funcionario *novoPont = novoFunc;

        while (novoPont->apont != NULL)
        {
            novoPont = novoPont->apont;
        }
        novoPont->apont = novo;
    }
}

void imprimir_lista(funcionario *novoFunc)
{
    while (novoFunc != NULL)
    {
        cout << "Matricula:" << novoFunc->matricula << endl;
        cout << "Idade:" << novoFunc->idade << endl;
        cout << ("") << endl;

        novoFunc = novoFunc->apont;
    }
}

void tamanho(funcionario *novoFunc)
{
    int tamanho=0;
    while (novoFunc != NULL){
        tamanho=tamanho+1;        
        novoFunc = novoFunc->apont;
    }
    cout << "Quantidade de funcinarios cadastrados:"<< tamanho << endl;
}

void inserir_na_posicao(funcionario *&novoFunc, int posicao, int matricula, int idade){

  
        funcionario *novo = new funcionario;
        novo->idade = idade;
        novo->matricula = matricula;
        novo->apont = NULL;
        if (posicao == 1)
        {
            novo->apont = novoFunc;
            novoFunc = novo;
        }
        else
        {
            funcionario *perc = novoFunc;
            funcionario *aux;
            int cont=0;
            while (cont != posicao)
            {
                aux = perc;
                perc = perc->apont;
                cont++;
            }
            novo->apont = perc;
            aux->apont = novo;
        }
}

int main()
{
    funcionario * listaFunc;
    instanciar_lista(listaFunc);

    int matricula,idade,posicao, opc,cont;

    do{
        cout << ("") << endl;   
        cout << ("-------------MENU------------")<< endl;
        cout << ("1.Inserir no inicio da lista.")<< endl;
        cout << ("2.Inserir no final da lista.")<< endl;
        cout << ("3.Imprimir a lista de funcionarios")<< endl;
        cout << ("4.Exibir a quantidade de funcionarios")<< endl;
        cout << ("5.Adicionar funcionario em uma determinada posicao da lista")<< endl;
        cout << ("6.SAIR") << endl;
        cout << ("OPERACAO: ");
        cin >> (opc);
        cout << ("") << endl;       
        system("cls");
        switch (opc)

        {
        case 1:
            cout << ("Matricula:");
            cin >> (matricula);
            cout << ("Idade:");
            cin >> (idade);
            inserir_inicio(listaFunc,matricula,idade);
            system("cls");
            cout << ("Funcionario cadastrado no INICIO da lista!")<< endl;
            break;
        case 2:
            cout << ("Matricula:");
            cin >> (matricula);
            cout << ("Idade:");
            cin >> (idade);
            inserir_final(listaFunc,matricula,idade);
            system("cls");
            cout << ("Funcionario cadastrado no FINAL da lista!")<< endl;
            break;
        case 3:
            cout << ("Funcionarios Cadastrados") << endl;
            cout << ("") << endl;
            imprimir_lista(listaFunc);
            break;
        case 4: 
            tamanho(listaFunc);
            break;
        case 5:
            cout << ("Posicao:");
            cin >>(posicao);
            cout << ("Matricula:");
            cin >> (matricula);
            cout << ("Idade:");
            cin >> (idade);
            system("cls");
            cout << "Funcionario cadastrado na posica "<<posicao<<" da lista" << endl;
            inserir_na_posicao(listaFunc,posicao,matricula,idade);
            break;
        case 6:
        cout << ("Fechando Sistema")<< endl;; 
        break;
        default:
            cout << ("OPCAO INVALIDA")<< endl;;
            break;
        }
    } while (opc != 6);
}