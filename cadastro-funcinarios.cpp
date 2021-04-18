#include <iostream>

using namespace std;

struct funcionario
{
    int idade;
    int matricula;
    funcionario *prox;
};

void instanciar_lista(funcionario *&listaFuncionarios)
{
    listaFuncionarios = NULL;
}

void inserir_inicio(funcionario *&listaFuncionarios, int matricula, int idade)
{
    funcionario *novo = new funcionario;
    novo->matricula = matricula;
    novo->idade = idade;
    novo->prox = NULL;

    if (listaFuncionarios == NULL)
    {
        listaFuncionarios = novo;
    }
    else
    {
        novo->prox = listaFuncionarios;
        listaFuncionarios = novo;
    }
}

void inserir_final(funcionario *&listaFuncionarios, int matricula, int idade)
{
    funcionario *novo = new funcionario;
    novo->idade = idade;
    novo->matricula = matricula;
    novo->prox = NULL;

    if (listaFuncionarios == NULL)
        listaFuncionarios = novo;
    else
    {
        funcionario *novoPont = listaFuncionarios;

        while (novoPont->prox != NULL)
        {
            novoPont = novoPont->prox;
        }
        novoPont->prox = novo;
    }
}

void imprimir_lista(funcionario *listaFuncionarios)
{
    while (listaFuncionarios != NULL)
    {
        cout << "Matricula:" << listaFuncionarios->matricula << endl;
        cout << "Idade:" << listaFuncionarios->idade << endl;
        cout << ("") << endl;

        listaFuncionarios = listaFuncionarios->prox;
    }
}

int tamanho ( funcionario *listaFuncionarios)
{
    int cont=0;
    while (listaFuncionarios != NULL)
    {
        cont++;
        listaFuncionarios = listaFuncionarios->prox;
    }
    return cont;
}

bool inserirPos (funcionario * &listaFuncionarios, int posicao, int matricula, int idade){
    int tam = tamanho(listaFuncionarios);
    if (posicao>tam+1){
        return false;
    }else{
        funcionario *novo = new funcionario;
        novo->idade = idade;
        novo->matricula = matricula;
        novo->prox = NULL;

        if (posicao == 1){
            inserir_inicio(listaFuncionarios,matricula,idade);
        } else if (posicao == tam+1){
            inserir_final(listaFuncionarios,matricula,idade);
        }else{
            funcionario * perc = listaFuncionarios;
            int cont = 1;
            while (cont != posicao-1)
            {
                perc = perc->prox;
                cont++;
            }
                novo->prox = perc->prox;
                perc->prox=novo;
        }
        return true;
    }
}

bool removerInicio (funcionario * &listaFuncionarios, int matricula, int idade){
    if (listaFuncionarios == NULL){
        return false;
    }else{
        funcionario * aux = listaFuncionarios;
        listaFuncionarios = listaFuncionarios->prox;
        delete aux;
        return true;
    }
}

bool removerFinal(funcionario *&listaFuncionarios, int matricula, int idade){
    if (listaFuncionarios == NULL){
        return false;
    }
    else{
        if (listaFuncionarios->prox == NULL){
            delete listaFuncionarios;
        }
        else{
            funcionario *aux = listaFuncionarios;
            while (aux->prox->prox != NULL){
                aux = aux->prox;
            }
            delete aux->prox;
            aux->prox = NULL;
        }
        return true;
    }
}



int main(){
    funcionario * listaFunc;
    instanciar_lista(listaFunc);

    int matricula,idade,posicao, opc,cont;

    do{
        cout << ("") << endl;   
        cout << ("-------------MENU------------")<< endl;
        cout << ("1.Inserir no inicio da lista")<< endl;
        cout << ("2.Inserir no final da lista")<< endl;
        cout << ("3.Imprimir a lista de funcionarios")<< endl;
        cout << ("4.Exibir a quantidade de funcionarios")<< endl;
        cout << ("5.Adicionar funcionario em uma determinada posicao da lista")<< endl;
        cout << ("6.Remover funcionário do início da lista") << endl;
        cout << ("7.Remover funcionário do final da lista") << endl;
        cout << ("8.Remover funcionário de uma determinada posição da lista") << endl;
        cout << ("9.Imprimir funcionários com matrículas pares") << endl;
        cout << ("10.SAIR") << endl;
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
            cout << ("Quantidade de funcionarios cadastrados:");
            cout << tamanho(listaFunc);
            break;
        case 5:
            cout << ("Posicao:");
            cin >>(posicao);
            cout << ("Matricula:");
            cin >> (matricula);
            cout << ("Idade:");
            cin >> (idade);
            system("cls");
            cout << "Funcionario cadastrado na posicao: "<<posicao<<" da lista" << endl;
            inserirPos(listaFunc,posicao,matricula,idade);
            break;
        case 10:
        cout << ("Fechando Sistema")<< endl;; 
        break;
        default:
            cout << ("OPCAO INVALIDA")<< endl;;
            break;
        }
    } while (opc != 6);
}