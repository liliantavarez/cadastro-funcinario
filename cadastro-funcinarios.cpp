#include <iostream>

using namespace std;

struct funcionario
{
    int idade;
    int matricula;
    struct funcionario *prox, * ant;
};

void instanciarLista(funcionario * &listaFuncionarios)
{
    listaFuncionarios = NULL;
}

void inserirInicio(funcionario *&listaFuncionarios, int matricula, int idade)
{
    funcionario * novo = new funcionario;
    novo->matricula = matricula;
    novo->idade = idade;
    novo->prox = NULL;
    novo->ant = NULL;

    if (listaFuncionarios == NULL)
    {
        listaFuncionarios = novo;
    }
    else
    {
        novo->prox = listaFuncionarios;
        listaFuncionarios->ant = novo ;
        listaFuncionarios = novo;
    }
}

void inserirFinal(funcionario *&listaFuncionarios, int matricula, int idade)
{
    funcionario *novo = new funcionario;
    novo->idade = idade;
    novo->matricula = matricula;
    novo->prox = NULL;
    novo->ant = NULL;

    if (listaFuncionarios == NULL)
        listaFuncionarios = novo;
    else
    {
        funcionario *perc = listaFuncionarios;

        while (perc->prox != NULL)
        {
            perc = perc->prox;
        }
        perc->prox = novo;
        novo->ant = perc;
    }
}

void imprimirLista(funcionario *listaFuncionarios)
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
        novo->ant = NULL;

        if (posicao == 1){
            inserirInicio(listaFuncionarios,matricula,idade);
        } else if (posicao == tam+1){
            inserirFinal(listaFuncionarios,matricula,idade);
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

bool removerInicio (funcionario * &listaFuncionarios){
    if (listaFuncionarios == NULL){
        return false;
    }else{
        funcionario * aux = listaFuncionarios;
        listaFuncionarios = aux->prox;
        if (aux->prox!=NULL){
        listaFuncionarios->prox->ant = NULL; 
        }
        delete aux;
        aux=NULL;
        return true;
    }
}

bool removerFinal(funcionario *&listaFuncionarios){
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
                aux->ant = aux;
            }
            delete aux->prox;
            aux->prox = NULL;
        }
        return true;
    }
}

bool removerPos (funcionario * &listaFuncionaros, int posicao){
    funcionario * aux = listaFuncionaros;
    funcionario * anterior;
    int cont=1;
    while(cont != posicao && aux != NULL){
      anterior = aux;
      aux=aux->prox;
      cont++;
    }
    if(aux == NULL){
        return false;
    }
    else{
        if(aux == listaFuncionaros){
            listaFuncionaros=listaFuncionaros->prox;
            delete aux;
        }
        else if(aux->prox == NULL){
            delete aux;
            anterior->prox = NULL;
        }
        else{
            anterior->prox = aux->prox;
            delete aux;
        }
        return true;
    }
}

void matriculaPar (funcionario * listaFuncionarios){

   while (listaFuncionarios!=NULL){
   if (listaFuncionarios->matricula%2==0){
        cout << "Matricula:" << listaFuncionarios->matricula << endl;
        cout << "Idade:" << listaFuncionarios->idade << endl;
        cout << ("") << endl;
        listaFuncionarios = listaFuncionarios->prox;
   }else{
       listaFuncionarios = listaFuncionarios->prox;
   }
   }
}

int main(){
    funcionario * listaFunc;
    instanciarLista(listaFunc);

    int matricula,idade,posicao, opc,cont;

    do{
        cout << ("") << endl;   
        cout << ("-------------MENU------------")<< endl;
        cout << ("1.Inserir no inicio da lista")<< endl;
        cout << ("2.Inserir no final da lista")<< endl;
        cout << ("3.Imprimir a lista de funcionarios")<< endl;
        cout << ("4.Exibir a quantidade de funcionarios")<< endl;
        cout << ("5.Adicionar funcionario em uma determinada posicao da lista")<< endl;
        cout << ("6.Remover funcionario do inicio da lista") << endl;
        cout << ("7.Remover funcionario do final da lista") << endl;
        cout << ("8.Remover funcionario de uma determinada posicao da lista") << endl;
        cout << ("9.Imprimir funcionarios com matriculas pares") << endl;
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
            inserirInicio(listaFunc,matricula,idade);
            system("cls");
            cout << ("Funcionario cadastrado no INICIO da lista!")<< endl;
            break;
        case 2:
            cout << ("Matricula:");
            cin >> (matricula);
            cout << ("Idade:");
            cin >> (idade);
            inserirFinal(listaFunc,matricula,idade);
            system("cls");
            cout << ("Funcionario cadastrado no FINAL da lista!")<< endl;
            break;
        case 3:
            cout << ("Funcionarios Cadastrados") << endl;
            imprimirLista(listaFunc);
            break;
        case 4: 
            cout << "Quantidade de funcionarios cadastrados:"<< tamanho(listaFunc);
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
        case 6:
            removerInicio(listaFunc);
            cout << "Funcionario do INICIO da lista removido com sucesso!" << endl;
            break;
        case 7:
            removerFinal(listaFunc);
            cout << "Funcionario do FINAL da lista removido com sucesso!" << endl;    
            break;
        case 8: 
            cout << "POSICAO:";
            cin >> (posicao);
            removerPos(listaFunc,posicao);
            system("cls");
            cout << "Funcionario da posicao:"<<posicao<<" removido da lista" << endl;
        case 9: 
            cout << "Funcionarios com matriculas pares" << endl;
            matriculaPar(listaFunc);
            break;
        case 10:
        cout << "Fechando Sistema" << endl; 
        break;
        default:
            cout << "OPCAO INVALIDA"<< endl;
            break;
        }
    } while (opc != 6);
}